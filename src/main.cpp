#include<iostream>
#include<string>
#include"library.h"

using std::cout;
using std::endl;

int main() {
    library myLibrary("myLibrary");

    // 创建一些书籍
    book* book1 = new pyshical_book("C++ prime plus", "A1", "143");
    book* book2 = new pyshical_book("Data Structure", "B2", "236");
    book* book3 = new pyshical_book("Rust programming", "C3", "89");
    book* book4 = new pyshical_book("C++ prime plus", "D4", "495"); // 重复书名测试
    book* book5 = new pyshical_book("blender foundation", "E5", "152");
    book* book6 = new ebook("Digital Design", "www.digitaldesign.com", 5);
    book* book7 = new ebook("linux programming", "www.linux.com", 10);

    // 将书籍添加到图书馆
    myLibrary.add_book(book1);
    myLibrary.add_book(book2);
    myLibrary.add_book(book3);
    myLibrary.add_book(book4);
    myLibrary.add_book(book5);
    myLibrary.add_book(book6);
    myLibrary.add_book(book7);

    // 创建一些读者
    reader* reader1 = new reader("zhangsan");
    reader* reader2 = new reader("lisi");

    // 注册读者到图书馆
    myLibrary.register_reader(reader1);
    myLibrary.register_reader(reader2);

    // 让读者借阅书籍
    myLibrary.borrowbook("zhangsan", "C++ prime plus");
    myLibrary.borrowbook("lisi", "Data Structure");
    myLibrary.borrowbook("zhangsan", "Digital Design");

    // 让读者归还书籍
    myLibrary.returnbook("zhangsan", "C++ prime plus");

    // 打印图书馆信息
    myLibrary.print_info();

    // 清理动态分配的内存
    // myLibrary.clear_memory(); 析构函数自动调用

    // cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=17
    
    // 终于整完了，md实在太有操作太有实力太有生活了
    // md这回真整完了，终于解放了算是
    return 0;
}