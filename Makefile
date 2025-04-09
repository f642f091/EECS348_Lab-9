CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = matrix
SRCS = main.cpp matrix.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
