#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>

using namespace std;

static const int MAX = 10e8;
static double sum = 0;
static mutex exclusive_sum;

void worker_with_mutex(int min, int max) {
  for (int i = min; i <= max; i++) {
    exclusive_sum.lock();
    sum += sqrt(i);
    exclusive_sum.unlock();
  }
}

void serial_task(int min, int max, void (*worker) (int, int) ) {
  auto start_time = chrono::steady_clock::now();
  sum = 0;
  worker(min, max);
  auto end_time = chrono::steady_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Serail task finish, " << ms << " ms consumed, Result: " << sum << endl;
}

void concurrent_worker(int min, int max) {
  double tmp_sum = 0;
  for (int i = min; i <= max; i++) {
    tmp_sum += sqrt(i);
  }
  exclusive_sum.lock();
  sum += tmp_sum;
  exclusive_sum.unlock();
}

void concurrent_task(int min, int max, void (*worker) (int, int) ) {
  auto start_time = chrono::steady_clock::now();

  unsigned concurrent_count = thread::hardware_concurrency();
  cout << "hardware_concurrency: " << concurrent_count << endl;
  vector<thread> threads;
  sum = 0;
  int step = (max-min) / concurrent_count;
  for (int t = 0; t < concurrent_count; t++) {
    if (t == concurrent_count - 1) {
      step = max - min + 1;
    }
    threads.push_back(thread(worker, min, min + step - 1));
    min = min + step;
  }
  for (auto& t : threads) {
    t.join();
  }

  auto end_time = chrono::steady_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << sum << endl;
}

int main() {
  serial_task(0, 1e8, concurrent_worker);
  serial_task(0, 1e8, worker_with_mutex);
  concurrent_task(0, 1e8, concurrent_worker);
  concurrent_task(0, 1e8, worker_with_mutex);
  return 0;
}