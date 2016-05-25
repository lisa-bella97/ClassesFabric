#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

class Base
{
private:
    int value;
public:
    Base() : value(0) {}
    Base(int val) : value(val) {}
    virtual void show() = 0;
    int get() { return value; }

};

class A : public Base
{
public:
    A(): Base() {}
    A(int val): Base(val) {}
    void show()
    {
        cout << "class A: " << get() << endl;
    }
};
class B : public Base
{
public:
    B(): Base() {}
    B(int val): Base(val) {}
    void show()
    {
        cout << "class B: " << get() << endl;
    }
};
class C : public Base
{
public:
    C(): Base() {}
    C(int val): Base(val) {}
    void show()
    {
        cout << "class C: " << get() << endl;
    }
};

int main() {

    map<string, function<void()>> strfunc;
    //strfunc["create"] =

    cout << "Hello, World!" << endl;
    return 0;
}
