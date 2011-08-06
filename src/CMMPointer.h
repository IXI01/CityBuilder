/*
 * CMMPointer.h
 *
 *  Created on: Aug 7, 2011
 *      Author: ixi
 */

#ifndef CMMPOINTER_H_
#define CMMPOINTER_H_

#include <cassert>

namespace citybuilder {

template<class T>
class CMMPointer {
protected:
	T* obj;
public:
	// Constructors - basic
	CMMPointer() {
		obj = 0;
	}
	// Constructing with a pointer
	CMMPointer(T *o) {
		obj = 0;
		*this = o;
	}
	// Constructing with another smart pointer (copy constructor)
	CMMPointer(const CMMPointer<T> &p) {
		obj = 0;
		*this = p;
	}
	// Destructor
	virtual ~CMMPointer() {
		if (obj)
			obj->Release();
	}

	// Assignment operators - assigning a plain pointer
	inline void operator =(T *o) {
		if (obj)
			obj->Release();
		obj = o;
		if (obj)
			obj->AddRef();
	}

	// Assigning another smart pointer
	inline void operator =(const CMMPointer<T> &p) {
		if (obj)
			obj->Release();
		obj = p.obj;
		if (obj)
			obj->AddRef();
	}

	// Access as a reference
	inline T& operator *() const {
		assert (obj != 0 && "Tried to * on a NULL smart pointer");
		return *obj;
	}

	// Access as a pointer
	inline T* operator ->() const {
		assert (obj != 0 && "Tried to -> on a NULL smart pointer");
		return obj;
	}

	inline operator T*() const {
		return obj;
	}

	inline bool isValid() const {
		return (obj != 0);
	}

	inline bool operator !() {
		return !(obj);
	}

	inline bool operator ==(const CMMPointer<T> &p) const {
		return (obj == p.obj);
	}

	inline bool operator ==(const T* o) const {
		return (obj == o);
	}
};

} /* namespace citybuilder */
#endif /* CMMPOINTER_H_ */
