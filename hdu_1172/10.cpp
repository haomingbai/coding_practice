/**
 * @file 10.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-18
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cassert>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <ostream>
#include <vector>

/// 主席树, 也就是可持久化线段树, 虽然失去了普通线段树懒加载懒更新的离线能力,
/// 但是获得了普通线段树所没有的进行版本查询的能力
/// 这种树使用了和之前朴素的线段树完全不一样的思路, 使用动态开点的方法实现.
/// 也就是说, 这种树的节点永远是按照需求创造的, 如果一个节点没有经过更新,
/// 那么这个节点就永远不会被创造.
/// 因此, 在实际的应用中, 动态开点的线段树总是被设置很大的一个固定尺寸,
/// 然后根据实际需求创建新节点.
template <typename T>
class PresidentTree {
 protected:
  /// 这是节点本身的数据, 因为一个节点所代表的范围可以通过计算得到,
  /// 而且这种数据在线段树的实际操作中必须被反复计算,
  /// 所以节点本身不存储它存放的数据的覆盖范围.
  struct Node {
    T val;  /// 节点的数据的值, 因为主席树是一种在线算法,
            /// 所以主席树的节点中不会包含"懒惰标签"
    size_t left_idx,
        right_idx;  /// 当前节点的左右孩子节点的指针
                    /// 因为动态开点的线段树,
                    /// 一个节点的子节点的下标永远是在运行的时候才知道,
                    /// 而不是通过什么东西计算出来,
                    /// 所以这个类似于指针的下标必须存在.
                    /// 这里使用了间接寻址的方式
                    /// (为什么我计算机组成只有77分 (╥﹏╥))
    /// 节点的构造函数
    /// 节点不应该存在无参数构造, 因为对于一颗线段树, 它的幺元永远只和类型有关,
    /// 且这个值应该是运行期的内容.
    /// 所以对象中存储的数据不能用于另一个类的无参构造.
    /// 如果没讲清楚, 忽略掉这段话.
    /// 这就是构造函数.
    Node(T val) : val(val), right_idx(0), left_idx(0) {}
  };

  const T one;                /// 幺元
  std::vector<Node> nodes;    /// 存储节点的动态数组, 初始的尺寸为1,
                              /// 因为我们在这里不使用下标为0的节点,
                              /// 而是用这个节点作为一个模板, 永远指向自己.
                              /// 就有点类似红黑树中常见的叶子节点.
  std::vector<size_t> roots;  /// 存储根节点下标的动态数组, 这里root[0]有效,
                              /// 需要注意. 因为这里roots的下标只代表版本.
  const size_t size;  /// 线段树的尺寸, 这里的尺寸代表的是维护的那个数组的尺寸.

  /// 这是一个纯内部的API, 这个接口的作用就是分配一个新的节点,
  /// 然后返回这个节点的下标. 因为对于线段树本身, 其实它只需要一个指针就可以,
  /// 实施上, 使用同样的思路, 我们以后可以用shared_ptr去替代下标,
  /// 这样线段树就变成树状数组了.
  /// 总之这个函数的思路就不解释了, 只要保证新节点被创造,
  /// 然后节点的下标被返回就可以.
  size_t assignNode(T val) {
    auto res = nodes.size();
    nodes.emplace_back(val);
    return res;
  }

  /// 使用幺元去初始化那个新节点.
  size_t assignNode() { return assignNode(one); }

  /// 建树的操作, 其实在动态开点的线段树中, 尤其是普通的动态开点
  /// (主席树不是普通的o_o) 中, 这样会让动态开点优势尽失,
  /// 所以用的很少, 但是反正都写了对吧.
  template <typename Container>
  void build(const Container &vec, size_t left_edge, size_t right_edge,
             size_t curr_idx) {
    /// 验证参数的有效性
    assert(left_edge <= right_edge);

    /// 获得当前节点的引用
    /// 这里因为我犯了一个错误, 所以只能这样写了, 这样写也有利于可读性
#define curr_node nodes[curr_idx]

    /// 如果左边界 == 右边界, 那么这个时候, 线段树的建立已经到了叶子节点.
    /// 这个时候, 我们应当写完元素的值就返回.
    if (left_edge == right_edge) {
      curr_node.val = vec[left_edge];
      return;
    }

    /// 获取中点准备二分
    auto mid = (left_edge + right_edge) / 2;
    /// 左右子树因为还没被建立, 所以位置都通过节点分配函数获取.
    auto left_idx = assignNode(), right_idx = assignNode();
    /// 获取节点的引用.
#define left_node nodes[left_idx]
#define right_node nodes[right_idx]

    /// 设置左右子树的指针, 其实这里按照道理, 下标就是朴素的线段树的样子.
    curr_node.left_idx = left_idx, curr_node.right_idx = right_idx;

    /// 给左右子树进行构造, 思路和朴素的线段树是一样的.
    build(vec, left_edge, mid, left_idx);
    build(vec, mid + 1, right_edge, right_idx);

    /// 当前的值等于左右子树的和.
    curr_node.val = left_node.val + right_node.val;
#undef left_node
#undef right_node
#undef curr_node
  }

  /// 更新节点, 增量更新
  /// 这是主席树的核心, 也就是不更新现有节点,
  /// 这也就是主席树可以存储历史版本的原因. 线段树其实就是一种单向的二叉树,
  /// 然后这里的原理就是: 如果儿子节点相同, 那么几个父亲可以指向一个相同的儿子.
  /// 就和你哥和你可以有一个相同的吃多了酱油的儿子一样 (喜当爹......).
  void updateDiff(T diff, size_t pos, size_t left_edge, size_t right_edge,
                  size_t old_idx, size_t curr_idx) {
    assert(left_edge > 0 && right_edge <= size);
    assert(left_edge <= right_edge);
    assert(pos >= left_edge && pos <= right_edge);

    /// 获得旧版的当前节点和新版的当前节点的引用.
    /// 这里一定要注意, 旧版本的一定要写成const,
    /// 因为我们一定不能不小心修改了旧版本.
    /// 这是编程的良好习惯, 常刷LeetCode的同学都知道,
    /// 当然常刷CF(无论是CodeForces还是CrossFire都一样)的同学的一般不知道......
#define curr_node nodes[curr_idx]
#define old_node nodes[old_idx]

    /// 因为有了单点的增量, 这里我们可以直接加.
    /// 如果存在元素 a: a -> a + x,
    /// 那么存在 a + b + ...: a + b + ... -> a + b + ... + x
    curr_node.val = old_node.val + diff;

    /// 如果左边界等与右边界, 那么已经更新到叶子了, 这就是递归退出的条件.
    /// 更新完叶子就退出.
    if (left_edge == right_edge) {
      assert(pos == left_edge);
      return;
    }

    /// 这个地方是我个人的创意, 如果新加上的值等与幺元,
    /// 那不就等于一切不变吗, 那这样的话就可以不用创建新节点了.
    /// 因为下面的所有区间的和与元素的值都是一样的.
    if (diff == one) {
      curr_node.left_idx = old_node.left_idx;
      curr_node.right_idx = old_node.right_idx;
      return;
    }

    /// 二分开始
    auto mid = (left_edge + right_edge) / 2;

    if (pos <= mid) {
      /// 待更新的点在左边

      /// 分配个新节点, 同时拿到旧节点的下标.
      auto new_child_idx = assignNode(), old_child_idx = old_node.left_idx;

      /// 新的节点的左孩子因为要被更新, 所以换成新分配的, 但是右孩子不变.
      curr_node.right_idx = old_node.right_idx;
      curr_node.left_idx = new_child_idx;  /// 新节点搞搞新意思.

      /// 更新左孩子.
      updateDiff(diff, pos, left_edge, mid, old_child_idx, new_child_idx);
    } else {
      /// 待更新的点在右边.
      /// 道理是一样的, 就是把左换成右, 毕竟左即是右, 右即是左嘛!
      auto new_child_idx = assignNode(), old_child_idx = old_node.right_idx;
      curr_node.left_idx = old_node.left_idx;
      curr_node.right_idx = new_child_idx;
      updateDiff(diff, pos, mid + 1, right_edge, old_child_idx, new_child_idx);
    }
#undef curr_node
#undef old_node
  }

  /// 单点更新, 只不过这次不带增量更新.
  void update(T val, size_t pos, size_t left_edge, size_t right_edge,
              size_t old_idx, size_t curr_idx) {
    /// assert是对自己的约束.
    assert(left_edge > 0 && right_edge <= size);
    assert(left_edge <= left_edge);
    assert(pos >= left_edge && pos <= right_edge);

    /// 获取新老节点, 还是一样的方式.
#define curr_node nodes[curr_idx]
#define old_node nodes[old_idx]

    /// 如果是更新叶子节点, 那么就直接赋值就可以.
    if (left_edge == right_edge) {
      assert(pos == left_edge);
      curr_node.val = val;
      return;
    }

    /// 二分查找.
    auto mid = (left_edge + right_edge) / 2;

    if (pos <= mid) {
      /// 如果左子树需要更新

      /// 获取新旧待更新子树的下标.
      auto new_child_idx = assignNode(), old_child_idx = old_node.left_idx;
      /// 获取他们的引用
#define new_child_node nodes[new_child_idx]
#define old_child_node nodes[old_child_idx]

      /// 还是更新当前节点的孩子指针.
      curr_node.right_idx = old_node.right_idx;
      curr_node.left_idx = new_child_idx;

      /// 更新子树之后我们才能更新当前的节点,
      /// 因为知道了新旧版本才知道差值, 知道差值才能给当前节点加上差值.
      update(val, pos, left_edge, mid, old_child_idx, new_child_idx);

      /// 获取差值
      /// 因为可持久化的存在,
      /// 我们这里就不需要在更新前备份旧版本的孩子节点的值了.
      /// 直接读取两个版本就好.
      auto diff = new_child_node.val - old_child_node.val;

      /// 给当前节点加上差值.
      curr_node.val = old_node.val + diff;

#undef new_child_node
#undef old_child_node
    } else {
      /// 如果右子树需要更新
      assert(pos > mid);  /// 还是提前验证一下条件

      /// 方法是一样的, 反正"色即是空, 空即是色, 色即是空即是空即是色".
      auto new_child_idx = assignNode(), old_child_idx = old_node.right_idx;
#define new_child_node nodes[new_child_idx]
#define old_child_node nodes[old_child_idx]
      curr_node.left_idx = old_node.left_idx;
      curr_node.right_idx = new_child_idx;
      update(val, pos, mid + 1, right_edge, old_child_idx, new_child_idx);
      auto diff = new_child_node.val - old_child_node.val;
      curr_node.val = old_node.val + diff;
#undef new_child_node
#undef old_child_node
    }
#undef curr_node
#undef old_node
  }

  /// 查询操作
  /// 这里target代表查询的目标, edge代表当前能管辖的边界
  T query(size_t left_target, size_t right_target, size_t left_edge,
          size_t right_edge, size_t curr_idx) {
    /// 获得当前节点的引用.
    const auto &curr_node = nodes[curr_idx];

    /// 如果引到0节点了, 那就直接返回幺元就可以了, 毕竟
    /// 0 + 0 + 0 + ... + 0 = 0
    if (curr_idx == 0) {
      return one;
    }

    /// 如果当前的管辖范围完全在目标内, 那么这个时候,
    /// 整个区间的和都是我们想要的. 就返回我们的父节点, 也就是当前节点就好了.
    if (left_edge >= left_target && right_edge <= right_target) {
      return curr_node.val;
    }

    /// 如果二者完全不相交, 我们就返回幺元就好了.
    /// 毕竟这里面完全没有我们需要的嘛.
    if (right_edge < left_target || left_edge > right_target) {
      /// 这里我不加断言是因为这个分支我真切用到了哈.
      return one;
    }

    /// 开始二分查找
    auto mid = (left_edge + right_edge) / 2;
    auto left_child_idx = curr_node.left_idx,
         right_child_idx = curr_node.right_idx;

    /// 结果就是对左边的查找和对右边的查找
    /// 这里可以看到为什么需要那个不相交的分支了.
    /// 目标区间不一定和左右的子区间都相交:
    /// 例如我在[1, 9]范围内查找[1, 2], 这个时候我就需要二分,
    /// 但是很明显, [1, 2]和[6, 9] 明显不相交嘛,
    /// 那我只能让[6, 9]被查找的时候函数退出递归避免死循环了.
    auto res =
        query(left_target, right_target, left_edge, mid, left_child_idx) +
        query(left_target, right_target, mid + 1, right_edge, right_child_idx);

    /// 返回结果.
    return res;
  }

 public:
  /// 构造函数
  template <typename Container>
  PresidentTree(const Container &vec, T one) : size(vec.size() - 1), one(one) {
    /// 先保留一点空间, 至少这次建树的保留出来, 再给一点冗余正好.
    nodes.reserve(size * 4);
    /// 创建0位置的模范节点.
    nodes.emplace_back(one);
    /// 创建第一个根节点.
    nodes.emplace_back(one);
    /// 从第一个根构造一个线段树
    build(vec, 1, size, 1);

    /// 加入根节点下标数组.
    roots.push_back(1);
  }

  /// 这个是最标准的构造, 只固定尺寸和幺元.
  PresidentTree(const size_t size, T one) : size(size), one(one) {
    /// 保留空间
    nodes.reserve(size * 4);
    /// 创造幺节点.
    nodes.emplace_back(one);
  }

  /// 增量更新.
  void updateDiff(T diff, size_t pos) {
    /// 创建新老节点下标
    size_t old_root_idx, new_root_idx;

    /// 新的根的下标肯定是新分配的.
    new_root_idx = assignNode();

    /// 新节点的下标, 如果上一个版本不存在就是0, 存在就是上一个版本的根的下标.
    if (roots.empty()) {
      old_root_idx = 0;
    } else {
      old_root_idx = roots.back();
    }

    /// 将新的根下标装入根下标数组中.
    roots.push_back(new_root_idx);

    /// 增量更新, 根节点的辖域是1到size这整个区间.
    updateDiff(diff, pos, 1, size, old_root_idx, new_root_idx);
  }

  /// 普通的单点更新需要满足减法存在, max运算的减法就不存在
  void update(T val, size_t pos)
  {
    /// 获取旧的根和新的根的下标
    size_t old_root_idx, new_root_idx;

    /// 分配新的根节点
    new_root_idx = assignNode();

    if (roots.empty()) {
      old_root_idx = 0;
    } else {
      old_root_idx = roots.back();
    }
    roots.push_back(new_root_idx);

    /// 更新
    update(val, pos, 1, size, old_root_idx, new_root_idx);
  }

  /// 查询
  T query(size_t time, size_t left_target, size_t right_target) {
    /// 这里`time`是第 time 个版本的线段树.
    return query(left_target, right_target, 1, size, roots[time]);
  }

  /// 获取版本的数量.
  size_t getVersionCount() { return roots.size(); }
};

class KthTree : public PresidentTree<size_t> {
  size_t KthElem(size_t k_remaining, size_t left_edge, size_t right_edge,
                 size_t curr_left_idx, size_t curr_right_idx) {
    if (left_edge == right_edge) {
      return left_edge;
    }

    auto mid = (left_edge + right_edge) / 2;

    /// 这里我懒得写了, 主要是变量太多, 不会命名.
    /// 意图讲解一下:
    /// 这里的意图就是分别获得当前节点的左孩子节点的前后版本的差值.
    /// 相信看了主席树的讲解一定能通过意图理解这里的思路.
    auto left_child_diff = nodes[nodes[curr_right_idx].left_idx].val -
                           nodes[nodes[curr_left_idx].left_idx].val;

    if (k_remaining <= left_child_diff) {
      return KthElem(k_remaining, left_edge, mid, nodes[curr_left_idx].left_idx,
                     nodes[curr_right_idx].left_idx);
    }

    else {
      return KthElem(k_remaining - left_child_diff, mid + 1, right_edge,
                     nodes[curr_left_idx].right_idx,
                     nodes[curr_right_idx].right_idx);
    }
  }

 public:
  size_t KthElem(size_t left, size_t right, size_t k) {
    return KthElem(k, 1, size, roots[left - 1], roots[right]);
  }

  KthTree(size_t max) : PresidentTree(max, 0) { roots.emplace_back(0); }

  void add(size_t elem) { updateDiff(1, elem); }
};

int main() {
  size_t T;
  std::cin >> T;

  while (T--) {
    size_t n;
    std::cin >> n;

    auto tree = KthTree(2001);

    for (size_t i = 0; i < n; i++) {
      int elem;
      std::cin >> elem;
      tree.add(elem);
    }

    long long res = 0;

    for (size_t i = 0; i < n; i++) {
      auto i_act = i + 1;
      for (size_t j = i; j < n; j++) {
        auto j_act = j + 1;
        if (((j - i) % 2) == 0) {
          auto delta = (j - i + 1);
          auto kth = (delta + 1) / 2;

          res += tree.KthElem(i_act, j_act, kth) * i_act * j_act;
        }
      }
    }

    std::cout << res << std::endl;
  }
}
