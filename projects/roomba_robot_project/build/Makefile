CXX = g++

my_project: main.o map.o battery.o robot.o jimmy.o alfred.o
	$(CXX) $? -o main

main.o: ../src/main.cpp
	$(CXX) ../src/main.cpp -c

map.o: ../src/map.cpp
	$(CXX) ../src/map.cpp -c

battery.o: ../src/battery.cpp
	$(CXX) ../src/battery.cpp -c

robot.o: ../src/robot.cpp
	$(CXX) ../src/robot.cpp -c

jimmy.o: ../src/jimmy.cpp
	$(CXX) ../src/jimmy.cpp -c

alfred.o: ../src/alfred.cpp
	$(CXX) ../src/alfred.cpp -c

clean:
	del *.o