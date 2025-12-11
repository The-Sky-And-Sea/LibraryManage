#pragma once
#include <string>
#include <vector>
#include "book.h"

class reader
{
protected:
    // 读者姓名
    std::string name;
    // 读者借阅的书籍列表
    std::vector<book*> borrowed_books;
    
public:
    // 创建读者账号
    reader(const std::string& s);
    ~reader();
    // 获取读者姓名
    std::string get_name() const;
    // 借阅书籍
    bool borrow_book(book* b = nullptr);
    // 归还书籍
    bool return_book(book* b = nullptr);
    // 打印读者信息
    void print_info() const;
};

