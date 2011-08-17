/*
 * Singleton.h
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <cassert>

namespace citybuilder {
    
template<class T>
class Singleton {
private:
    static T* ms_singleton;
    
public:
    Singleton() {
        assert(!ms_singleton);
        ms_singleton = static_cast<T*>(this);
    }
    
    ~Singleton() {
        assert(ms_singleton);
        ms_singleton = 0;
    }
    
    static T& GetSingleton() {
        return *ms_singleton;
    }
    
    static T* GetSingletonPtr() {
        return ms_singleton;
    }

};   

template <class T> T* Singleton <T>::ms_singleton = 0;
    
} /* namespace citybuilder */


#endif /* SINGLETON_H_ */