/*
 * CLog.h
 *
 *  Created on: Aug 17, 2011
 *      Author: christian
 */


#ifndef CLOG_H_
#define CLOG_H_

#include <fstream>

//first, a few predefined constants
const int LOG_APP=1;
const int LOG_CLIENT=2;
const int LOG_SERVER=4;
//LOG_USER is used to display the log message to the
//user - i.e. in a dialog box
const int LOG_USER=8;

#define MAX_LOG_STRINGS 256


namespace citybuilder {

class CLog  
{
protected:
    CLog();
    std::ofstream appLog;
    std::ofstream clientLog;
    std::ofstream serverLog;
    std::string logStrings[MAX_LOG_STRINGS];
    bool LoadStrings();
   
public:
    static CLog &Get();
    bool Init();
    void Write(int target, const char *msg, ...);
    void Write(int target, unsigned long msgID, ...);
};

} /* namespace citybuilder */

#endif /* CLOG_H_ */