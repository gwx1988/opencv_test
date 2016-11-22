#通用Makefile模板,cpp版
#来源于网络
#整理人：SSJ
#邮箱：bisunshujun@163.com
#时间：2013.12.24
#修订：2016.11.21

#这条语句定义了一个变量SRCS，它的值就是当前面目录下面所有的以.cpp结尾的源文件。
SRCS = $(wildcard *.cpp)

#这里变量OBJS的值就是将SRCS里面所有.cpp文件编译出的.o目标文件
OBJS = $(SRCS:.cpp = .o)

#变量CC代表我们要使用的编译器
CC = g++

#这里指定除了编译器默认的头文件和库文件的路径之外需要额外引用的头文件路径以及库的路径（×××表示路径）。
#INCLUDES = -I/×××
#LIBS = -L/×××
INCLUDES = `pkg-config opencv --cflags`
LIBS = `pkg-config opencv --libs`

#CCFLAGS变量存放的是编译选项
CCFLAGS = -g -Wall -O0

#my_app依赖于所有的.o文件，$^代表$(OBJS)，$@代表my_app
my_app : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)

#将所有的.cpp源代码编译成.o目标文件
%.o : %.cpp
	$(CC) -c $< $(CCFLAGS)

#在执行make clean之后删除所有编译过程中生成的.o文件。
clean:
	rm *.o

#每次执行make clean时都要执行rm *.o命令
.PHONY:clean

