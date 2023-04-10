// Memory order: acq_rel
// An atomic operation A that performs a release operation on an atomic object M synchronized with an atomic operation B that performs an acquire operation on M and takes its value from any side effect in the release seqeunce headed by A.
// acq-rel 模型有如下保证：
  // 同一个对象上的原子操作不允许被乱序。
  // release操作禁止了所有在它之前的读写操作与在它之后的写操作乱序。
  // acquire操作禁止了所有在它之前的读操作与在它之后的读写操作乱序。
  

#include <atomic>
#include <cassert>
#include <thread>

std::atomic<bool> x,y;
std::atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed); // ①
    y.store(true, std::memory_order_release); // ②
}

void read_y_then_x()
{
    while(!y.load(std::memory_order_acquire)); // ③
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
    assert(z.load()!=0); // ⑤
}
