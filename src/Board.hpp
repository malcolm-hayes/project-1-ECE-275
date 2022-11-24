
#ifndef HAVEYOUSEENTHSISNAIL_BOARD_
#define HAVEYOUSEENTHSISNAIL_BOARD_


#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
#include <fstream>

#include "Cell.hpp"
#include "Gary.hpp"


class Board{
public:
    Gary* G;
    
    typedef std::vector<Cell> row;
    typedef std::vector<row> grid; // grid adds more rows
    
    grid tempBoard;
    
    std::ofstream outputFile;
    std::string output_file;
    
    Board(unsigned int N){
        
        if(N % 2 == 0){
            std::cout << "Board dimension must be an odd number!! Got " << N << " and adding 1 to equal " << N+1 << std::endl;
            N = N + 1;
        }
        
        G = new Gary(N);
        
        tempBoard.resize(N);
            
        for(unsigned int i = 0; i < N; i++){
            tempBoard.at(i).resize(N);
        }
    }

    void setOutputFilename(std::string str){

        outputFile.open(str);
        
            if(!outputFile.is_open()){
                std::cout << "File is not open";
                str.clear();
            }
    }

 
    std::string print_board(){
        std::stringstream str;
    

       str << "[Gary Location] {" << std::get<0>(G->get_location())<< ", " <<std::get<1>(G->get_location())<< "} [Gary Orientation] " << G->current_orientation();
            

        for(unsigned int i = 0; i < tempBoard.size(); i++){ // [Row 0]
            str << " [Row "<<i<<"]";
            row* temp1 = &(tempBoard.at(i));

            for(unsigned int j=0; j < tempBoard.size(); j++){
                Cell* temp2 = &(temp1->at(j));
                str << " ";
                if (temp2->get_color() == 0) {
                    str << "0";
                }
                else {
                    str << "1";
                }

            }
        }
        str << "\n";
        
        if(!outputFile.is_open()){
            std::cout << str.str();
        }
        else{
            outputFile << str.str();
        }
        return str.str();
    }
   

    Cell* get_loc_ptr(){
    
        unsigned int a = std::get<0>(G->get_location());
        unsigned int b = std::get<1>(G->get_location());
        
        return &(tempBoard.at(a).at(b));

    }
    
    void move_gary(unsigned int steps){
        
        for(unsigned int j = 0; j < steps + 1; j++){
            print_board();
            G->move(get_loc_ptr());
        }
    }
private:

};

#endif
