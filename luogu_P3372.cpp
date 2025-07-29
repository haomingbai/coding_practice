/**
 * @file seg_tree.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-06-29
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cassert>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
concept Addable = requires(T a, T b) {
  { a + b } -> std::convertible_to<T>;
};

template <typename T>
concept Subtractable = requires(T a, T b) {
  { a - b } -> std::convertible_to<T>;
};

template <typename T>
concept Multiplyable = requires(T a, T b) {
  { a * b } -> std::convertible_to<T>;
};

template <typename T>
concept Dividable = requires(T a, T b) {
  { a / b } -> std::convertible_to<T>;
};

template <typename Container, typename E>
concept RandomAccessContainer =
    requires(const Container &c, std::size_t index) {
      // 要求有size()成员函数，返回类型可转换为size_t
      { c.size() } -> std::convertible_to<std::size_t>;

      // 要求支持随机访问（下标操作符）
      { c[index] } -> std::convertible_to<E>;
    };

template <typename T1, typename T2>
concept AddableWith = requires(T1 a, T2 b) {
  { a + b } -> std::convertible_to<std::common_type_t<T1, T2>>;
};

template <typename T1, typename T2>
concept SubtractableWith = requires(T1 a, T2 b) {
  { a - b } -> std::convertible_to<std::common_type_t<T1, T2>>;
};

template <typename T1, typename T2>
concept MultiplyableWith = requires(T1 a, T2 b) {
  { a * b } -> std::convertible_to<std::common_type_t<T1, T2>>;
};

template <typename T1, typename T2>
concept DividableWith = requires(T1 a, T2 b) {
  { a / b } -> std::convertible_to<std::common_type_t<T1, T2>>;
};

template <typename T>
concept Accumulateable = requires(T a, size_t b) {
  { a * b } -> std::convertible_to<T>;
};

template <typename T>
concept Partable = requires(T a, size_t b) {
  { a / b } -> std::convertible_to<T>;
};

template <typename T>
concept Negativable = requires(T a) {
  { -a } -> std::convertible_to<T>;
};

template <typename Container, typename E>
concept RandomStdContainer =
    RandomAccessContainer<Container, E> && requires(Container arr) {
      { arr.begin() };
      { arr.end() } -> std::same_as<decltype(arr.begin())>;
      { std::next(arr.begin()) } -> std::same_as<decltype(arr.begin())>;
      { std::prev(arr.end()) } -> std::same_as<decltype(arr.begin())>;
      { arr.begin() < arr.end() } -> std::convertible_to<bool>;
      { arr.empty() } -> std::convertible_to<bool>;
    };

/**
 *  线段树（Segment Tree）是一种二叉树结构，用于高效地执行区间查询与更新操作。
 *  每个节点管理数组的一个区间 [l,
 *  r]，叶节点对应单个元素，内部节点的值由左右子区间合并得出（如求和、最小值等）。
 *  构建时从根 [0, n–1]
 *  递归分割中点，将区间划分为左右两半，最终叶节点存元素值，内部节点存左右子节点的合并结果。
 *  查询时，对于目标区间 [L,
 * R]，若当前节点区间完全包含于目标区间，直接返回其值；
 *  若不相交则返回操作的“单位值”（如和为0、最小值为
 *  +∞），否则递归查询左右子并合并结果。 更新时，递归定位到包含目标索引 idx
 *  的叶节点，更新其值，然后回溯更新各祖先节点的合并值。 构建时间为
 *  O(n)，查询与更新时间均为 O(log n)。
 */
///
///                     [0..7] (sum)
///                      /       \
///             [0..3](sum)     [4..7](sum)
///             /     \           /     \
///         [0..1]   [2..3]   [4..5]   [6..7]
///         /   \     /   \     /   \     /   \
///       [0]  [1] [2]  [3]  [4]  [5]  [6]  [7]

/// 我们的线段树模板必须具备加法能力. 我们这里所有运算均用加法表示,
/// 如果是基本数据类型的其他运算, 如max, min等, 我们可以定义一个新的结构体,
/// 且这个结构体可以和这一基本类型隐式互转.
/// 例如我们可以定义:
/// struct SpecialInt {
///    int data;
///    SpecialInt operator+(SpecialInt b) const;
///    SpecialInt(int i): data(i) {}
///    operator int() const {return data;}
/// };
/// 通过这种方法, 我们就可以对任何一种基本的数据类型进行类似运算符重载的操作.
/// 在我们的模板中, 线段树进行的是求和运算,
/// 因为这种运算可以最好地展示出线段树的特征.

/// 如果线段树需要进行单点的更新, 那么最通俗的接口无疑是将某一点更新为某个值,
/// 如果是这样做, 我们就需要知道, 在这个点的位置, 这个节点到底更新了多少.
/// 因此, 在这样的接口下面, 我们需要知道加法运算的逆运算, 也就是求逆元的运算.
/// 所以`update`接口要求类型参数具有减法的性质.

/// 累加运算, 这是我选取加法的重要原因: 乘法需要用作累加器,
/// 但是我不希望看到太多重载. 在区间更新接口`updateDiff`部分,
/// 我们可以看到, 当我们不能给一个节点打上懒惰标签时,
/// 我们需要进行一种累加的运算, 即快速将运算重复`size_t n`次的运算.
/// 这种运算对于lazy_tag功能格外重要.

/// RandomAccessContainer作为容器类型, 拿来写泛型很有用

template <Addable DT>
class SimpleSegTree {
 protected:
  struct SegNode {
    DT val;
    DT lazy_tag;

    SegNode(const SegNode &) = default;
    SegNode(SegNode &&) = default;
    SegNode &operator=(const SegNode &) = default;
    SegNode &operator=(SegNode &&) = default;

    SegNode(const DT &val, const DT &tag) : val(val), lazy_tag(tag) {}
  };

  DT one;
  std::size_t size;
  std::vector<SegNode> data;

  template <RandomAccessContainer<DT> Container>
  void build(const Container &arr, size_t left_edge, size_t right_edge,
             size_t curr_idx) {
    assert(left_edge <= right_edge);

    if (left_edge == right_edge) {
      const size_t &pos = left_edge;
      data[curr_idx].val = arr[pos];
      return;
    }

    auto mid = (left_edge + right_edge) / 2;
    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    build(arr, left_edge, mid, left_idx);
    build(arr, mid + 1, right_edge, right_idx);

    data[curr_idx].val = data[left_idx].val + data[right_idx].val;
  }

  void pushDown(size_t curr_left, size_t curr_right, size_t curr_idx)
    requires Accumulateable<DT>
  {
    if (curr_left == curr_right) {
      data[curr_idx].val = data[curr_idx].val + data[curr_idx].lazy_tag;
      data[curr_idx].lazy_tag = one;
      return;
    }

    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    data[left_idx].lazy_tag = data[left_idx].lazy_tag + data[curr_idx].lazy_tag;
    data[right_idx].lazy_tag =
        data[right_idx].lazy_tag + data[curr_idx].lazy_tag;

    data[curr_idx].val = data[curr_idx].val +
                         data[curr_idx].lazy_tag * (curr_right - curr_left + 1);

    data[curr_idx].lazy_tag = this->one;
  }

  void updateDiff(size_t left_edge, size_t right_edge, const DT &diff,
                  size_t curr_left, size_t curr_right, size_t curr_idx)
    requires Accumulateable<DT>
  {
    if (diff == this->one) {
      return;
    }

    if (curr_right < left_edge || curr_left > right_edge) {
      return;
    }

    if (curr_left >= left_edge && curr_right <= right_edge) {
      data[curr_idx].lazy_tag = data[curr_idx].lazy_tag + diff;
      return;
    }

    auto overlap_length = [](size_t l1, size_t r1, size_t l2,
                             size_t r2) -> size_t {
      if (l2 > r1 || l1 > r2) {
        return 0;
      }

      std::pair<size_t, size_t> left_pair(l1, l2), right_pair(r1, r2);
      if (l2 < l1) {
        left_pair = std::pair<size_t, size_t>(l2, l1);
      }
      if (r2 < r1) {
        right_pair = std::pair<size_t, size_t>(r2, r1);
      }

      return (right_pair.first - left_pair.second) + 1;
    };

    auto curr_overlap =
        overlap_length(left_edge, right_edge, curr_left, curr_right);
    data[curr_idx].val = data[curr_idx].val + diff * curr_overlap;

    auto mid = (curr_left + curr_right) / 2;
    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    updateDiff(left_edge, right_edge, diff, curr_left, mid, left_idx);
    updateDiff(left_edge, right_edge, diff, mid + 1, curr_right, right_idx);
  }

  DT query(size_t left_edge, size_t right_edge, size_t curr_left,
           size_t curr_right, size_t curr_idx) {
    if (left_edge > curr_right || right_edge < curr_left) {
      return this->one;
    }

    if constexpr (Accumulateable<DT>) {
      if (data[curr_idx].lazy_tag != this->one) {
        pushDown(curr_left, curr_right, curr_idx);
      }
    }

    if (curr_left >= left_edge && curr_right <= right_edge) {
      return data[curr_idx].val;
    }

    auto mid = (curr_left + curr_right) / 2;
    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    return query(left_edge, right_edge, curr_left, mid, left_idx) +
           query(left_edge, right_edge, mid + 1, curr_right, right_idx);
  }

  void updateDiff(size_t pos, const DT &diff, size_t curr_left,
                  size_t curr_right, size_t curr_idx) {
    if (curr_left == curr_right) {
      data[curr_idx].val = data[curr_idx].val + diff;
      return;
    }

    data[curr_idx].val = data[curr_idx].val + diff;

    auto mid = (curr_left + curr_right) / 2;
    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    if (pos <= mid) {
      updateDiff(pos, diff, curr_left, mid, left_idx);
    }
    if (pos >= mid + 1) {
      updateDiff(pos, diff, mid + 1, curr_right, right_idx);
    }
  }

  void update(size_t pos, const DT &val, size_t curr_left, size_t curr_right,
              size_t curr_idx) {
    if (curr_left == curr_right) {
      data[curr_idx].val = val;
      return;
    }

    auto mid = (curr_left + curr_right) / 2;
    auto left_idx = curr_idx * 2, right_idx = curr_idx * 2 + 1;

    if (pos <= mid) {
      update(pos, val, curr_left, mid, left_idx);
    }
    if (pos >= mid + 1) {
      update(pos, val, mid + 1, curr_right, right_idx);
    }

    data[curr_idx].val = data[left_idx].val + data[right_idx].val;
  }

 public:
  template <RandomAccessContainer<DT> Container>
  SimpleSegTree(const Container &arr, const DT &one)
      : one(one),
        size(arr.size()),
        data(1 << (static_cast<size_t>(std::ceil(std::log2(arr.size()))) + 1),
             {one, one}) {
    build(arr, 0, arr.size() - 1, 1);
  }

  template <RandomAccessContainer<DT> Container>
    requires requires() {
      { DT() };
    }
  SimpleSegTree(const Container &arr) : SimpleSegTree(arr, DT{}) {}

  SimpleSegTree(size_t size, const DT &one)
      : one(one),
        size(size),
        data(1 << (static_cast<size_t>(std::ceil(std::log2(size))) + 1),
             {one, one}) {}

  SimpleSegTree(size_t size)
    requires requires() {
      { DT() };
    }
      : SimpleSegTree(size, DT{}) {}

  template <RandomAccessContainer<DT> Container>
  void build(const Container &arr) {
    this->size = (2 << static_cast<size_t>(std::ceil(std::log(size)))) * 2 + 1;
    data.resize(size, {one, one});
    build(arr, 0, arr.size() - 1, 1);
  }

  void update(size_t pos, const DT &val) { update(pos, val, 0, size - 1, 1); }

  void updateDiff(size_t left_edge, size_t right_edge, const DT &diff)
    requires Accumulateable<DT>
  {
    updateDiff(left_edge, right_edge, diff, 0, size - 1, 1);
  }

  void updateDiff(size_t pos, const DT &diff) {
    updateDiff(pos, diff, 0, size - 1, 1);
  }

  DT query(size_t left_edge, size_t right_edge) {
    return query(left_edge, right_edge, 0, size - 1, 1);
  }
};

int main() {
  size_t n, m;
  std::cin >> n >> m;

  std::vector<long long> v(n);
  for (auto &it : v) {
    std::cin >> it;
  }

  SimpleSegTree<long long> tree(v);

  for (size_t i = 0; i < m; i++) {
    int type;
    std::cin >> type;

    if (type == 1) {
      size_t l, r;
      long long k;
      std::cin >> l >> r >> k;
      l--, r--;
      tree.updateDiff(l, r, k);
    } else {
      size_t l, r;
      std::cin >> l >> r;
      l--, r--;
      auto res = tree.query(l, r);
      std::cout << res << std::endl;
    }
  }
}
