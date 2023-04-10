// 默认内存顺序是顺序一致性，即std::memory_order_seq_cst
// 这是最严格的内存顺序模型，它有两个保证：1）程序指令与源码顺序一致；2）所有线程的所有操作存在一个全局的顺序
// 缺点是性能较差，因为为了保证顺序一致性，需要添加很多手段来对抗编译器和CPU的优化

#include <atomic>
#include <cassert>
#include <thread>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y()
{
  x.store(true); // ①
  y.store(true); // ②
}

void read_y_then_x()
{
  while (!y.load());// ③
  if (x.load()) // ④
    ++z;        // ⑤
}

int main()
{
  x = false;
  y = false;
  z = 0;
  std::thread a(write_x_then_y);
  std::thread b(read_y_then_x);
  a.join();
  b.join();
  assert(z.load() != 0);
}
