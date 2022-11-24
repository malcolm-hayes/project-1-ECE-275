#ifndef HAVEYOUSEENTHSISNAIL_GARY_
#define HAVEYOUSEENTHSISNAIL_GARY_

#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#include "Cell.hpp"

enum class orientation { up, right, down, left };

class Gary{
public:
    
    orientation orient = orientation::up;
        
    unsigned int boardSize;
    Gary (unsigned int N): boardSize(N){
        unsigned int center;
        center = (N - 1) / 2;
        location = std::make_tuple(center, center);
    }
    
    typedef std::tuple<unsigned int, unsigned int> loc;
    loc location;
        
    loc get_location(){
        return location;
    
    }
    
    
void move(Cell* cellcolor){ 
    if(cellcolor->get_color() == Cell::white){
        if(orient == orientation::up){
            orient = orientation::right;
        }
        else if(orient == orientation::right){
            orient = orientation::down;
        }
        else if(orient == orientation::down){
            orient = orientation::left;
        }
        else if(orient == orientation::left){
            orient = orientation::up;
        }
    }
        
    else if(cellcolor->get_color() == Cell::black){
        if(orient == orientation::up){
            orient = orientation::left;
        }
        else if(orient == orientation::left){
            orient = orientation::down;
        }
        else if(orient == orientation::down){
            orient = orientation::right;
        }
        else if(orient == orientation::right){
            orient = orientation::up;
        }
    }
        
    cellcolor->next_color(); 
    update_loc();
}
 
    
void update_loc(){
    unsigned int row = std::get<0>(location);
    unsigned int col = std::get<1>(location);
    
    if(orient == orientation::up){
        row = row - 1;
        col = col;
    }
    else if(orient == orientation::right){
        row = row;
        col = col + 1;
    }
    else if(orient == orientation::down){
        row = row + 1;
        col = col;
    }
    else if(orient == orientation::left){
        row = row;
        col = col - 1;
    }
    
    if (col == (unsigned int) - 1){
        col = boardSize - 1;
    }
    else if (row == (unsigned int) - 1){
        row = boardSize - 1;
    }
    if (col > boardSize - 1){
        col = 0;
    }
    else if (row > boardSize - 1){
        row = 0;
    }
    std::get<0>(location) = row;
    std::get<1>(location) = col;

}
    
    orientation get_orientation(){
        orientation ori;
        
        if(orient == orientation::up){
           // ori.assign("up");
            ori = orientation::up;
        }
            
        else if(orient == orientation::right){
            //ori.assign("right");
            ori = orientation::right;
        }
        else if(orient == orientation::down){
           // ori.assign("down");
            ori = orientation::down;
        }
        else if(orient == orientation::left){
           // ori.assign("left");
            ori = orientation::left;
        }
        //return ori;
        return ori;
    }
    
        std::string current_orientation() {
        std::string ori;

        if (orient == orientation::up) {
            ori.assign("up");
        }

        else if (orient == orientation::right) {
            ori.assign("right");
        }
        else if (orient == orientation::down) {
             ori.assign("down");

        }
        else if (orient == orientation::left) {
            ori.assign("left");

        }
        return ori;
    }
    
};

#endif
