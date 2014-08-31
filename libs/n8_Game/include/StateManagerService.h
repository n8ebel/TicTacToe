/*
 * StateManagerService.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */

#ifndef STATE_MANAGER_SERVICE_H
#define STATE_MANAGER_SERVICE_H

#include <map>
#include <vector>

#include "SDL2/SDL.h"
#include "ID.h"
#include "Service.h"
#include "State.h"
#include "Window.h"

#include "PushStateCommand.h"
#include "PopStateCommand.h"


namespace n8{
    
/**
 *  State_Manager handles the state stack and holds pointers
 *    to each registered game state.
 *
 *  The singleton pattern is used so there is a single
 *    state stack and access point to state information.
 */
class StateManagerService : public Service{

public:
    StateManagerService();
    ~StateManagerService();
    
    
    bool RegisterState(int identifier, State* state);
    
    bool PushState(int identifier);
    void PopState();
    void Clear();
    
    int GetStackSize();
    ID GetCurrentStateId();
    
    void ProcessState(Uint32 time, Window* screen);
    
    void OnNotify(Event*);
    
private:
    
    
    map<int, State*> m_registeredStates; /** < map of identifiers and game state objects */
    vector<State*> m_stateStack; /** < stack of state objects */
    
};

}

#endif
