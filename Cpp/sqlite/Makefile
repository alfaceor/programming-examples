all:insertTable createTable example

insertTable:insertTable.cpp
	g++ -o insertTable insertTable.cpp -lsqlite3

createTable:createTable.cpp
	g++ -o createTable createTable.cpp -lsqlite3

example:example.cpp
	g++ -o example example.cpp -lsqlite3

clean:
	rm example createTable
