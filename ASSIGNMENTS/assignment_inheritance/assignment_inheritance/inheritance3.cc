#include <iostream>

using namespace std;

class Base {
	public:
	virtual void print() {
		cout << "Base class\n";
	}
};

class Child : public Base {
	public:
	void print() override {
		cout << "Child class\n";
	}
};

class Grandchild : public Child {
	public:
	void print() override {
		cout << "Grandchild class\n";
	}
};

void print_class(Base& b) {
	b.print();
}

int main() {
	Base base;
	Child child;
	Grandchild grandchild;
	print_class(base);
	print_class(child);
	print_class(grandchild);
}