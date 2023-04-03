CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SRC := $(wildcard src/*.cpp)
INC_DIR := $(wildcard src/headers/)

VulkanTest: main.cpp $(SRC) $(INC_DIR)
	g++ $(CFLAGS) -I$(INC_DIR) -o VulkanTest main.cpp $(SRC) $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest