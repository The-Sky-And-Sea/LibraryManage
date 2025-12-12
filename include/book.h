#pragma once
#include <string>
#include <iostream>

class book
{
protected:
    // 书名
    std::string title;
    // 是否被借出
    bool is_borrowed = false;

public:
    book(std::string t);
    ~book();
    // 获取书名
    std::string get_title() const;
    // 检查书是否被借出
    bool check_borrowed() const;
    // 设置书的借出状态
    void set_borrowed(bool status);
    // 打印书的信息
    virtual void print_info() const = 0;
    // 获取书的类型
    virtual std::string get_type() const = 0;
};

// 实体书
class pyshical_book : public book{
protected:
    // 书架和编号
    std::string shelf;
    std::string number;
public:
    pyshical_book(std::string t, std::string s, std::string n);
    ~pyshical_book();
    // 获取书架
    std::string get_shelf() const;
    // 获取编号
    std::string get_number() const;
    // 获取书的类型
    std::string get_type() const { return "Physical"; }
    // 打印书的信息
    void print_info() const override;
};

class ebook : public book {
protected:
    // 网址链接
    std::string link;
    // 内存大小
    int size;
public:
    ebook(std::string t, std::string l, int s);
    ~ebook();
    // 获取书的类型
    std::string get_type() const { return "E-book"; }
    std::string get_link() const;
    int get_size() const;
    // 打印书的信息
    void print_info() const override;
};