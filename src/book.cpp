#include "book.h"
#include <iostream>

book::book(std::string t) : title(t), is_borrowed(false){}

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


//实体书
pyshical_book::pyshical_book(std::string t, std::string s, std::string n) : book(t), shelf(s), number(n) {}

pyshical_book::~pyshical_book() {}

std::string pyshical_book::get_shelf_number() const {
        return shelf + " " + number;
}

void pyshical_book::print_info() const {
    std::cout << "[Pyshical]: " << shelf << " " << number << "  " << title << "   " 
        << (is_borrowed ? "lent" : "available") << std::endl;
}

// 电子书
ebook::ebook(std::string t, std::string l, int s) : book(t), link(l), size(s) {}
// 电子书析构函数
ebook::~ebook() {}
// 打印电子书信息
void ebook::print_info() const {
    std::cout << "[E-book]: " << title << "   " << size << "MB   " << link << "   "
        << (is_borrowed ? "lent" : "available") << std::endl;
}