TARGET_EXE := ex04
CXX := g++
SRC_DIR := ./src
BUILD_DIR := ./build
INC_DIR := ./src/include

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CPPFLAGS := -I$(INC_DIR) -MMD -MP
CXXFLAGS := -std=c++20 -g -Wall -Wformat -Wextra
INCFLAGS := -I$(INC_DIR)
LDFLAGS :=
LDLIBS :=

$(BUILD_DIR)/$(TARGET_EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c %< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
