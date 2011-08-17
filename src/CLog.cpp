/*
 * CLog.cpp
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */

#include <cstdarg>
#include "CLog.h"

namespace citybuilder {

CLog::CLog() {
   //the constructor doesn't do anything, but we need
   //it for our singleton to work correctly
}

CLog &CLog::Get() {
    static CLog log;
    return log;
}

bool CLog::Init() {
    appLog.open("applog.txt");
    clientLog.open("clntlog.txt");
    serverLog.open("srvrlog.txt");
    //user errors get logged to client

    //load the strings file
    if(!LoadStrings())return false;

    return true;
}

void CLog::Write(int target, const char *msg, ...) {
    va_list args; 
    va_start(args,msg);
    char szBuf[1024];
    vsprintf(szBuf,msg,args);
    
    if(target&LOG_APP) {
        appLog<<szBuf<<"\n";
#ifdef DEBUG
        appLog.flush();
#endif
    }
    if(target&LOG_CLIENT) {
        clientLog<<szBuf<<"\n";
#ifdef DEBUG
        clientLog.flush();
#endif
    }
    if(target&LOG_SERVER) {
        serverLog<<szBuf<<"\n";
#ifdef DEBUG
        serverLog.flush();
#endif
    }
    if(target&LOG_USER) {
#warning User-level logging is not yet implemented for this platform.
    }
}

void CLog::Write(int target, unsigned long msgID, ...) {
    va_list args; 
    va_start(args, msgID);
    char szBuf[1024];
    vsprintf(szBuf,logStrings[msgID].c_str(),args);
    Write(target,szBuf);
}


bool CLog::LoadStrings(){
    std::ifstream in("strings.txt");
    if(!in.is_open())return false;
    
    unsigned int index=0;

    while(!in.eof())
    {
        char szBuf[1024];
        in.getline(szBuf,1024);
        logStrings[index++]=szBuf;
    }

    return true;
} 
    
    
} /* namespace citybuilder */
