#include <string>

std::string string_to_hex(const std::string& input);
std::string UTF8toANSI(const char* strUTF8);
std::string ws2s(const std::wstring &s);
std::wstring s2ws(const std::string &s);
int DetectUTF8toLocalPage(const char* strUTF8);