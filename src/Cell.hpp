#ifndef HAVEYOUSEENTHSISNAIL_CELL_
#define HAVEYOUSEENTHSISNAIL_CELL_

#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
#include <fstream>

class Cell{
public:
    enum Color { white, black };
    Cell() = default;
    
    Color cellcolor = white;  
    
    void next_color(){
        if(cellcolor == white){
            cellcolor = black;
        }
        else{
            cellcolor = white;
        }
    }
    Color get_color(){
        return cellcolor;
    }
    
    
    std::string current_color(){
    std::string col_curr;

        if(cellcolor == white){
            col_curr.assign("white");
        }
            
        else if(cellcolor == black){
            col_curr.assign("black");

        }

        return col_curr;
    }
    
private:
    
};



#endif
