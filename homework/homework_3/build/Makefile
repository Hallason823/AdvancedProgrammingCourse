CXX = g++

project: main.o stack.o queue.o auxiliarytools.o hashtable.o doublylinkedlist.o binarytree.o graph.o
	$(CXX) $? -o main

main.o: ../src/main.cpp
	$(CXX) ../src/main.cpp -c

stack.o: ../src/stack.cpp
	$(CXX) ../src/stack.cpp -c

queue.o: ../src/queue.cpp
	$(CXX) ../src/queue.cpp -c

auxiliarytools.o: ../src/auxiliarytools.cpp
	$(CXX) ../src/auxiliarytools.cpp -c

hashtable.o: ../src/hashtable.cpp
	$(CXX) ../src/hashtable.cpp -c

doublylinkedlist.o: ../src/doublylinkedlist.cpp
	$(CXX) ../src/doublylinkedlist.cpp -c

binarytree.o: ../src/binarytree.cpp
	$(CXX) ../src/binarytree.cpp -c

graph.o: ../src/graph.cpp
	$(CXX) ../src/graph.cpp -c

clean:
	del *.o