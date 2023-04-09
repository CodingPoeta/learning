#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <mutex>

using namespace std;

void hello(string name) {
  cout << "Hello " << name << " from new thread." << endl;
}

void print_time() {
  auto now = chrono::system_clock::now();
  auto in_time_t = chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
  cout << "now is: " << ss.str() << endl;
}

void sleep_thread() {
  this_thread::sleep_for(chrono::seconds(3));
  cout << "[thread-" << this_thread::get_id() << "] is waking up" << endl;
}

void loop_thread() {
  for (int i = 0; i < 10; i++) {
    cout << "[thread-" << this_thread::get_id() << "] print: " << i << endl;
  }
}

void init() {
  cout << "Initialing..." << endl;
  // Do something...
}

void once_worker(once_flag* flag) {
  call_once(*flag, init);
}

int main() {
  thread t1(hello, "World");
  t1.join();

  thread t2([] {
    cout << "Hello World from lambda thread." << endl;
  });
  t2.join();


  print_time();

  thread t3(sleep_thread);
  thread t4(loop_thread);

  t3.join();
  t4.detach();

  print_time();

  once_flag flag;
  thread t5(once_worker, &flag);
  thread t6(once_worker, &flag);

  t5.join();
  t6.join();

  return 0;
}