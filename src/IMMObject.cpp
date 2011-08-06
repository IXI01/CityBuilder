/*
 * IMMObject.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: ixi
 */

#include "IMMObject.h"

namespace citybuilder {

std::list<IMMObject *> IMMObject::liveObjects;
std::list<IMMObject *> IMMObject::deadObjects;

IMMObject::IMMObject() {
	liveObjects.push_back(this);

	// update the constructor to initialise refCount to zero
	refCount = 0;
}

IMMObject::~IMMObject() {

}

void IMMObject::AddRef() {
	++refCount;
}

void IMMObject::Release() {
	--refCount;
	if (refCount <= 0) {
		liveObjects.remove(this);
		deadObjects.push_back(this);
	}
}

void IMMObject::CollectGarbage() {
	for (std::list<IMMObject *>::iterator it = deadObjects.begin();
			it != deadObjects.end(); it++) {
		delete (*it);
	}
	deadObjects.clear();
}

void IMMObject::CollectRemainingObjects(bool bEmitWarnings) {
	CollectGarbage();
	for (std::list<IMMObject*>::iterator it = liveObjects.begin();
		it != liveObjects.end(); it++) {
		IMMObject *o = (*it);
		if (bEmitWarnings) {
			// log some kind of error message here
		}
		delete o;
	}
	liveObjects.clear();
}

} /* namespace citybuilder */
