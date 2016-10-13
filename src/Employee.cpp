/*
 * Employee.cpp
 *
 *  Created on: 2010-12-02
 *      Author: cdunphy
 */

#include <iostream>
#include <sstream>

#include "Employee.h"

using std::string;
using std::flush;
using std::size_t;
using std::stringstream;
using std::ostream;

namespace rcd {

inline void Employee::change_job(const std::string& new_jtitle,
		const std::string& new_company) {
	job_title = new_jtitle;
	company = new_company;
}

inline const std::string Employee::to_str() const {
	stringstream to_str;
	to_str << Person::to_str() << ", Job Title: " << job_title << ", Company: "
			<< company << ", Salary: $" << salary << flush;
	return to_str.str();
}

}
