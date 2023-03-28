#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
    // Create a vector containing integers
    std::vector<int, std::allocator<int>> v = {7, 5, 16, 8};

    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);

    // Print out the vector
    std::cout << "v = { ";
    for (int n : v)
        std::cout << n << ", ";
    std::cout << "}; \n";

    std::cout << std::count_if(v.begin(), v.end(),
                               [](int i)
                               { return i % 2 == 0; })
              << " even numbers in v" << std::endl;

    std::cout << std::count_if(v.begin(), v.end(),
                               std::not_fn(std::bind(std::modulus<int>(), std::placeholders::_1, 2)))
                            //    std::not1(std::bind2nd(std::modulus<int>(), 2)))
                << " odd numbers in v" << std::endl;

    std::sort(v.begin(), v.end(), std::greater<int>());
    for (auto iter = v.begin(); iter != v.end(); ++iter)
        std::cout << *iter << " ";

    auto iter = std::find_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
    if (iter != v.end())
        std::cout << "\nFirst even number in v is " << *iter << std::endl;
        
    return 0;
}