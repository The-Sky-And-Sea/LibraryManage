# 📚 图书馆管理系统

第一次正了八经写c++项目，而且学校教的c++又是依托，边写边学
写完脑子过载了，让ai帮我写了这个README.md

## 🎯 项目简介

一个基于C++的现代化图书馆管理系统，支持实体书和电子书的借阅、归还和完整生命周期管理。采用面向对象设计，具备完善的数据持久化功能。

---

## 🛠️ 环境搭建指南

### 📋 系统要求

| 组件 | 最低要求 | 推荐版本 |
|------|----------|----------|
| 操作系统 | Windows 10 / Ubuntu 18.04 / macOS 10.14 | Windows 11 / Ubuntu 20.04 / macOS 12 |
| 编译器 | GCC 7.0+ / MinGW-w64 8.0+ | GCC 11.0+ / MinGW-w64 10.0+ |
| 构建工具 | CMake 3.10+ | CMake 3.20+ |
| 内存 | 100MB 可用空间 | 500MB 可用空间 |

### 🚀 快速环境配置

#### Windows 用户

**方案A：使用 MSYS2 + MinGW-w64（推荐）**

```powershell
# 1. 安装 MSYS2（如果未安装）
# 下载地址：https://www.msys2.org/

# 2. 打开 MSYS2 MinGW 64-bit 终端
# 3. 安装编译工具链
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-make

# 4. 验证安装
gcc --version
cmake --version
make --version
```

**方案B：使用 Chocolatey 一键安装**

```powershell
# 以管理员身份运行 PowerShell
# 1. 安装 Chocolatey（如果未安装）
Set-ExecutionPolicy Bypass -Scope Process -Force
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))

# 2. 安装编译工具
choco install mingw cmake make -y

# 3. 添加环境变量（可能需要重启）
$env:Path += ";C:\ProgramData\chocolatey\bin;C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin"
```

#### Linux 用户（Ubuntu/Debian）

```bash
# 1. 更新包管理器
sudo apt update

# 2. 安装编译工具链
sudo apt install build-essential g++ cmake make git -y

# 3. 验证安装
g++ --version
cmake --version
```

### ✅ 环境验证

配置完成后，运行以下命令验证环境：

```bash
# 检查编译器
g++ --version
# 应显示类似：g++ (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 12.2.0

# 检查 CMake
cmake --version
# 应显示类似：cmake version 3.25.1

# 检查 Make
make --version
# 应显示类似：GNU Make 4.3
```

---

## 🏗️ 项目构建与运行

### 📁 项目结构概览

```
bookManage/
├── 📁 include/          # 头文件目录
│   ├── book.h          # 📖 书籍基类
│   ├── reader.h        # 👤 读者类
│   └── library.h       # 🏛️ 图书馆主类
├── 📁 src/             # 源代码目录
│   ├── book.cpp        # 书籍实现
│   ├── reader.cpp      # 读者实现
│   ├── library.cpp     # 图书馆实现
│   └── main.cpp        # 🎬 程序入口
├── info.txt            # 💾 数据存储文件
├── CMakeLists.txt      # 🔧 CMake 配置
└── README.txt          # 📋 本文档
```

### 🔨 构建步骤详解

#### 方法一：标准CMake构建（推荐）

**步骤1：准备项目**
```bash
# 克隆或下载项目
git clone <项目地址>
cd bookManage

# 或者直接进入项目目录
cd /path/to/bookManage
```

**步骤2：配置构建环境**

*Windows (MinGW-w64):*
```powershell
# 创建构建目录
mkdir build
cd build

# 生成构建文件
cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=17

# 或者指定编译器路径
cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
```

*Linux/macOS:*
```bash
mkdir build
cd build
cmake .. -DCMAKE_CXX_STANDARD=17
```

**步骤3：编译项目**

*Windows:*
```powershell
# 使用 make
make -j4  # -j4 表示使用4个核心并行编译

# 或者使用 mingw32-make
mingw32-make -j4
```

*Linux/macOS:*
```bash
make -j4
```

**步骤4：查看输出**
```bash
# 编译成功后，可执行文件位于
# Windows: bin/library_system.exe
# Linux/macOS: bin/library_system

ls -la bin/
```

#### 方法二：一键构建脚本

创建 `build.sh` (Linux/macOS) 或 `build.bat` (Windows):

**build.sh (Linux/macOS):**
```bash
#!/bin/bash
echo "🚀 开始构建图书馆管理系统..."

# 清理旧构建
rm -rf build
rm -rf bin

# 创建目录
mkdir -p build
mkdir -p bin

# 进入构建目录
cd build

# 配置
echo "⚙️  配置CMake..."
cmake .. -DCMAKE_CXX_STANDARD=17

# 编译
echo "🔨 编译项目..."
make -j$(nproc)

# 返回项目根目录
cd ..

# 运行程序
echo "🚀 运行程序..."
if [ -f "bin/library_system" ]; then
    ./bin/library_system
else
    echo "❌ 构建失败！"
fi
```

**build.bat (Windows):**
```batch
@echo off
echo 🚀 开始构建图书馆管理系统...

REM 清理旧构建
if exist build rmdir /s /q build
if exist bin rmdir /s /q bin

REM 创建目录
mkdir build
mkdir bin

REM 进入构建目录
cd build

REM 配置CMake
echo ⚙️  配置CMake...
cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=17

REM 编译
echo 🔨 编译项目...
mingw32-make -j4

REM 返回项目根目录
cd ..

REM 运行程序
echo 🚀 运行程序...
if exist "bin\library_system.exe" (
    bin\library_system.exe
) else (
    echo ❌ 构建失败！
)

pause
```

#### 方法三：直接编译（快速测试）

```bash
# 一行命令编译运行
g++ -std=c++17 -I include src/*.cpp -o library_system && ./library_system
```

### 🚀 运行程序

**首次运行：**
```bash
# 进入项目目录
cd bookManage

# 运行程序
./bin/library_system  # Linux/macOS
# 或
bin\library_system.exe  # Windows
```

**程序执行流程：**
1. ✅ 加载现有数据（如果 info.txt 存在）
2. ✅ 创建示例书籍和读者
3. ✅ 执行借阅/归还操作
4. ✅ 打印当前状态
5. ✅ 保存数据到 info.txt

### 📊 预期输出示例

```
====LIBRARY NAME====
myLibrary

====ALL BOOKS====
[Pyshical]: A1 143  C++ prime plus   available
[Pyshical]: B2 236  Data Structure   lent
[Pyshical]: C3 89  Rust programming   available
[Pyshical]: E5 152  blender foundation   available
[E-book]: Digital Design   5MB   www.digitaldesign.com   lent
[E-book]: linux programming   10MB   www.linux.com   available

====READERS====
reader's name: zhangsan
reader's name: lisi

over
Saving library data to file: info.txt
```

---

## 🔧 高级配置

### 自定义数据文件
```cpp
// 在 main.cpp 中修改
library myLibrary("我的图书馆", "custom_data.txt");
```

### 构建选项
```bash
# 调试模式（包含调试符号）
cmake .. -DCMAKE_BUILD_TYPE=Debug

# 发布模式（优化）
cmake .. -DCMAKE_BUILD_TYPE=Release

# 指定安装目录
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
```

### 多平台编译
```bash
# Linux 静态编译
cmake .. -DBUILD_STATIC=ON

# Windows 跨平台编译
cmake .. -G "Visual Studio 17 2022" -A x64
```

---

## 🐛 故障排除

### 常见问题解决

**问题1：CMake找不到编译器**
```bash
# 指定编译器路径
cmake .. -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++
```

**问题2：make命令不存在**
```bash
# Windows：使用 mingw32-make
mingw32-make

# 或安装make
choco install make
```

**问题3：权限不足**
```bash
# Linux/macOS
chmod +x build.sh
sudo make install
```

**问题4：C++版本不匹配**
```bash
# 在 CMakeLists.txt 中修改
set(CMAKE_CXX_STANDARD 17)  # 改为 11, 14, 17 或 20
```

### 调试模式
```bash
# 1. 启用调试
cmake .. -DCMAKE_BUILD_TYPE=Debug

# 2. 编译
make

# 3. 使用GDB调试
gdb ./bin/library_system
# gdb常用命令：
# break main      # 设置断点
# run            # 运行
# next           # 下一步
# print variable # 查看变量
# quit           # 退出
```

---

## 📁 文件说明

| 文件 | 用途 | 重要性 |
|------|------|--------|
| `info.txt` | 数据存储文件 | 🔴 重要！不要手动修改 |
| `CMakeLists.txt` | 构建配置文件 | 🟡 修改需谨慎 |
| `include/*.h` | 类定义头文件 | 🟢 可以查看和修改 |
| `src/*.cpp` | 类实现源文件 | 🟢 可以查看和修改 |

---

## 🎮 快速开始检查清单

1. [ ] 安装编译器（g++/MinGW）
2. [ ] 安装 CMake 3.10+
3. [ ] 安装 Make 工具
4. [ ] 克隆/下载项目到本地
5. [ ] 运行环境验证命令
6. [ ] 进入项目目录
7. [ ] 执行 `mkdir build && cd build`
8. [ ] 执行 `cmake ..`
9. [ ] 执行 `make`
10. [ ] 运行 `../bin/library_system`

---

## 📞 获取帮助

如果遇到问题：

1. **检查环境**：运行 `g++ --version` 和 `cmake --version`
2. **查看错误**：仔细阅读控制台输出
3. **验证步骤**：对照本文档的每个步骤
4. **检查权限**：确保对目录有读写权限
5. **清理重试**：删除 `build/` 和 `bin/` 目录重新构建

---

**🎉 现在你已经准备好开始使用图书馆管理系统了！**

**系统版本**: 1.0  
**最后更新**: 2024年  
**作者**: [你的名字]  
**开发环境**: C++17 + CMake + 面向对象设计  

**祝您使用愉快！** 🚀📚