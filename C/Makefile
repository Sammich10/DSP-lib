# C/Makefile

# Compile the dsp.h and dsp.cpp file into a shared library, libdsp.so
# link the shared library into the main executable

# Makefile for building the DSP shared library and main executable

CXX ?= g++
CXXFLAGS = -Wall -c
LDFLAGS = -shared
LIB_NAME = libdsp
BUILD_DIR = ./build
SRC_DIR = ./src

# Builds the shared library and the main executable
all: $(BUILD_DIR)/$(LIB_NAME).so $(BUILD_DIR)/main.o
	$(CXX) -o main $(BUILD_DIR)/main.o -L$(BUILD_DIR) -ldsp

$(BUILD_DIR)/$(LIB_NAME).so: $(BUILD_DIR)/dsp.o
	$(CXX) $(LDFLAGS) -o $@ $<

$(BUILD_DIR)/dsp.o: $(SRC_DIR)/dsp.cpp $(SRC_DIR)/dsp.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up the build directory
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.so

