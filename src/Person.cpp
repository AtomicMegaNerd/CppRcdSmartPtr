#include <iostream>
#include <sstream>

#include "Person.h"

using std::string;
using std::flush;
using std::size_t;
using std::stringstream;
using std::ostream;

namespace rcd {

/*
 * The nice part about this operator is that it will work
 * on base classes as well, because we are calling the
 * virtual to_str() method.
 */
ostream& operator<<(ostream& out, const Person& p) {
	return out << p.to_str();
}

inline const std::string Person::to_str() const {
	stringstream to_str;
	to_str << "First Name: " << first_name << ", Last Name: " << last_name
			<< ", Age: " << age << flush;
	return to_str.str();
}

}

