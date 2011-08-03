/*
 * IMMObject.h
 *
 *  Created on: Aug 3, 2011
 *      Author: ixi
 */

#ifndef IMMOBJECT_H_
#define IMMOBJECT_H_

#include <list>

namespace citybuilder {

class IMMObject {
private:
	static std::list<IMMObject *> liveObjects;
	static std::list<IMMObject *> deadObjects;
	long refCount;
protected:
	IMMObject();
	virtual ~IMMObject();
public:
	void AddRef();
	void Release();
	static void CollectGarbage();
	static void CollectRemainingObjects(bool bemitWarnings=false);
	virtual unsigned long size()=0;
};

} /* namespace citybuilder */
#endif /* IMMOBJECT_H_ */
