#include <iostream>
#include <coroutine>

std::generator simple_generator() {
    for (int i = 0; i < 5; ++i) {
        co_yield i; // 生成值
    }
}

int main() {
    for (int val : simple_generator()) {
        std::cout << val << std::endl;
    }
    return 0;
}
