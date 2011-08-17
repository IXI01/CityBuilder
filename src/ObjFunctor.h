/*
 * ObjectFunctor.h
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */

#ifndef OBJFUNCTOR_H_
#define OBJFUNCTOR_H_

#include "Functor.h"

namespace citybuilder {

template<class T>
class ObjFunctor : public Functor {
protected:
    T* obj;
    typedef void (T::*funcType)();
    funcType func;
public:
    AUTO_SIZE;
    
    ObjFunctor(T* o, funcType f) {
        obj = 0;
        func = f;
    }
    
    void operator() () {
        obj->*func();
    }
};

} /* namespace citybuilder */

#endif /* OBJFUNCTOR_H_ */