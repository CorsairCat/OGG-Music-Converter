#ifndef _FORMAT_CONVERTER_H
#define _FORMAT_CONVERTER_H

#include <string>

std::string string_to_hex(const std::string& input);
std::string UTF8toANSI(const char* strUTF8);
std::string ANSItoUTF8(const char* strAnsi);
std::string ws2s(const std::wstring &s);
std::wstring s2ws(const std::string &s);
int DetectUTF8toLocalPage(const char* strUTF8);

#endif