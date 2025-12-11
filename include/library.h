#pragma once
#include "book.h"
#include "reader.h"

class library
{
protected:
    // 图书馆名称
    std::string library_name;
    // 馆藏数目列表
    std::vector<book*> books;
    // 注册读者列表
    std::vector<reader*> readers;
public:
    library(std::string name);
    ~library();

    // 添加书籍到馆藏
    void add_book(book* b);
    // 添加注册读者
    void register_reader(reader* r);
    
    // 查找注册读者，避免重复注册和未注册借阅
    reader* find_reader(const std::string& reader_name) const;
    // 查找馆藏书籍，避免重复添加和借阅不存在的书籍
    book* find_book(const std::string& book_title) const;

    // 让读者借阅书籍
    bool borrowbook(const std::string& reader_name, const std::string& book_title);
    // 让读者归还书籍
    bool returnbook(const std::string& reader_name, const std::string& book_title);
    // 打印图书馆信息
    void print_info() const;
};
