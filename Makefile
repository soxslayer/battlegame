CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS = -Wall
CXXFLAGS = -g
LDFLAGS = 

SRCS = assign3.cpp creature.cpp

OBJS = $(SRCS:.cpp=.o) 

TARGET = assign3 

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(TARGET)


