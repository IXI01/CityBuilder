/*
 * MMObjectFunctor.h
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */

#ifndef MMOBJFUNCTOR_H_
#define MMOBJFUNCTOR_H_


#include "Functor.h"
#include "CMMPointer.h"

namespace citybuilder {

template<class T>
class MMObjFunctor : public Functor {
protected:
    CMMPointer<T> obj;
    typedef void (T::*funcType)();
    funcType func;
public:
    AUTO_SIZE;
    
    MMObjFunctor(T* o, funcType f) {
        obj = 0;
        func = f;
    }
    
    void operator() () {
        obj->*func();
    }
};

} /* namespace citybuilder */


#endif /* MMOBJFUNCTOR_H_ */