# main: main.o array_sort.o avl_tree.o binary_search_tree.o
# 	g++ -std=c++11 -o main main.o array_sort.o avl_tree.o binary_search_tree.o

main: main.o binary_search_tree.o array_sort.o
	g++ -std=c++11 -o main main.o 
	chmod +x main
	./main

binary_search_tree.o: include/binary_search_tree.cpp include/binary_search_tree.h
	g++ -c include/binary_search_tree.cpp

array_sort.o: include/array_sort.cpp include/array_sort.h
	g++ -c include/array_sort.cpp

# avl_tree.o: include/avl_tree.cpp include/avl_tree.h
# 	g++ -std=c++11 -c include/avl_tree.cpp
	

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o main
