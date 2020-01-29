#获取所有的.cpp文件,wildcard函数的使用
SrcFiles=$(wildcard *.cpp) #这里的SrcFiles变量就是所有的.cpp文件了
#使所有的.cpp文件变成.o文件，pastsubst函数的使用
Objfiles=$(patsubst %.cpp,%.o,$(SrcFiles)) #这里通过函数的三个参数，将第三个参数里的SrcFiles变量的所有.cpp变成了.o
#目标变量的使用$(Objfiles)

all:myString

myString:$(Objfiles)
	g++ -o myString -I./include $(Objfiles)
#模式匹配规则，$@,$< 这样的变量，只能在规则中出现
%.o:%.cpp
	# g++ -o $@ -c -I./include $^
	# g++ -c -I./include $^
	g++  -c -I./include $<

.PHONY:clean

clean:
	-@rm -f *.o
	-@rm -f myString
