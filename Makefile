CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = main.cpp record.cpp question.cpp htmlfunc.cpp

OBJS = main.o record.o question.o htmlfunc.o

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main