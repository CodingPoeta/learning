#include <assert.h>
const int SIZE = 32;
double arr[SIZE];

double& subscript(int i) {
    assert(i >= 0 && i < SIZE);
    return arr[i];
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        subscript(i) = i;
    }
    double val = subscript(10);
    return 0;
}
