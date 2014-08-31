/*
 *  LogService.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>

#include "Singleton.h"

namespace n8{

/** Provides static logging functionality.  Could be extended to allow for runtime logging. */
class Log : public Singleton<Log>{
public:
    Log();
	virtual ~Log();
    
	static void Error(std::string tag,std::string msg);
	static void Info(std::string tag, std::string msg);
	static void Debug(std::string tag, std::string msg);
    
    static void TurnOnErrorMessages();
    static void TurnOffErrorMessages();
    
    static void TurnOnInfoMessages();
    static void TurnOffInfoMessages();
    
    static void TurnOnDebuggingMessages();
    static void TurnOffDebuggingMessages();
    
private:
    
    static bool ERROR;  /** < static boolean flag to control whether ERROR messages are displayed > */
    static bool INFO;  /** < static boolean flag to control whether INFO messages are displayed > */
    static bool DEBUGGING;  /** < static boolean flag to control whether DEBUGGING messages are displayed > */
};
    
}
#endif /* defined(LOG_SERVICE_H) */

