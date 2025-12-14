## 1. 项目介绍

第一次写c++项目，学校里教的c++简直依托，边写边重新学c++，写的不咋地，勿喷

### 1.1 项目描述
做了一个简单的图书管理系统，实现了对图书的借书和还书功能，读者则是可以注册并且记录自己借的书籍，因为还不是很会用mysql，所以就先把图书馆的信息直接写在info.txt里，每次程序运行时从info.txt里读取初始化，然后最后在程序执行完毕后将更改后的信息再写进去

### 1.2 代码功能
共有book，reader，library，pyshical_book(应该是physical_book实体书，只不过最后发现的时候太晚了懒得改了)，ebook五个类。

其中book是基类，pyshical_book和ebook则是book的子类，book拥有两个属性名称title和是否借出is_borrowed。
pyshical_book公有继承book类并且添加了两个属性书架shelf和编号number。因为类型是实体书，也用不着成员变量，直接用gettype函数返回"physical"
而ebook则是添加了另外两个属性link(网址)和size(内存大小mb)。gettype返回"ebook"。

reader则是有两个属性，一个是读者名称name，另外一个是存放借阅的图书的指针的向量vector容器的borrowed_books，实现了相关的借书还书函数

library类则是含有三个属性，第一个是图书馆名字library_name，第二个是图书馆的注册读者readers，第三个是图书馆的馆藏书籍books，后两个是用vector容器存储对应类型的指针
也写了相关的借书还书函数，还有一些功能比如find_book，find_reader，
find_book防止图书馆馆藏里没有的书被借出去或者再往图书馆里添加书籍时添加重复书籍(同一本书有很多本这个我就不想考虑了)
find_reader则是防止读者重复注册或者未注册的情况下借书还书

最后程序执行时调用的是library对象的函数，这些library中的函数会调用book和reader的函数保证信息同步，最后程序快执行完时会打印图书馆相关的信息，再调用save_to_file将信息保存到本地文件info.txt中

## 2. 项目结构
因为写c++比较少，对c++工程化的项目结构不是很熟，勿喷

```
bookManage/
├── include/            
│   ├── book.h          
│   ├── reader.h        
│   └── library.h       
├── src/             
│   ├── book.cpp       
│   ├── reader.cpp     
│   ├── library.cpp     
│   └── main.cpp        
├── bin/
|   ├── info.txt   
|   ├── library_system.exe       
├── CMakeLists.txt      
└── README.txt          

```

## 3. 项目构建与运行方式
我是用的windows系统和vscode，编译器使用的mingw64，还有cmake(4.2.0)，vs2022的编译器msvc有点抽象，生成的中间文件搞不懂，不推荐使用

vscode，mingw64，cmake这三个工具csdn上都有教程，就不多说了
建议安装mingw64并添加环境变量后进入mingw64的bin目录中

然后将mingw32-make.exe复制粘贴在同一文件夹下，重命名为make.exe
这样使用cmake编译时可以写短一点，直接写make就行了

从github上下载源码后进入根目录LibraryManage中
```shell
# 创建build文件夹
mkdir build
# 进入build文件夹
cd build
# 指定mingw64编译器编译，否则会自动选择电脑上最适合的编译器比如msvc进行编译
cmake .. -G "MinGW Makefiles"
# 编译
make
# 或者
mingw32-make
```

或者使用g++编译，虽然不是太麻烦但是项目一旦大了那就很有生活了：
```shell
# 在根目录下g++
g++ -std=c++17 -I include src/*.cpp -o Library_system
# 然后运行可执行文件
.\library_system.exe
```

## 4. 最后
- 版本：1.0 其实以后也不会更新了
- 学号：2024213460
- 开发环境：c++17
