CXX = g++
CXXFLAGS = -Iinclude

SRCS = src/rnt.cpp \
	   src/rnt-main.cpp \
	   src/rnt-enum.cpp \
	   src/rnt-texteditor.cpp
OBJS = $(SRCS:.cpp=.o) # convert .cpp to .o
TARGET = build/rnt

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
