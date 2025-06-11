CXX = g++

project: main.o auxiliarytools.o bubblesort.o quicksort.o mergesort.o mergesortedarrays.o
	$(CXX) $? -o main

main.o: ../src/main.cpp
	$(CXX) ../src/main.cpp -c

auxiliarytools.o: ../src/auxiliarytools.cpp
	$(CXX) ../src/auxiliarytools.cpp -c

bubblesort.o: ../src/bubblesort.cpp
	$(CXX) ../src/bubblesort.cpp -c

quicksort.o: ../src/quicksort.cpp
	$(CXX) ../src/quicksort.cpp -c

mergesort.o: ../src/mergesort.cpp
	$(CXX) ../src/mergesort.cpp -c

mergesortedarrays.o: ../src/mergesortedarrays.cpp
	$(CXX) ../src/mergesortedarrays.cpp -c

clean:
	del *.o
