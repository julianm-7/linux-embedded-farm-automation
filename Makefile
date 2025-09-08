CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/motor_control.cpp src/grid_scanner.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = test_motor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./scripts/run_farm.sh

test: all
	./test_motor
	pytest tests/test_lidar.py

clean:
	rm -f $(OBJ) $(TARGET)
