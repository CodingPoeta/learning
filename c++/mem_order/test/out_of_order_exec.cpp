/*
        this program test CPU out of order execute.
        ENV: CPU need more than two core thread
        gcc -Wall -O3 out_of_order.c -o out_of_order -lpthread
*/

#include <iostream>
#include <thread>

static long a = 0, b = 0;
static long x = 0, y = 0;

#define mb()    __asm__ __volatile__("mfence":::"memory")
#define rmb()   __asm__ __volatile__("lfence":::"memory")
#define wmb()   __asm__ __volatile__("sfence":::"memory")
#define barrier() __asm__ __volatile__("": : :"memory")

void func1()
{
  a = 1;
  barrier();
  // mb();
  x = b;
}

void func2()
{
  b = 1;
  // barrier();
  // mb();
  y = a;
}

int main()
{
  for (int i = 0; i < 1e8; i++)
  {
    a = 0; b = 0;
    x = 0; y = 0;

    std::thread t1(func1);
    std::thread t2(func2);
    t1.join();
    t2.join();

    // we don't think, but ...
    if (x == 0 && y == 0){
      std::cout << "i = " << i << std::endl;
      break;
    }
  }
}
