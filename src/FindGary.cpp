#include "Gary.hpp"
#include "Cell.hpp"
#include "Board.hpp"

#include <iostream>

int main(int argc, char** argv){ //can accept 3 args if wanted
    
    unsigned int boardSize = atoi(*(argv+1));
    unsigned int numberSteps = atoi(*(argv+2));
 
    Board B(boardSize);
    if (argc == 4){
        std::string outputFilename = (*(argv+3));
        B.setOutputFilename(outputFilename);
    }
    
    B.move_gary(numberSteps);

    return 0;
}
