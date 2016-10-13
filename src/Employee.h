/*
 * Employee.h
 *
 *  Created on: 2010-12-02
 *      Author: cdunphy
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Person.h"

namespace rcd {

class Employee: public rcd::Person {
public:
	Employee(const std::string& fname, const std::string& lname,
			std::size_t _age, std::string jtitle, std::string comp, double sal) :
		Person(fname, lname, _age), job_title(jtitle), company(comp), salary(sal) { }
	~Employee() { }

	const std::string& get_job_title() const { return job_title; }
	const std::string& get_company() const { return company; }
	double get_salary() const { return salary; }

	void change_job(const std::string& job_title, const std::string& company);

	void give_raise(double amount) { salary += amount; }

	const std::string to_str() const;

private:
	std::string job_title;
	std::string company;
	double salary;
};

}

#endif /* EMPLOYEE_H_ */
