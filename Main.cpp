#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template<class ID, class Base, class ... Args> 
class Factory 
{
private:
	typedef Base* (*fInstantiator)(Args ...);
	template<class Derived> static Base* instantiator(Args ... args) 
	{
		return new Derived(args ...);
	}
	map<ID, fInstantiator> classes;
public:
	Factory() {}
	template<class Derived> void add(ID id) 
	{
		classes[id] = &instantiator<Derived>;
	}
	fInstantiator get(ID id) 
	{
		return classes[id];
	}
};

class Base
{
protected:
	int value;
public:
	Base(int val) : value(val) {}
	virtual void show() = 0;
};

class A : public Base
{
public:
	A(int val) : Base(val) {}
	void show() { cout << "class A: " << value << endl; }
};

class B : public Base
{
public:
	B(int val) : Base(val) {}
	void show() { cout << "class B: " << value << endl; }
};

class C : public Base
{
public:
	C(int val) : Base(val) {}
	void show() { cout << "class C: " << value << endl; }
};

vector<string> split(const string &s, char delim);

int main()
{
	string expression;
	vector<string> expressions;
	int N;
	cout << "N = ";
	cin >> N;
	Factory<int, Base, int> factory;
	vector<Base*> classes;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 1; i <= N; i++)
	{
		cout << i << '>';
		getline(cin, expression);
		expressions = split(expression, ' ');

		if (expressions.size() == 1 && expressions[0] == "showall")
		{
			for (auto it : classes)
				it->show();
		}
		else if (expressions.size() == 3 && expressions[0] == "create")
		{
			if (expressions[1] == "A")
				factory.add<A>(i);
			else if (expressions[1] == "B")
				factory.add<B>(i);
			else if (expressions[1] == "C")
				factory.add<C>(i);
			else
			{
				cout << "Incorrect operation\n"; i--; continue;
			}
			classes.push_back(factory.get(i)(stoi(expressions[2])));
		}
		else
		{
			cout << "Incorrect operation\n"; i--;
		}
	}

	system("pause");
	return 0;
}

vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}
