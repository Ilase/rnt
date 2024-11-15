CXX = g++
CXXFLAGS = -Iinclude
BUILD = build
PREFIX = "[RNT] "
SRCS = $(wildcard src/*.cpp)


OBJS:=$(SRCS:src/%.cpp=$(BUILD)/%.o) 
TARGET=$(BUILD)/rnt

.PHONY: all clean

all: $(OBJS) $(TARGET)
# -------------------------------------------
$(OBJS): $(BUILD)/%.o : src/%.cpp | $(BUILD)
	@echo $(PREFIX) "Compiling $< to $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
$(BUILD):
	@echo $(PREFIX) "Creating build directory..." 
	@mkdir -p $(BUILD)
# -------------------------------------------
$(TARGET): $(OBJS)
	@echo $(PREFIX) "Linking objects in "$(BUILD)" with target "$(TARGET)
	@$(CXX) $(OBJS) -o $(TARGET)

clean:

	@rm -fr $(BUILD)
