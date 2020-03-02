#include <iostream>

using namespace std;

__declspec(dllexport) void fun() {
    cout << "fun() called from a dynamic library" << endl;
}