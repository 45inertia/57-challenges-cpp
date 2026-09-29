TARGET_EXE := ex03
CXX := g++
SOURCES_DIR := ./src
BUILD_DIR := ./build
INC_DIR := ./src/include

SRCS := $(shell find $(SOURCES_DIR) -name '*.cpp')	
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# for writing .d file listing headers next to .o files
DEPS := $(OBJS:.o=.d)

# -MMD and -MP write a .d file next to each .o file listing headers that the file includes. This is
# done so that if a header is updated the .o file is recompiled.
CPPFLAGS := -I$(INC_DIR) -MMD -MP
CXXFLAGS := -std=c++20 -g -Wall -Wformat -Wextra
INCFLAGS := -I$(INC_DIR)
LDFLAGS :=
LDLIBS :=

$(BUILD_DIR)/$(TARGET_EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS) 

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	rm -rf $(BUILD_DIR)

# pulls .d files into the makefile
-include $(DEPS)
