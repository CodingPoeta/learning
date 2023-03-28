class A {
public:
    A(int _i) : my_i(_i) {}
    int& my_i;
};

int main() {
    int i = 0;
    A a(i);
    a.my_i = 1;
    return 0;
}
