// Builtin type conversions
// 1. Primitive
// char => short => int => float => double, int => long => long long
// 2. Implicit conversions
// T => T&, T& => T, T* => void*, T[] => T*, T* => T[], T => const T
// 3. Explicit conversions T => C
// 3.1 if C(T) is a valid constructor call for C
// 3.2 if operator C() is defined for T

class Orange;

class Apple {
public:
    operator Orange() const;
};

class Orange {
public:
    explicit Orange(Apple);
};

void f(Orange);

int main (){
    Apple a;
    f(a); // error: ambiguous conversion from Apple to Orange, need explicit conversion
    return 0;
}