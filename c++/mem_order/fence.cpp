// full fence：指定了memory_order_seq_cst或者memory_order_acq_rel。
// acquire fence：指定了memory_order_acquire。
// release fence：指定了memory_order_release。

#include <atomic>
#include <cassert>
#include <thread>

std::atomic<bool> x,y;
std::atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed); // ①
    std::atomic_thread_fence(std::memory_order_release);
    y.store(true, std::memory_order_relaxed); // ②
}

void read_y_then_x()
{
    while(!y.load(std::memory_order_relaxed)); // ③
    std::atomic_thread_fence(std::memory_order_acquire);
    if(x.load(std::memory_order_relaxed))
        ++z;  // ④
}

int main()
{
    x=false;
    y=false;
    z=0;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
    assert(z.load()!=0); // ⑥
}
