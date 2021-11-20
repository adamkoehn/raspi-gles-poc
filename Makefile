CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -g
GLFLAGS = $(shell pkg-config --cflags glfw3 glew)
LDLIBS = $(shell pkg-config --libs glfw3 glew)

.PHONY: clean

demo: src/main.cpp WindowFactory.o Platform.o ShaderFactory.o PrimitiveFactory.o Triangle.o
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -o demo src/main.cpp src/WindowFactory.o src/Platform.o src/ShaderFactory.o src/PrimitiveFactory.o src/Triangle.o $(LDLIBS)

WindowFactory.o: src/WindowFactory.h src/WindowFactory.cpp
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -c -o src/WindowFactory.o src/WindowFactory.cpp

Platform.o: src/Platform.h src/Platform.cpp
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -c -o src/Platform.o src/Platform.cpp

ShaderFactory.o: src/ShaderFactory.h src/ShaderFactory.cpp
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -c -o src/ShaderFactory.o src/ShaderFactory.cpp

PrimitiveFactory.o: src/PrimitiveFactory.h src/PrimitiveFactory.cpp
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -c -o src/PrimitiveFactory.o src/PrimitiveFactory.cpp

Triangle.o: src/Triangle.h src/Triangle.cpp
	$(CXX) $(CXXFLAGS) $(GLFLAGS) -c -o src/Triangle.o src/Triangle.cpp

clean:
	rm -f demo src/WindowFactory.o src/Platform.o src/ShaderFactory.o src/PrimitiveFactory.o src/Triangle.o
