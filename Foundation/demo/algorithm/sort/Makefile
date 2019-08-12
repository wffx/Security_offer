cc=g++
target=main
obj=main.o bubble.o choose.o heap.o insert.o merge.o quick.o
$(target):$(obj)
	$(cc) $(obj) -Wall -o $(target)
main.o:main.cpp
	$(cc) -c main.cpp
bubble.o:bubble.cpp
	$(cc) -c bubble.cpp
choose.o:choose.cpp
	$(cc) -c choose.cpp
heap.o:heap.cpp
	$(cc) -c heap.cpp
insert.o:insert.cpp
	$(cc) -c insert.cpp
merge.o:merge.cpp
	$(cc) -c merge.cpp
quick.o:quick.cpp
	$(cc) -c quick.cpp
clean:
	rm  *.o $(target)
