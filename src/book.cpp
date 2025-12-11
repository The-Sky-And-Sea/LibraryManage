#include "book.h"
#include <iostream>

book::book(std::string t, std::string shelfnum) : title(t), is_borrowed(false), shelf_number(shelfnum) {}

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

std::string book::get_shelf_number() const {
    return shelf_number;
}

void book::print_info() const {
    std::cout << "shelf and number:  " << shelf_number <<", book name: " << title << ", status " << (is_borrowed ? "lent" : "in library") << std::endl;
}
