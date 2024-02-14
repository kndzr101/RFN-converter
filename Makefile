onp: onp.o 
	g++ -g -o onp onp.o
onp.o: onp.cpp stacks.hpp
	g++ -c onp.cpp
clean:
	rm *.o *~* onp	
