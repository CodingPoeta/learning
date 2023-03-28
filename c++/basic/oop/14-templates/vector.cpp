// Non-type template parameters
template <class T, int N>
class vector {
    T* data;
    int sz;
public:
    vector(int s = N) : sz(s) { data = new T[s]; }
    ~vector() { delete[] data; }
    int size() const { return sz; }
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

// Template and inheritance
