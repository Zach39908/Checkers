all:
	g++ -g main.cpp board.cpp menu.cpp player.cpp -Wall -Wpedantic -Wextra

clean:
	rm a.out