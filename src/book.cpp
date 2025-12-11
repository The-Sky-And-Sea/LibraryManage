#include "book.h"
#include <iostream>

book::book(std::string t, bool b = false) : title(t), is_borrowed(b) {}

book::~book() {}

std::string book::get_title() const {
    return title;
}

void book::set_borrowed(bool status) {
    is_borrowed = status;
}

bool book::check_borrowed() const {
    return is_borrowed;
}

void book::print_info() const {
    std::cout << "书名: " << title << " , 是否借出: " << (is_borrowed ? "是" : "否") << std::endl;
}
