CXX= g++
CXXFLAGS= -Iinclude

SRCS = src/rnt.cpp \
       src/rnt-mainapp.cpp \
       src/rnt-enum.cpp \
       src/rnt-texteditor.cpp \
       src/rnt-sys.cpp \
       src/rnt-configurator.cpp \
       src/rnt-main.cpp \


OBJS=$(SRCS:.cpp=.o) 
TARGET=build/rnt

.PHONY: all clean

all: $(TARGET)

%.o: %.cpp
	@echo "[--] Building object $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
