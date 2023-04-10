#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif

#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

template<typename T>
T type_sum(const T *data, size_t size) {
    T sum{};
    for (size_t i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

int main()
{
  std::cout.imbue(std::locale("en_US.UTF-8"));
  std::cout << std::fixed << std::setprecision(1);
  auto eval = [](auto fun)
  {
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto [name, result] = fun();
    const auto t2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << std::setw(28) << std::left << name << "sum: "
              << result << "\t time: " << ms.count() << " ms\n";
  };
  {
    const std::vector<float> v(100'000'007, 0.1);

    eval([&v]
         { return std::pair{"std::accumulate (float)",
                            std::accumulate(v.cbegin(), v.cend(), 0.0)}; });
    eval([&v]
         { return std::pair{"std::reduce (seq, float)",
                            std::reduce(SEQ v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"std::reduce (par, float)",
                            std::reduce(PAR v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"type_sum(float)",
                            type_sum(v.data(), v.size())}; });
  }{
    const std::vector<double> v(100'000'007, 0.1);

    eval([&v]
         { return std::pair{"std::accumulate (double)",
                            std::accumulate(v.cbegin(), v.cend(), 0.0)}; });
    eval([&v]
         { return std::pair{"std::reduce (seq, double)",
                            std::reduce(SEQ v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"std::reduce (par, double)",
                            std::reduce(PAR v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"type_sum(double)",
                            type_sum(v.data(), v.size())}; });
  }{
    const std::vector<int> v(100'000'007, 1);

    eval([&v]
         { return std::pair{"std::accumulate (int)",
                            std::accumulate(v.cbegin(), v.cend(), 0)}; });
    eval([&v]
         { return std::pair{"std::reduce (seq, int)",
                            std::reduce(SEQ v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"std::reduce (par, int)",
                            std::reduce(PAR v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"type_sum(int)",
                            type_sum(v.data(), v.size())}; });
  }{
    const std::vector<long> v(100'000'007, 1);

    eval([&v]
         { return std::pair{"std::accumulate (long)",
                            std::accumulate(v.cbegin(), v.cend(), 0l)}; });
    eval([&v]
         { return std::pair{"std::reduce (seq, long)",
                            std::reduce(SEQ v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"std::reduce (par, long)",
                            std::reduce(PAR v.cbegin(), v.cend())}; });
    eval([&v]
         { return std::pair{"type_sum(long)",
                            type_sum(v.data(), v.size())}; });
  }
}
