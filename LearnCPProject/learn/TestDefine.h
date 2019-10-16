//
// Created by 赵英坤 on 2019/10/16.
//

#ifndef LEARNCPPROJECT_LEARN_TESTDEFINE_H_
#define LEARNCPPROJECT_LEARN_TESTDEFINE_H_

#include <string>

namespace DefineNS {
class LogContent {
 public:
  std::string m_content;
  LogContent& operator<<(const char* content);
};

LogContent& stream(bool show, const std::string& pre);
std::string sshow(bool need_show, const char* val1, const char* val2);
}
#endif //LEARNCPPROJECT_LEARN_TESTDEFINE_H_
