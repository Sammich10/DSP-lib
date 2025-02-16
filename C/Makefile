# C/Makefile

# Compile the libdsp.h and libdsp.cpp file into a shared library, libdsp.so
# link the shared library into the main executable

# Makefile for building the DSP shared library and main executable

ifeq ($(wildcard $(addsuffix /rm,$(subst :, ,$(PATH)))),)
WINMODE=1
else
WINMODE=0
endif

CXX ?= g++
CXXFLAGS = -Wall -c -std=c++11 -g
LDFLAGS = -shared
LIB_NAME = libdsp
BUILD_DIR = ./build
SRC_DIR = ./src
EXE_NAME = main

# Create a portable executable that statically links to the shared library instead of the dynamic library (just for fun)
port: dsp dsplib main
	$(CXX) -o $(EXE_NAME)_static.exe -static $(BUILD_DIR)/main.o $(BUILD_DIR)/libdsp.so

# Builds the shared library and the main executable, dynamically links them
all: dsp dsplib main
	$(CXX) -o $(EXE_NAME).exe $(BUILD_DIR)/main.o $(BUILD_DIR)/libdsp.so -L/usr/lib/ -ldsp

# Compile the libdsp cpp and header files
dsp: $(SRC_DIR)/libdsp.cpp $(SRC_DIR)/libdsp.h
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/libdsp.o $<

# Create the shared library from the compiled object file(s)
# This will copy the shared library to /usr/lib so the dynamic linker can find it. Kind of a hack
# libs can be reloaded with sudo ldconfig -v
ifeq ($(WINMODE), 0)
dsplib: $(BUILD_DIR)/libdsp.o
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$(LIB_NAME).so $<
	sudo cp $(BUILD_DIR)/$(LIB_NAME).so /usr/lib/;
else
dsplib: $(BUILD_DIR)/libdsp.o
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$(LIB_NAME).so $<
endif

# Compile the main executable object
main: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/main.o $<

# Clean up the build directory
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.so *.exe
	if [ -e /lib/$(LIB_NAME).so ]; then sudo rm /lib/$(LIB_NAME).so; fi


