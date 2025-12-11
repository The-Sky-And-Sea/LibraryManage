#include "reader.h"
#include <iostream>
#include <algorithm>

reader::reader(const std::string& s) : name(s) {}

reader::~reader() {}

std::string reader::get_name() const {
    return name;
}

bool reader::borrow_book(book* b = nullptr) {
    if (b && !b->check_borrowed()) {
        borrowed_books.push_back(b);
        b->set_borrowed(true);
        return true;
    }
    return false;
}

bool reader::return_book(book* b = nullptr) {
    auto it = std::find(borrowed_books.begin(), borrowed_books.end(), b);
    if (it != borrowed_books.end()) {
        borrowed_books.erase(it);
        b->set_borrowed(false);
        return true;
    }
    return false;
}

void reader::print_info() const {
    std::cout << "读者姓名: " << name << std::endl;
    std::cout << "借阅的书籍列表: " << std::endl;
    for (const auto& b : borrowed_books) {
        b->print_info();
    }
}