#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{
private:


	//std::vector<std::vector<Cell>> Board;





public:
	GameOfLife();
	int row = 17;
	int column = 17; 
	void start();
	void stop();
	void advance();
	std::vector<std::vector<Cell>> Board;

	int neighborCount(std::vector<std::vector<Cell>>, int i, int j);
	ucm::json getBoard()const;

};

#endif
