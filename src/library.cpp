#include "library.h"
#include <iostream>

library::library(std::string name) : library_name(name) {}

library::~library() {}

void library::add_book(book* b) {
    if (b && !find_book(b->get_title())) {
        books.push_back(b);
    }
}

void library::register_reader(reader* r) {
    if (r && !find_reader(r->get_name())) {
        readers.push_back(r);
    }
}

reader* library::find_reader(const std::string& reader_name) const {
    // 查找注册读者，如果有返回对应指针，否则返回nullptr
    for (auto& r : readers) {
        if (r->get_name() == reader_name) {
            return r;
        }
    }
    return nullptr;
}
book* library::find_book(const std::string& book_title) const {
    // 查找馆藏，如果有返回对应指针，否则返回nullptr
    for (auto& b : books) {
        if (b->get_title() == book_title) {
            return b;
        }
    }
    return nullptr;
}

bool library::borrowbook(const std::string& reader_name, const std::string& book_title) {
    reader* r = find_reader(reader_name);
    book* b = find_book(book_title);
    // 只有当读者和书籍都存在且书籍未被借出时，才能借阅
    if (r && b) {
        if (!b->check_borrowed())
        {
            return r->borrow_book(b);
            // 将书籍状态设为已借出
            b->set_borrowed(true);
        }
        else {
            std::cout << "书籍《" << book_title << "》已被借出，无法借阅。" << std::endl;
            return false;
        }
        
    }
    return false;
}

bool library::returnbook(const std::string& reader_name, const std::string& book_title) {
    reader* r = find_reader(reader_name);
    book* b = find_book(book_title);
    // 只有当读者和书籍都存在且书籍已被借出时，才能归还
    if (r && b && b->check_borrowed()) {
        return r->return_book(b);
        b->set_borrowed(false);
    }
    return false;
}

void library::print_info() const {
    std::cout << "图书馆名称: " << library_name << std::endl;
    std::cout << "馆藏书籍列表:" << std::endl;
    for (const auto& b : books) {
        b->print_info();
        std::cout << "------------------" << std::endl;
    }
    std::cout << "注册读者列表:" << std::endl;
    for (const auto& r : readers) {
        r->print_info();
        std::cout << "------------------" << std::endl;
    }
}