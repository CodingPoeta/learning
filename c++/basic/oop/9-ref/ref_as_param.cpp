void f(int &x) {
    x = 10;
}

void g(const int &x) {
    // x = 10;
    // error: assignment of read-only reference 'x'
}

int main() {
    int a = 5;
    f(a);
    // f(a*3);
    // error: expects an lvalue for 1st argument

    g(a*3);
    // equals to:
    // const int &x = a*3;
    // g(x);

    return 0;
}