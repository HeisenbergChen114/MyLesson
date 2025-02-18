# 学习使用日志
```cmake
message(STATUS "66666666666")
message(STATUS "PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
# 链接动态库,需要在最后才写，生成app后才链接
# 先指定权限，在指定文件,PUBLIC可以传递给其他的目标
target_link_libraries(MyApp calc)#自定义库需要在此之前要有生成link_directories

# FATAL_ERROR可以退出日志，并且输出日志
#message(FATAL_ERROR "88888")
message(STATUS "77777777777")
```


# 变量的拼接
```cmake
set(Src_List ${Src_List} main.cpp)
set(Src_List2 ${Src_List} swap.cpp)
set(Src_List3 ${Src_List} ${Src_List2} )#Src_List3拼接list和list2

# 变量的追加
list(APPEND Src_List4 ${Src_list} ${Src_List2} ${Src_List3} )

# 变量的移除

list(REMOVE_ITEM Src_List4 ${PROJECT_SOURCE_DIR}/src/swap.cpp)

```

在 CMake 中，`list` 相关的操作主要用于处理列表数据。虽然它不是像其他编程语言中的标准列表数据结构那样具有丰富的字符串方法，但有一些与字符串处理和列表操作相关的命令和函数。

以下是一些常见的与 `list` 处理字符串相关的 CMake 操作：

1. `list(APPEND list_name element)`: 向列表 `list_name` 末尾添加元素 `element` 。
2. `list(FIND list_name value)`: 在列表 `list_name` 中查找值 `value` 并返回其索引，如果未找到则返回 `-1` 。
3. `list(INSERT list_name index element)`: 在列表 `list_name` 的指定索引 `index` 处插入元素 `element` 。
4. `list(LENGTH list_name)`: 返回列表 `list_name` 的长度。
5. `list(REMOVE_AT list_name index)`: 从列表 `list_name` 中移除指定索引 `index` 处的元素。
6. `list(REMOVE_ITEM list_name value)`: 从列表 `list_name` 中移除值为 `value` 的第一个元素。

这些操作可以用于处理包含字符串的列表，以满足一些基本的列表管理需求。