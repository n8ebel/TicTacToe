/*
 *  ObjectFactory.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <iostream>

namespace n8{
    
    /** \class ObjectFactory
     *  \brief Abstract base class for a game's object factory.
     *
     *  ObjectFactory acts as a base class for creating a game's object factory.  The object factory tracks available object ID's.
     */
class ObjectFactory{
public:
    static int m_nextId; /** < Static counter to get available id values for created entities **/
    
    ObjectFactory();
    virtual ~ObjectFactory() = 0;
    
    int GetNextId();
    
private:
};

}

#endif /* defined(OBJECT_FACTORY_H) */
