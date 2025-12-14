#include <iostream>

using namespace std;

class Base {
	int i;
	public:
	Base(int i) : i(i) {}
	virtual void print() {
		cout << "Base class: i = " << i << endl;
	}
};

class Child : public Base {
	public:
	Child(int i) : Base(i) {}
	void print() {
		cout << "Child class\n";
	}
};

class Grandchild : public Child {
	public:
	Grandchild(int i) : Child(i) {}
	void print() {
		cout << "Grandchild class\n";
	}
};

void print_class(Base& b) {
	b.print();
}

int main() {
	Base base(1);
	Child child(2);
	Grandchild grandchild(3);
	print_class(base);
	print_class(child);
	print_class(grandchild);
}