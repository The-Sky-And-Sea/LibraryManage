#include "library.h"
#include <iostream>
#include <fstream>
#include <sstream>

library::library(const std::string name, const std::string& datafile) : library_name(name) {
    try{
        // 从文件加载数据
        load_from_file("info.txt");
    }
    catch(const std::exception& e){
        std::cout << "Exception occurred while loading data: " << e.what() << std::endl;
    }
    
}

library::~library() {
    save_to_file("info.txt");
    clear_memory();
}

//------------------------------------------------------------------
// 从文件中读取书籍和读者信息
void library::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    std::string line;
    std::string section;

    while (std::getline(file, line)){
        if (line.empty()) continue;
        if (line[0] == '#'){
            section = line;
            continue;
        }
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;;
        while (std::getline(iss, token, ',')){
            tokens.push_back(token);
        }

        if (section == "# BOOKs" && tokens.size() >= 4) {
            std::string type = tokens[0];
            std::string title = tokens[1];
            if (type == "physical") 
            {
                std::string shelf = tokens[2];
                std::string number = tokens[3];
                // 创建实体书对象并添加到馆藏
                book* new_book = new pyshical_book(title, shelf, number);
                books.emplace_back(new_book);

            }
            else if (type == "ebook") 
            {
                std::string url = tokens[2];
                int size = std::stoi(tokens[3]);
                // 创建电子书对象并添加到馆藏
                book* new_book = new ebook(title, url, size);
                books.emplace_back(new_book);
            }
            
        }
        else if (section == "# READERS" && !tokens.empty()) {
            reader* new_reader = new reader(tokens[0]);
            readers.emplace_back(new_reader);
        }
        else if (section == "#BORROWED BOOKS" && tokens.size() >= 2) {
            std::string reader_name = tokens[0];
            std::string book_title = tokens[1];
            reader* r = find_reader(reader_name);
            for (int i = 1; i < tokens.size(); i++)
            {
                book* b = find_book(book_title);
                if (r && b) {
                    r->borrow_book(b);
                    b->set_borrowed(true);
                }
            }
        }
    }
    // 这里可以添加从文件读取书籍和读者信息的实现
    std::cout << "Loading library data from file: " << filename << std::endl;
}

// 保存书籍和读者信息到文件
void library::save_to_file(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    file << "# BOOKs\n";
    for (const auto& b : books) {
        file << b->get_type() << ",";
        file << b->get_title() << ",";
        if (b->get_type() == "Physical") {
            pyshical_book* pb = dynamic_cast<pyshical_book*>(b);
            file << pb->get_shelf() << ",";
            file << pb->get_number() << "\n";
        }
        else if (b->get_type() == "E-book") {
            ebook* eb = dynamic_cast<ebook*>(b);
            file << eb->get_link() << ",";
            file << eb->get_size() << "\n";
        }
    }

    file << "\n# READERS\n";
    for (const auto& r : readers) {
        file << r->get_name() << "\n";
    }

    file << "\n# BORROWED BOOKS\n";
    for (const auto& r : readers) {
        file << "111111\n";
        for (const auto& b : r->get_borrowed_books()) {
            file << r->get_name() <<"," << b->get_title() << "\n";
        }
    }

    // 这里可以添加保存书籍和读者信息到文件的实现
    std::cout << "Saving library data to file: " << filename << std::endl;
}

//------------------------------------------------------------------

void library::add_book(book* b) {
    if (b && !find_book(b->get_title())) {
        books.push_back(b);
    } else {
        delete b; // 避免内存泄漏
    }
}

void library::register_reader(reader* r) {
    if (r && !find_reader(r->get_name())) {
        readers.push_back(r);
    } else {
        delete r; // 避免内存泄漏
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
            // 将书籍状态设为已借出
            b->set_borrowed(true);
            r->borrow_book(b);
            return true;
        }
        else {
            std::cout << "book: " << book_title << ", is borrowed" << std::endl;
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
        b->set_borrowed(false);
        r->return_book(b);
        return true;
        
    }
    return false;
}

void library::print_info() const {
    std::cout << "====LIBRARY NAME====\n" << library_name << std::endl << std::endl;
    std::cout << "====ALL BOOKS====" << std::endl;
    for (const auto& b : books) {
        b->print_info();
    }
    std::cout << "\n====READERS====" << std::endl;
    for (const auto& r : readers) {
        r->print_info();
    }
    
    std::cout << "\nover\n";
}

void library::clear_memory() {
    for (auto& b : books) {
        delete b;
    }
    books.clear();

    for (auto& r : readers) {
        delete r;
    }
    readers.clear();
}