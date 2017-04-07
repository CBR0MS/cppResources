#include <iostream>
using namespace std;

class LivingThing
{
public:
	LivingThing() {}
	LivingThing(int p)	{ legs = p; }
	int legs;
	virtual void move() { cout << "Some living thing is moving!\n"; };
};

class Human : public LivingThing
{
public:
	Human() 
		: LivingThing(2)
	{ }
	void move() { cout << "Human is walking!\n"; }
};

class Tiger : public LivingThing
{
public:
	Tiger()
		: LivingThing(4)
	{ }
	void move() { cout << "Tiger is prowling!\n"; }

};


int main()
{
	cout << "Part I. Static Bindings\n";
	cout << "=======================\n";
	LivingThing staticArr[4];
	staticArr[0] = Human();
	staticArr[1] = Human();
	staticArr[2] = Tiger();
	staticArr[3] = Human();

	for (int i = 0; i < 4; i++) {
		staticArr[i].move();
		cout << "This object has " << staticArr[i].legs << " legs\n";
	}

	cout << "\nPart II. Dynamic Bindings\n";
	cout << "=========================\n";

	LivingThing * dynamicArr[4];

	Human* h1 = new Human;
	Human* h2 = new Human;
	Tiger* t1 = new Tiger;
	Human* h3 = new Human;

	dynamicArr[0] = h1;
	dynamicArr[1] = h2;
	dynamicArr[2] = t1;
	dynamicArr[3] = h3;

	for (int i = 0; i < 4; i++) {
		dynamicArr[i]->move();
		cout << "This object has " << dynamicArr[i]->legs << " legs\n";
	}
	return 0;
}
