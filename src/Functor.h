/*
 * Functor.h
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */

#ifndef FUNCTOR_H_
#define FUNCTOR_H_

#include "IMMObject.h"

namespace citybuilder {

class Functor : public IMMObject {
public:
    virtual void operator()() = 0;
};

} /* namespace citybuilder */

#endif /* Functor_H_ */