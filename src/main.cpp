#include<iostream>
#include<string>
#include"library.h"

using std::cout;
using std::endl;

int main() {
    library myLibrary("myLibrary");

    // 创建一些书籍
    book* book1 = new book("C++ prime plus", "A1");
    book* book2 = new book("Data Structure", "B2");
    book* book3 = new book("Rust programming", "C3");
    book* book4 = new book("C++ prime plus", "D4"); // 重复书名测试
    book* book5 = new book("blender foundation", "E5");

    // 将书籍添加到图书馆
    myLibrary.add_book(book1);
    myLibrary.add_book(book2);
    myLibrary.add_book(book3);
    myLibrary.add_book(book4);
    myLibrary.add_book(book5);

    // 创建一些读者
    reader* reader1 = new reader("zhangsan");
    reader* reader2 = new reader("lisi");

    // 注册读者到图书馆
    myLibrary.register_reader(reader1);
    myLibrary.register_reader(reader2);

    // 让读者借阅书籍
    myLibrary.borrowbook("zhangsan", "C++ prime plus");
    myLibrary.borrowbook("lisi", "Data Structure");

    // 打印图书馆信息
    myLibrary.print_info();

    // 让读者归还书籍
    myLibrary.returnbook("zhangsan", "C++ prime plus");

    // 打印图书馆信息
    myLibrary.print_info();

    // 清理动态分配的内存
    delete book1;
    delete book2;
    delete book3;
    delete book4;
    delete book5;
    delete reader1;
    delete reader2;

    return 0;
}