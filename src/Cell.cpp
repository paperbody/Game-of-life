#include <Cell.h>

Cell::Cell(){
    alive =false;
}

bool Cell::AliveOrDead() const{
    return alive;

}

void Cell::Dead(){

    alive = false;

}

void Cell::Alive(){
    alive = true;

}
/*
int neighborCount(){
    int count = 0;
    //Left top
    //if( ){
        
    //}
    //Left Mid
    //if()
    //Left Bot

    //Mid top
    //Mid Mid
    //Mid Bot

    //Right top
    //Right Mid
    //Right Bot
    return count;
}
*/

