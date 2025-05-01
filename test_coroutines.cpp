#include <coroutine>
#include <iostream>

using namespace std;

template <typename T> class MyCoroutine
{
  public:
    // 协程开始时，在协程的状态对象分配内存后，调用promise_type的构造函数
    struct promise_type
    {
        T value;
        // 为协程的状态对象分配内存失败时
        static auto get_return_object_on_allocation_failure()
        {
            return MyCoroutine{nullptr};
        }

        // 构造成功后开始执行
        auto get_return_object()
        {
            return MyCoroutine{handle::from_promise(*this)};
        }
        // 在以上函数后执行
        auto initial_suspend()
        {
            return std::suspend_always{};
        }
        // 协程结束前执行
        auto final_suspend() noexcept
        {
            return std::suspend_always{};
        }
        // 出现未经处理的异常时执行
        void unhandled_exception()
        {
            return std::terminate();
        }
        // co_return 时执行，return_void跟return_value二选一
        void return_void()
        {
        }
        // int return_value(int result) { this.result = reslut; }

        // co_yield时执行
        auto yield_value(T value)
        {
            this->value = value;
            return std::suspend_always{};
        }
    };
    using handle = std::coroutine_handle<promise_type>;

  private:
    handle hCoroutine;
    MyCoroutine(handle handle) : hCoroutine(handle)
    {
    }

  public:
    // int result;
    MyCoroutine(MyCoroutine &&other) noexcept : hCoroutine(other.hCoroutine)
    {
        other.hCoroutine = nullptr;
    }
    ~MyCoroutine()
    {
        if (hCoroutine)
            hCoroutine.destroy();
    }
    bool MoveNext() const
    {
        return hCoroutine && (hCoroutine.resume(), !hCoroutine.done());
    }
    T GetValue() const
    {
        return hCoroutine.promise().value;
    }
};

MyCoroutine<int> task()
{
    int a = 0, b = 1;
    while (a <= 10)
    {
        co_yield a;
        a++;
    }
};

int main()
{
    MyCoroutine<int> fun = task();
    while (fun.MoveNext())
    {
        cout << fun.GetValue() << endl;
        // getchar();
    }
}