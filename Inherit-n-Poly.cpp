#include<iostream>
#include<vector>
using namespace std;
class Employee {
protected:
	string name;
	double salary;
public:
	Employee() { // Class for employee role.
		name = "";
		salary = 0;
	};
	Employee(string n, double s) { // Declaration will be : Employee("Name", Salary);
		name = n;
		salary = s;
	};
	void showInfo() { // Function to show info of specific role. Shows name and salary.
		cout <<"Info for " << name << ", Salary: " << salary << endl;
	}
	virtual void calculateBonus() { // Parameter will be bonus percentage.
		cout << "Bonus for Employee : \n"; 
	}
};

class Manager : public Employee { // Class for manager role.
public:
	Manager() { // Both manager and the other classes needs default constructor otherwise the compiler cries.
		name = "";
		salary = 0;
	}
	Manager(string n, double s) { // Constructor for manager role.
		name = n;
		salary = s;
	}
	void calculateBonus() override { // Overriddes original calculate bonus for the different bonus percentage.
		cout <<"Bonus for Manger : " << (salary *= 0.20) << '$' << endl; // Calculates and displays bonus for Manager role.
	}
};

class Developer : public Employee { // Class for developer role.
public:
	Developer(string n, double s) {
		name = n;
		salary = s;
	}
	void calculateBonus() override {
		cout << "Bonus for Developer : " << (salary *= 0.10) << '$' << endl; // Calculates and displays bonus for Developer role.
	}
};

class Intern : public Manager { // Class for intern role. Inherits manager class properties.
public:
	Intern() { 
		name = "";
		salary = 0;
	}
	Intern(string n, double s = 1000) {
		name = n;
		salary = s;
	}
	void calculateBonus() override { // Overridden function for no bonus necessary.
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
	cout << "\n___________________________________\nStep 3:\n ";
	vector<Employee*> employees = {new Manager("Manager person",3), new Developer ("Developer dude",4), new Intern("No one in particular")};
	for (int i = 0; i < employees.size(); i++) {
		employees[i]->showInfo(); // Shows info of each employee role.
		employees[i]->calculateBonus(); // Shows bonus of each employee role.
		cout << '\n';
	}
}
