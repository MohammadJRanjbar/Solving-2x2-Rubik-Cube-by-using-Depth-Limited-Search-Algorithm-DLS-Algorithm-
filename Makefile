CXX = g++
CXXFLAGS = -std=c++17 -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++17 -Ih -pthread
OBJECTS = ./obj/main.o  ./obj/Matrix.o ./obj/Rubik_cube.o ./obj/Graph.o ./obj/ApProject.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
./obj/Matrix.o: ./cpp/Matrix.cpp
	$(CXX) $(CXXFLAGS) ./cpp/Matrix.cpp -o ./obj/Matrix.o
./obj/Rubik_cube.o: ./cpp/Rubik_cube.cpp
	$(CXX) $(CXXFLAGS) ./cpp/Rubik_cube.cpp -o ./obj/Rubik_cube.o
./obj/Graph.o: ./cpp/Graph.cpp
	$(CXX) $(CXXFLAGS) ./cpp/Graph.cpp -o ./obj/Graph.o
./obj/ApProject.o: ./cpp/ApProject.cpp
	$(CXX) $(CXXFLAGS) ./cpp/ApProject.cpp -o ./obj/ApProject.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
