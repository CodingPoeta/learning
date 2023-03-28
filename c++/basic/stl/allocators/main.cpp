#include <iostream>

int main(){
    int *p = std::allocator<int>().allocate(10, (int*)0);
    std::allocator<int>().deallocate(p, 10);
    return 0;
}