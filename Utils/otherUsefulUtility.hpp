//
// Created by 帆桥 on 2019/6/27.
//

#ifndef CLIONCODE_OTHERUSEFULUTILITY_HPP
#define CLIONCODE_OTHERUSEFULUTILITY_HPP

#include <string>
#include "Utils/Vector.hpp"
extern std::string GBKToUTF8(const char* strGBK);
extern Util::Vector<std::string> split(const std::string& str, const std::string& delim);
extern std::string UTF8ToGBK(const char* strUTF8);
#endif //CLIONCODE_OTHERUSEFULUTILITY_HPP
