CXX = g++

CXXFLAGS = -g -Wall -Werror -fmessage-length=0 -std=c++11

CPP_FILES = $(wildcard src/tests/*.cpp) $(wildcard src/tests/testrunner/*.cpp) $(wildcard src/string/*.cpp) $(wildcard src/tests/testrunner/leakdetection/*.cpp)

OBJS =	$(CPP_FILES:.cpp=.o)

LIBS = 

TARGET =	tests

$(TARGET):  $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
