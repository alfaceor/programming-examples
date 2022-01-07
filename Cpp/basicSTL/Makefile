programs=tmp example_tuple example_unordered_map example_sort example_list example_vector example_array example_forward_list example_queue example_map
all:$(programs)

CXXFLAGS=-g -O0

tmp:tmp.cpp
	g++ -o tmp tmp.cpp

example_tuple:example_tuple.cpp
	g++ -o example_tuple example_tuple.cpp

example_unordered_map:example_unordered_map.cpp
	g++ -o example_unordered_map example_unordered_map.cpp

example_sort:example_sort.cpp
	g++ -o example_sort example_sort.cpp

example_list:example_list.cpp
	g++ -o example_list example_list.cpp

example_forward_list:example_forward_list.cpp
	g++ -o example_forward_list example_forward_list.cpp

example_vector:example_vector.cpp
	g++ -o example_vector example_vector.cpp

example_array:example_array.cpp
	g++ -o example_array example_array.cpp -std=c++11

example_map:example_map.cpp
	g++ $(CXXFLAGS) -o example_map example_map.cpp -std=c++11

example_queue:example_queue.cpp
	g++ $(CXXFLAGS) -o example_queue example_queue.cpp -std=c++11

clean:
	rm $(programs)
