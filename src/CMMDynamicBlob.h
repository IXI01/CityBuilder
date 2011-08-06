/*
 * CMMDynamicBlob.h
 *
 *  Created on: Aug 7, 2011
 *      Author: ixi
 */

#ifndef CMMDYNAMICBLOB_H_
#define CMMDYNAMICBLOB_H_

#include "IMMObject.h"
#include <cassert>

namespace citybuilder {

template<class T>
class CMMDynamicBlob: public citybuilder::IMMObject {
protected:
	unsigned long dataSize;
	T *buffer;
public:
	CMMDynamicBlob(unsigned long size) {
		dataSize = size;
		buffer = new T[size];
		assert(buffer != 0 && "DynamicBlob buffer could not be created - out of memory?");
	}

	virtual ~CMMDynamicBlob() {
		if (buffer)
			delete[] buffer;
	}

	inline T& operator [](int index) {
		assert(index < dataSize && "Bad index on CMMDynamicBlob::[]");
		return buffer[index];
	}

	inline operator T*() {
		return buffer;
	}

	unsigned long size() {
		return dataSize + sizeof(this);
	}

	inline unsigned long blobSize() {
		return dataSize;
	}
};

} /* namespace citybuilder */
#endif /* CMMDYNAMICBLOB_H_ */
