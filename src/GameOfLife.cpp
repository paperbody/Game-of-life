#include <GameOfLife.h>
#include <iostream>

//Global variable

//std::vector<std::vector<Cell>> Board;
GameOfLife::GameOfLife(){

	
	Cell myCell;

	for(int i = 0; i < row; i++){
			std::vector<Cell> hi;
		for(int j = 0; j < column; j++){
				hi.push_back(myCell);
		}
		Board.push_back(hi);
	}
//Blinker
/*
Board[2][2].Alive();
Board[2][1].Alive();
Board[2][3].Alive();
*/

//toad

// Board[2][2].Alive();
// Board[2][3].Alive();
// Board[2][4].Alive();
// Board[3][1].Alive();
// Board[3][2].Alive();
// Board[3][3].Alive();

//pulsar
//TL
 Board[2][4].Alive();
 Board[2][5].Alive();
 Board[2][6].Alive();

 Board[4][2].Alive();
 Board[5][2].Alive();
 Board[6][2].Alive();

 Board[7][4].Alive();
 Board[7][5].Alive();
 Board[7][6].Alive();

 Board[4][7].Alive();
 Board[5][7].Alive();
 Board[6][7].Alive();
//DL
 Board[9][4].Alive();
 Board[9][5].Alive();
 Board[9][6].Alive();

 Board[10][2].Alive();
 Board[11][2].Alive();
 Board[12][2].Alive();

 Board[14][4].Alive();
 Board[14][5].Alive();
 Board[14][6].Alive();

 Board[10][7].Alive();
 Board[11][7].Alive();
 Board[12][7].Alive();
//TR
 Board[4][9].Alive();
 Board[5][9].Alive();
 Board[6][9].Alive();

 Board[2][10].Alive();
 Board[2][11].Alive();
 Board[2][12].Alive();

 Board[4][14].Alive();
 Board[5][14].Alive();
 Board[6][14].Alive();

 Board[7][10].Alive();
 Board[7][11].Alive();
 Board[7][12].Alive();
//DR
 Board[10][9].Alive();
 Board[11][9].Alive();
 Board[12][9].Alive();

 Board[9][10].Alive();
 Board[9][11].Alive();
 Board[9][12].Alive();

 Board[10][14].Alive();
 Board[11][14].Alive();
 Board[12][14].Alive();

 Board[14][10].Alive();
 Board[14][11].Alive();
 Board[14][12].Alive();

//beacon
//  Board[8][9].Alive();
//  Board[9][9].Alive();
//  Board[9][8].Alive();

//  Board[7][6].Alive();
//  Board[6][6].Alive();
//  Board[6][7].Alive();

//spaceship
// Board[9][9].Alive();
//  Board[9][8].Alive();

//  Board[7][6].Alive();
//  Board[6][6].Alive();
//  Board[6][7].Alive();

}



void GameOfLife::start(){

}

void GameOfLife::stop(){
	
}

void GameOfLife::advance(){
	int neighbor = 0;
	std::vector<int> posI;
	std::vector<int> posJ;
	std::vector<int> posDI;
	std::vector<int> posDJ;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			//std::cout<<"test1"<<std::endl;
			neighbor = neighborCount(Board, i, j); 
			//std::cout<<"testEnd"<<std::endl;
			
			if(neighbor == 3 && Board[i][j].AliveOrDead() == false){
				//Board[i][j].Alive();
				posI.push_back(i);
				posJ.push_back(j);
			}
			else if(Board[i][j].AliveOrDead() == true && (neighbor == 3 || neighbor == 2) ){
				//Board[i][j].Alive();
				posI.push_back(i);
				posJ.push_back(j);
			}
			else{
				//Board[i][j].Dead();
				posDI.push_back(i);
				posDJ.push_back(j);
			}
			
		}

	}
	for(int i = 0; i < posI.size(); i++){
				Board[posI[i]][posJ[i]].Alive();
	}

	for(int i = 0; i < posDI.size(); i++){
				Board[posDI[i]][posDJ[i]].Dead();
	}

}

int GameOfLife::neighborCount(std::vector<std::vector<Cell>>, int i, int j){
	
    int count = 0;
	//for (int k = 0; k < 3; k++){
    //Left top
			//std::cout<<i<<" "<<j<<std::endl;
    	if(i != 0 && j != 0 && Board[i-1][j-1].AliveOrDead() == true){
			count++;
			//std::cout<<"Left Top "<<std::endl;
    	}
    //Left Mid
		if(j != 0 && Board[i][j-1].AliveOrDead() == true){
			count++;
			//std::cout<<"Left Mid "<<std::endl;
    	}
    //Left Bot
		if( i != Board.size()-1 && j != 0 && Board[i+1][j-1].AliveOrDead() == true){
			count++;
			//std::cout<<"Left Bot "<<std::endl;
    	}
    //Mid top
		if(i != 0 && Board[i-1][j].AliveOrDead() == true){
			count++;
			//std::cout<<"Mid Top "<<std::endl;
    	}
		
    //Mid Mid
		//if(Board[i][j].AliveOrDead() == true){
		//	count++;
		//	std::cout<<"test 6 "<<std::endl;
    	//}
			//std::cout<<"past half "<<std::endl;		
    //Mid Bot
		if(i != Board.size()-1 && Board[i+1][j].AliveOrDead() == true ){
			count++;
			//std::cout<<"Mid Bot "<<std::endl;
    	}
		//std::cout<<"past half 1"<<std::endl;	
    //Right top
		if(i !=0 && j != Board.size()-1 && Board[i-1][j+1].AliveOrDead() == true ){
			count++;
			//std::cout<<"Right Top "<<std::endl;
    	}
		//std::cout<<"past half 2"<<std::endl;	
    //Right Mid
		if(j != Board.size()-1 && Board[i][j+1].AliveOrDead() == true){
			count++;
			//std::cout<<"Right Mid "<<std::endl;
    	}
		//std::cout<<"past half 3"<<std::endl;	
    //Right Bot
		if(i != Board.size()-1 && j != Board.size()-1 && Board[i+1][j+1].AliveOrDead() == true ){
			count++;
			//std::cout<<"Right Bot "<<std::endl;
    	}
		//std::cout<<"END "<<std::endl;
	//}
    return count;


}

ucm::json GameOfLife::getBoard() const {
	ucm::json result;
	
	for(int i = 0; i<row;i++){
	ucm::json temp;
		for(int j =0; j< column;j++){
			temp.push_back((Board[i][j].AliveOrDead()));
		}
	result.push_back(temp);
	}
	return result;
}


