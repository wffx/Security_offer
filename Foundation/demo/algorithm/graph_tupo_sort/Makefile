cc = g++
target = main
obj = main.o base.o 
$(target):$(obj)
	$(cc) $(obj) -Wall -o $(target)
main.o: main.cpp
	$(cc) -c main.cpp
base.o:base.cpp
	$(cc) -c base.cpp
clean:
	rm *.o $(target)
