//
// Created by 赵英坤 on 2019/10/16.
//

#include "TestDefine.h"

namespace DefineNS {
LogContent log_content;
bool needShow = false;

void log(std::string need_show) {
    log(need_show.data());
}

void log(const char* show) {
    printf("%s", show);
}

LogContent& stream(bool show, const std::string& pre) {
    log_content.m_content.clear();
    log("\n");
    log(pre.data());
    needShow = show;
    return log_content;
}

LogContent& LogContent::operator<<(const char* content) {
    std::string s = content;
    this->m_content += s;
    if (needShow) log(content);
    return *this;
}

std::string sshow(bool need_show, const char* val1, const char* val2) {
    std::string p_pre;
    if (need_show) {
        std::string s1 = val1;
        std::string s2 = val2;
        p_pre = s1 + s2;
    }
    return p_pre;
}

}