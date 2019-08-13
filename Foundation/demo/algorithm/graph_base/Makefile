cc = g++
target = main
obj = main.o BFS.o DFS.o base.o
$(target):$(obj)
	$(cc) $(obj) -Wall -o $(target)
main.o:main.cpp
	$(cc) -c main.cpp
base.o:base.cpp
	$(cc) -c base.cpp
DFS.o:DFS.cpp
	$(cc) -c DFS.cpp
BFS.o:BFS.cpp
	$(cc) -c BFS.cpp
clean:
	rm *.o $(target)
