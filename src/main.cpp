/*
 * main.cpp
 *
 *  Created on: 2010-12-02
 *      Author: cdunphy
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "RcdSmartPtr.h"
#include "Person.h"
#include "Employee.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

using rcd::SmartPtr;
using rcd::Person;
using rcd::Employee;

typedef vector<SmartPtr<Person> >::const_iterator cp_iter;
typedef vector<SmartPtr<Person> >::iterator p_iter;

int main() {

	SmartPtr<Person> p1(new Employee("Chris", "Dunphy", 35, "Software Developer", "Shaw", 192000.00));
	SmartPtr<Person> p2(new Person("Lori-Ann", "Dunphy", 39));

	/* Cool baby name, hey? Notice the implicit fun here? */
	SmartPtr<Person> p3 = new Person("Brontus", "Dunphy", 1);

	// Add our people to a vector and iterate
	vector<SmartPtr<Person> > people;
	people.push_back(p1);
	people.push_back(p2);
	people.push_back(p3);
	for (cp_iter it = people.begin(); it != people.end(); ++it) {
		cout << (**it).to_str() << endl;
	}

	cout << endl;

	// Make a copy of the vector
	vector<SmartPtr<Person> > people2(people);
	for (p_iter it = people2.begin(); it != people2.end(); ++it) {
		cout << (**it) << endl;
	}

	return EXIT_SUCCESS;
}
