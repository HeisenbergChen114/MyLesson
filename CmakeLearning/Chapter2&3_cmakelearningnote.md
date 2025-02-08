# 1.关于set文件名和设置cpp的版本以及可执行文件输出路径

set(Src_List FunctionObject1.cpp)#作为字符串变量
set(CMAKE_CXX_STANDARD 11)#设置C++11标准，由set指定；还可以通过命令行指定,-DCMAKE_CXX_STANDARD=11
#set(CMAKE_CXX_STANDARD_REQUIRED ON)#设置C++11标准为必须，由set指定；还可以通过命令行指定,-DCMAKE_CXX_STANDARD_REQUIRED=ON
#set(CMAKE_CXX_EXTENSIONS OFF)#关闭C++11标准的扩展，由set指定；还可以通过命令行指定,-DCMAKE_CXX_EXT

#指定输出路径，可以是绝对和相对路径
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#指定输出可执行程序路径，也可以是绝对和相对路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/aa/bb/cc)
add_executable(test ${Src_List})

# 2.搜索的方式来添加源文件
```cmake
#我们通过搜索当前目录下的所有源文件，并将其添加到Src_List变量中，这样就可以通过Src_List变量来添加源文件了
#1.方法1是用aux_source_directory来实现
#aux_source_directory(${PROJECT_SOURCE_DIR} Src_List)#将project目录下的所有源文件添加到Src_List变量中
#add_executable(test ${Src_List})#添加可执行程序test，源文件为Src_List变量中的所有源文件

#2.方法2用file(GLOB/GLOB——RECURSE)来实现,可以查找c,cpp,hpp,h文件
file(GLOB_RECURSE Src_List ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(test ${Src_List})
target_include_directories(${PROJECT_SOURCE_DIR}/include)#找到头文件目录
```

# 3.动态库和静态库的输出

#add_library(calc SHARED ${SRC_LIST})#动态库制作
add_library(calc STATIC ${SRC_LIST})#静态库制作
#add_executable(MyApp ${SRC_LIST})

set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/aa)#设置库文件输出路径

# 4.库的导入（包含系统和自定义库）
# 链接静态库
#1.
#link_libraries(${PROJECT_SOURCE_DIR}/lib1/libcalc.a)
#2.
link_libraries(calc)
link_directories(${PROJECT_SOURCE_DIR}/lib1)

# 链接动态库


当将静态库和动态库编译追加到应用程序以及加载到内存时，有以下不同的行为：

**静态库**：

编译时：
 - 静态库中的目标代码会被直接复制到应用程序的可执行文件中。
 - 链接器会解析对静态库中符号的引用，并将相应的代码段合并到最终的可执行文件中。

加载时：
 - 整个应用程序作为一个单一的实体被加载到内存中，包括从静态库中引入的代码。
 - 由于代码已经在可执行文件内部，不需要在运行时额外加载库文件。

**动态库**：

编译时：
 - 链接器只记录应用程序对动态库中符号的引用，而不会将动态库的代码复制到可执行文件中。
 - 会生成一些关于动态库的元数据，如库的名称、需要链接的符号等。

加载时：
 - 当应用程序启动时，操作系统会根据链接时记录的信息，在需要的时候加载动态库到内存中。
 - 多个使用相同动态库的应用程序可以共享内存中的同一份动态库代码，节省内存空间。
 - 如果动态库在运行时找不到，或者版本不匹配，可能会导致应用程序无法运行。

总的来说，静态库在编译时就完成了所有的代码合并，而动态库在运行时根据需要进行加载和链接。