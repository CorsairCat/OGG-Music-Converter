#ifndef _CMD_EXECUTOR_H
#define _CMD_EXECUTOR_H

#include <string>
#include <list>

//std::string ExecuteCmd(std::string inputCmd);
int ExecuteCmd(const char *cmd, std::list<std::string> &resultList);

#endif