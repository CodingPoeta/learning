#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

string read_file(const string& filename) {
    if (filename == "badfile") {
        throw exception("badfile!");
    }
    ifstream ifs(filename);
    if (!ifs) {
        throw exception("File not found!");
    }
    string s;
    getline(ifs, s);
    return s;
}

void cat(const string& filename) {
    try {
        string s = read_file(filename);
        cout << s << endl;
    }
    catch (exception& e) {
        if (string(e.what()) == "File not found!") {
            cout << "cat(): " << e.what() << endl;
        }
        else {
            throw;
        }
    }
    catch (...) {
        cout << "Unknown exception!" << endl;
    }
}
    

int main()
{
    string s;
    try
    {
        cout << "Enter a string: ";
        cin >> s;
        cat(s);
        cout << "You entered " << s << endl;
    }
    catch (exception& e)
    {
        cout << "main(): " << e.what() << endl;
    }
    return 0;
}
