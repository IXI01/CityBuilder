/*
 * CMMBlob.h
 *
 *  Created on: Aug 7, 2011
 *      Author: ixi
 */

#ifndef CMMBLOB_H_
#define CMMBLOB_H_

#include "IMMObject.h"
#include <cassert>

namespace citybuilder {

template <class T, int i>
class CMMBlob: public citybuilder::IMMObject {
protected:
	T buffer[i];
public:
	CMMBlob();
	virtual ~CMMBlob();

	inline T& operator [](int index) {
		assert (index < i && "Bad index on CMMBlob::[]");
		return buffer[index];
	}

	inline operator T*() {
		return buffer;
	}
	AUTO_SIZE;
};

} /* namespace citybuilder */
#endif /* CMMBLOB_H_ */
