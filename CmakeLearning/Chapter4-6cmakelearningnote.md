# 学习使用日志
message(STATUS "66666666666")
message(STATUS "PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
# 链接动态库,需要在最后才写，生成app后才链接
# 先指定权限，在指定文件,PUBLIC可以传递给其他的目标
target_link_libraries(MyApp calc)#自定义库需要在此之前要有生成link_directories

# FATAL_ERROR可以退出日志，并且输出日志
#message(FATAL_ERROR "88888")
message(STATUS "77777777777")

# 变量的拼接
set(Src_List ${Src_List} main.cpp)
set(Src_List2 ${Src_List} swap.cpp)
set(Src_List3 ${Src_List} ${Src_List2} )#Src_List3拼接list和list2

# 变量的追加
