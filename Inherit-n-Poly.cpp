#include<iostream>
using namespace std;
class Employee {
protected:
	string name;
	double salary;
public:
	Employee() {
		name = "";
		salary = 0;
	};
	Employee(string n, double s) { // Declaration will be : Employee("Name", Salary);
		name = n;
		salary = s;
	};
	void showInfo() {
		cout << name << ' ' << salary << endl;
	}
	virtual void calculateBonus() { // Parameter will be bonus percentage.
		cout << "Bonus for Employee : \n";
	}
};

class Manager : public Employee {
public:
	Manager(string n, double s) {
		name = n;
		salary = s;
	}
	void calculateBonus() override {
		cout <<"Bonus for Manger : " << (salary *= 0.20) << '$' << endl; // Calculates and displays bonus for Manager role.
	}
};

class Developer : public Employee {
public:
	Developer(string n, double s) {
		name = n;
		salary = s;
	}
	void calculateBonus() override {
		cout << "Bonus for Developer : " << (salary *= 0.10) << '$' << endl; // Calculates and displays bonus for Developer role.
	}
};

class Intern : public Manager {
	Intern(string n, double s = 1000) {
		name = n;
		salary = s;
	}
	void calculateBonus() override {
		cout << "Hah, intern has no bonus.";
	}

};

int main() {
	// Testing the differences between both classes: 
	Manager m1("John", 200000); // Initializes both manager 1
	Developer d1("Kachunk", 150000); // and developer 1 respectively.

	m1.calculateBonus(); // Calculates bonus for each role.
	d1.calculateBonus();
	// Polymorphism or whatever: 
	Employee* nptr = new Manager("bunk",1); // New pointer for pointing and stuff. Points to manager.
	nptr->calculateBonus(); // Calculates bonus for new blank manager object.
	nptr = new Developer("clunk", 2); // Points new pointer to developer object.
	nptr->calculateBonus(); // Calculates bonus for new blank bonus object.

	// Bonus
	Employee* array

}
