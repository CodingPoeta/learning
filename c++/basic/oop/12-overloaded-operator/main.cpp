#include <iostream>
#include <string>

using namespace std;

class MyString {
public:
    // 'explicit' keyword is used to prevent implicit conversion
    // explicit MyString(const char* str = NULL){
    MyString(const char* str = NULL){
        if (str == NULL) {
            m_data = new char[1];
            m_data[0] = '\0';
        } else {
            int len = strlen(str);
            m_data = new char[len + 1];
            strcpy(m_data, str);
        }
    }
    MyString(const MyString& other){
        int len = strlen(other.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, other.m_data);
    }
    ~MyString() {
        delete[] m_data;
    }
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] m_data;
        int len = strlen(other.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, other.m_data);
        return *this;
    }
    MyString operator+(const MyString& other) {
        int len = strlen(m_data) + strlen(other.m_data);
        char* newStr = new char[len + 1];
        strcpy(newStr, m_data);
        strcat(newStr, other.m_data);
        MyString ret(newStr);
        delete[] newStr;
        return ret;
    }
    bool operator==(const MyString& other) {
        return strcmp(m_data, other.m_data) == 0;
    }
    bool operator!=(const MyString& other) {
        return !this->operator==(other);
    }
    char& operator[](int index) {
        return m_data[index];
    }
    const char& operator[](int index) const {
        return m_data[index];
    }
    int length() const {
        return strlen(m_data);
    }
    const char* c_str() const {
        return m_data;
    }
private:
    char* m_data;
};

MyString operator+(const char* str, const MyString& other) {
    return MyString(str) + other;
}

// ambiguous
// MyString operator+(const MyString str, const char* str2) {
//     cout << "here" << endl;
//     return MyString(str) + MyString(str2);
// }

int main (){
    MyString str1("hello");
    MyString str2("world");
    MyString str3 = str1 + str2;
    cout << str3.c_str() << endl;
    str3 = str1 + "world";
    cout << str3.c_str() << endl;
    str3 = MyString("hello") + str2;
    cout << str3.c_str() << endl;
    str3 = "hello" + str2;
    cout << str3.c_str() << endl;
    str3 = "hello";
    cout << str3.c_str() << endl;
    str3[0] = 'H';
    cout << str3.c_str() << endl;
    str3[1] = 'E';
    cout << str3.c_str() << endl;
    return 0;
}

// Note: 
// +-*/%^&|~ 
// const T operatorX(const T& l, const T& r) const;
// ! && || < <= > >= == !=
// bool operatorX(const T& l, const T& r) const;
// []
// T& T::operator[](int index);
// prefix++, prefix--
// const Interger& operator++();
// postfix++, postfix--
// const Interger operator++(int);
// compiler will place a 0 as the parameter
