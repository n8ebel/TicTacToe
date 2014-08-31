#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
    /** \class Singleton
     *  \brief Template for singleton classes
     */
class Singleton{

public:
	static T* GetInstance(){
        if (!m_instance){
			m_instance = new T();
		}
        
		assert(m_instance);
		return m_instance;
	}
	
    static void Create(){
        if (!m_instance){
			m_instance = new T();
		}
    }
	
    static void Destroy(){
        if (m_instance) {
            delete m_instance;
        }
    }

protected:
	static T* m_instance;

};

template<class T> T* Singleton<T>::m_instance = 0;

#endif