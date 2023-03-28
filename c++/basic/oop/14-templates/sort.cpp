template <class T>
void sort( vector<T>& v ) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
};
