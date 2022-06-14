#include "include/cmdExecuteProxy.h"
#include "include/formatConvert.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 300

int ExecuteCmd(const char *cmd, std::list<std::string> &resultList)
{
    char buffer[BUFFER_SIZE];
    bool ret = false;
    FILE *pipe = _popen(cmd, "r"); //打开管道，并执行命令
    if (!pipe)
        return ret;

    bool isOk = false;
    while (!feof(pipe))
    {
        if (fgets(buffer, BUFFER_SIZE, pipe))
        {
            if (isOk == false || strcmp("\r\n", buffer) == 0) //去掉windows无用的空行
            {
                continue;
            }
            ret = true;
            resultList.push_back(std::string(buffer));
        }
    }
    _pclose(pipe); // 关闭管道
    return ret;
}

/*
std::string ExecuteCmd(std::string inputCmd)
{
    std::wstring inputCmd_w = s2ws(inputCmd);
    // 创建匿名管道,write->read;
    SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    HANDLE hRead, hWrite;
    if (!CreatePipe(&hRead, &hWrite, &sa, 0))
    {
        return ("FAIL");
    }
    // 设置命令行进程启动信息(以隐藏方式启动命令并定位其输出到hWrite
    STARTUPINFO si = {sizeof(STARTUPINFO)}; // Pointer to STARTUPINFO structure;
    GetStartupInfo(&si);
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    // si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE; //隐藏窗口；
    si.hStdError = hWrite;
    si.hStdError = hWrite;
    si.hStdOutput = hWrite; //管道的输入端口连接命令行的输出；
    // 启动命令行
    PROCESS_INFORMATION pi; // Pointer to PROCESS_INFORMATION structure;
    if (!CreateProcess(NULL,
                       (LPWSTR)inputCmd_w.c_str(),
                       NULL,
                       NULL,
                       TRUE,
                       // FALSE,          // Set handle inheritance to FALSE
                       NULL,
                       // 0,              // No creation flags
                       NULL,
                       NULL,
                       &si,
                       &pi))
    {
        // std::cout << "@ CreateProcess failed!" << std::endl;
        return ("FAIL");
    }
    CloseHandle(hWrite); //关闭管道的输入端口；
    // 读取命令行返回值
    std::string strRetTmp;
    char buff[1024] = {0};
    DWORD dwRead = 0;
    strRetTmp = buff;
    bool isOk = false;
    while (ReadFile(hRead, buff, 1024, &dwRead, NULL)) //从管道的输出端获取命令行写入的数据；
    {
        if (isOk == false || strcmp("\r\n", buff) == 0) //去掉windows无用的空行
        {
            continue;
        }
        strRetTmp += buff;
        break;
    }
    CloseHandle(hRead); //关闭管道的输出端口；
    return strRetTmp;
}
*/