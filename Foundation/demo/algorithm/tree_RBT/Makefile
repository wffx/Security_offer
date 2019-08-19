cc = g++
target = main
obj = main.o redblacktree.o
$(target):$(obj)
	$(cc) $(obj) -Wall -o $(target)
main.o:main.cpp
	$(cc) -c main.cpp
redblacktree.o:redblacktree.cpp
	$(cc) -c redblacktree.cpp
clean:
	rm *.o $(target)
