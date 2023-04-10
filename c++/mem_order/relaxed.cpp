// Memory order: relaxed
// 这是最轻量级的内存顺序模型，仅保证对于特定原子变量存在全局一致的修改顺序，除此以外不再有其他保证。
// （它没有任何保证，只是告诉编译器和CPU不要对该原子操作进行优化）
// - 尽管所有操作都是原子的，但是所有的事件不要求存在一个全局顺序
// - 同一个线程内部有happens-before规则，但是线程之间可能会看到不同的顺序

#include <atomic>
#include <cassert>
#include <thread>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed); // ①
    y.store(true, std::memory_order_relaxed); // ②
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_relaxed));// ③
    if (x.load(std::memory_order_relaxed)) // ④
        ++z;                               // ⑤
}

int main()
{
    for (int i = 0; i < 1e7; ++i)
    {
        x = false;
        y = false;
        z = 0;
        std::thread a(write_x_then_y);
        std::thread b(read_y_then_x);
        a.join();
        b.join();
        assert(z.load() != 0); // ⑥
    }
}
