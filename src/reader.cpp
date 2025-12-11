#include "reader.h"
#include <iostream>
#include <algorithm>

reader::reader(const std::string& s) : name(s) {}

reader::~reader() {}

const std::string reader::get_name() const {
    return name;
}

bool reader::borrow_book(book* b) {
    if (b && !b->check_borrowed()) {
        borrowed_books.push_back(b);
        b->set_borrowed(true);
        return true;
    }
    return false;
}

void reader::return_book(book* b) {
    for (auto it = borrowed_books.begin(); it != borrowed_books.end(); ++it) {
        if (*it == b) {
            borrowed_books.erase(it);
            b->set_borrowed(false);
            break;
        }
    }
}

void reader::print_info() const {
    std::cout << "reader's name: " << name << std::endl;
}