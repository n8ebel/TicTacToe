/*
 * ID.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

    /** \class ID
     *  \brief Handles id abstraction 
     */
class ID{
public:
    ID() { m_id = -1; };
    ID(int newID) {m_id = newID;};
    
    int GetId() const {return m_id;};
    
    bool operator ==( const ID& other) const {
        return m_id == other.GetId();
    }
    
    bool operator <( const ID& other) const {
        return m_id < other.GetId();
    }
    
    bool operator >( const ID& other) const {
        return m_id > other.GetId();
    }
    
    
protected:
    
    
private:
    int m_id; /** < Actual id value **/
};





#endif