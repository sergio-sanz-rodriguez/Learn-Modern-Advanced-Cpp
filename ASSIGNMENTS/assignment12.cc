#include <iostream>

using namespace std;

class Base {
private:
    int m_integer;
public:
    Base(int i) : m_integer{i} {}
    virtual void print() const {cout << "Base class with integer " << m_integer << endl; }
    int get_integer() const {return m_integer; }
};

class Child : public Base {
public:
    Child(int i) : Base(i) {};
    void print() const {cout << "Child class with integer " << get_integer() << endl; }
};

class Grandchild : public Child {
public:
    Grandchild(int i) : Child(i) {};
    void print() const {cout << "Grandchild class with integer " << get_integer() << endl; }
};

void print_class(const Base& b) {
    b.print();
}

int main() {
    Base base(5);
    Child child(6);
    Grandchild grandchild(7);

    print_class(base);
    print_class(child);
    print_class(grandchild);

    return 0;
};
