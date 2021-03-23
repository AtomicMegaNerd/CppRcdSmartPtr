#ifndef __PERSON_H
#define __PERSON_H

#include <string>
#include <cstddef>
#include <ostream>

namespace rcd {

class Person {
	friend std::ostream& operator<<(std::ostream& out, const Person& p);
public:
	Person(const std::string& fname, const std::string& lname, std::size_t _age) :
		first_name(fname), last_name(lname), age(_age) { }
	virtual ~Person() { }

	const std::string& get_first_name() const { return first_name; }
	const std::string& get_last_name() const { return last_name; }
	const std::size_t get_age() const { return age; }
	void increment_age() { age++; }

	virtual const std::string to_str() const;

private:
	std::string first_name;
	std::string last_name;
	std::size_t age;
};

}

#endif /* __PERSON_H */
