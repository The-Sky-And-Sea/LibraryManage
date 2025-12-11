#pragma once
#include <string>

class book
{
protected:
    // 书名
    std::string title;
    // 是否被借出
    bool is_borrowed = false;
public:
    book(std::string t, bool b = false);
    ~book();
    // 获取书名
    std::string get_title() const;
    // 检查书是否被借出
    bool check_borrowed() const;
    // 设置书的借出状态
    void set_borrowed(bool status);
    // 打印书的信息
    void print_info() const;
};

