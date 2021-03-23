/*
 * RcdSmartPtr.h
 *
 *  Created on: 2010-12-02
 *      Author: cdunphy
 */

#ifndef RCDSMARTPTR_H_
#define RCDSMARTPTR_H_

#include <cstddef>
#include <stdexcept>

namespace rcd {

/**
 * This is a generic reference counting smart pointer
 * template.  Note that this class will NOT work properly
 * with arrays.
 */
template<typename T> class SmartPtr {
public:
	SmartPtr(T* _data = 0) : data(_data), num_refs(new std::size_t(1)) { }
	SmartPtr(const SmartPtr<T>& other) :
		data(other.data), num_refs(other.num_refs) {
		*num_refs++;
	}
	SmartPtr<T>& operator=(const SmartPtr<T>& rhs);
	~SmartPtr() { decr_ref(); }

	const T& operator*() const;
	T& operator*();
	const T* operator->() const;
	T* operator->();

private:
	void decr_ref() { if (--num_refs == 0) { delete data; delete num_refs; } }
	T* data;
	std::size_t* num_refs;
};

template<typename T> inline SmartPtr<T>& SmartPtr<T>::operator=(
		const SmartPtr<T>& rhs) {
	++*rhs.num_refs;
	decr_ref();
	data = rhs.data;
	num_refs = rhs.num_refs;
	return *this;
}

template<typename T> inline const T& SmartPtr<T>::operator*() const {
	if (data)
		return *data;
	throw std::runtime_error("Cannot de-reference an unbound SmartPtr");
}

template<typename T> inline T& SmartPtr<T>::operator*() {
	// Call const-version and then cast away const-ness
	return const_cast<T&> (static_cast<const SmartPtr<T>&> (*this).operator*());
}

template<typename T> inline const T* SmartPtr<T>::operator->() const {
	if (data)
		return data;
	throw std::runtime_error("Cannot access an unbound SmartPtr");
}

template<typename T> inline T* SmartPtr<T>::operator->() {
	// Call const-version and then cast away const-ness
	return const_cast<T*> (static_cast<const SmartPtr<T>&> (*this).operator->());
}

}

#endif /* RCDSMARTPTR_H_ */
