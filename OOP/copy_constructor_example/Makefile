# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Targets
TARGET = main
OBJS = Deep.o Shallow.o main.o

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile object files
Deep.o: Deep.cpp Deep.h
	$(CXX) $(CXXFLAGS) -c Deep.cpp

Shallow.o: Shallow.cpp Shallow.h
	$(CXX) $(CXXFLAGS) -c Shallow.cpp

main.o: main.cpp Deep.h Shallow.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
