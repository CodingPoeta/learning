#include <iostream>
#include <deque>
 
int main()
{
    // Create a deque containing integers
    std::deque<int> d = {7, 5, 16, 8};
 
    // Add an integer to the beginning and end of the deque
    d.push_front(13);
    d.push_back(25);
 
    // Iterate and print values of deque
    for(int n : d)
        std::cout << n << ' ';
}

// an indexed sequence container that allows fast insertion and deletion at both its beginning and its end
// not stored contiguously: typical implementations use a sequence of individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences, compared to vector's indexed access which performs only one.

// The complexity (efficiency) of common operations on deques is as follows:
// Random access - constant O(1)
// Insertion or removal of elements at the end or beginning - constant O(1)
// Insertion or removal of elements - linear O(n)