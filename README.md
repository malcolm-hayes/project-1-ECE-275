# ECE 275 Project 1: Have you seen this snail?? 
> Can You help Gary get home?? 
 
 [![Gary Come Home](https://img.youtube.com/vi/Ju8Nz2cmCp0/0.jpg)](https://www.youtube.com/watch?v=Ju8Nz2cmCp0)
 
 Gary the snail is lost and scared in Bikini Bottom. Can you help Gary get home?? 

 
## Project 1 Background: 
Project 1 will see students implement a solution to "Langton's Ant", a cellular automata existing on a 2 Dimensional *N* by *N* grid where each grid cell is colored white or black and the "ant" cell can be described as one of eight states (cell color + ant orientation). 

### Rules of Langton's Ant
*Note that the rules are slightly modified for our purposes*

Initialize an *N* by *N* square grid (note that *N* must be an odd integer) of `Cell` types that are either white or black. Start the "Ant" (or Gary the snail in our case) at the center of the grid. Start Gary in an "up" orientation. Perform *K* steps where each step follows a simple rule:

1. If Gary is on a white square turn 90 deg clockwise, flip the color of the square, and move forward one unit
2. If Gary is on a black square turn 90 deg counterclockwise, flip the color of the square, and move forward one unit. 

### Links/References to Langton's Ant
Below you will find links for more information on Langton's Ant. Note that there are many solutions to this problem available on the internet but we will design to a specific set of criteria and it will be impossible to copy-paste a solution. 

* [Langton's Ant Wikipedia](https://en.wikipedia.org/wiki/Langton's_ant)
* [Langton's Ant WolframMathworld](https://mathworld.wolfram.com/LangtonsAnt.html)
* [Coding Challenge Video: Langton's Ant (in Python)](https://www.youtube.com/watch?v=G1EgjgMo48U)

Below you will find examples of Langton's Ant in various programming languages. 

* [Langton's Ant implementation in Python](https://www.geeksforgeeks.org/python-langtons-ant/)
* [Langton's Ant implementation in C++](https://github.com/jeinhorn787/Langtons-Ant)
* [Langton's Ant Rosetta Code](https://rosettacode.org/wiki/Langton%27s_ant) 
* [Langton's Ant solution in C++](https://euler.stephan-brumme.com/349/)
* [Langton's Ant C++ solution in REPL](https://repl.it/@Ronald_MaxMax/Langtons-Ant#main.cpp)

The above links might be helpful conceptually but do *not* implement Langton's Ant in accordance with the design guidelines for Project 1. 

## Program Composition Overview:
`Gary` the snail exists on a `Board` which consists of an *N* by *N* grid of `Cell`s. Therefore you will construct three classes: `Board`, `Gary`, and `Cell`. The `Board` class drives the program in that it parameterizes the `Gary` class and issues *K* commands for `Gary` to move. On each step, `Gary` moves based on the `Cell` he currently occupies (passed by the `Board` class). `Gary` is responsible for the `Board`'s wrapping boundary conditions. 

We will track the overall state of the program (all Cell colors and Gary's orientation) via formatted output either to standard output or to a file. Note that this output may be used to create a visualization if desired. 

## Board Class:
The `Board` class has the following requirements:

1. The Board class **shall** be constructed given an unsigned integer parameter that defines the number of rows and columns, i.e., 'N' in the N by N board. Note that N must be odd. If N is given as even, students **shall** display a message (*only* to `std::cout` and not to any file argument!) stating "Board dimension must be an odd number!! Got {N} and adding 1 to equal {N+1}" (note that parameters within { } must be printed as their values and the { } should not be printed) and **shall** add 1 to N to satisfy the requirement that N must be odd. Note that this message must be printed only to the console, i.e., should not be printed to the output file. 
2. Gary **shall** move around the board when the `Board::move_gary(unsigned int steps)` function is called. Each step **shall** be one step of Langton's ant as defined above, i.e., change Gary's orientation based on the Cell input, change the cell color, and move Gary forward one unit. The board class **shall** print the state of the board at every step. See the below example with a boardSize input of 5 for 10 steps:

	```
	[Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
	[Gary Location] {2, 3} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
	[Gary Location] {3, 3} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
	[Gary Location] {3, 2} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {1, 1} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {1, 2} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 1 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {2, 2} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	[Gary Location] {3, 1} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
	```
	the format is given by `[Gary Location] {(row), (col)} (orientation) [Row 0] (col 0 color) (col 1 color) ...` `(col N-1 color) [Row 1] ... [Row (N-1)] ... (col N-1 color)` where values within ( ) are to be filled in with program values. `(col i color)` *shall* be either "0" for "white" or "1" for "black". This output will either be to standard output, i.e., `std::cout`, if a filename command line argument is not provided or will be printed to the filename given in the argument (students should use the [`ofstream`](http://www.cplusplus.com/reference/fstream/ofstream/) object for file output. Note that C's [`fprintf`](http://www.cplusplus.com/reference/cstdio/fprintf/) will also be okay). The filename *shall* be set with the `void Board::setOutputFilename(std::string)` member function. 

Students are free to implement the remaining functionality of the `Board` class as desired. The class should store a representation of the actual grid of cells which define the environment for Langon's ant, i.e., the Cell class (Hint: I utilized a vector of vectors where each element of the outer vector stores a "row" or the grid represented by a vector of class Cell). The board class must also store a variable of type `Gary` that "walks" about the board. (More information on `Gary` is given below) At each step in the `Board::move_gary(unsigned int)` function the Board class must pass a pointer to the `Cell` that Gary currently occupies (via the `Gary::move(Cell*)` member function, so that Gary can alter his orientation, flip the color of that cell, i.e., call the `next_color` member function, and change his position, i.e., "walk" (find a tutorial for pointers to objects [here](https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_class.htm)). 

## Cell Class:
This class will be used to define the *N* by *N* board in the final solution (there will be *N* <sup>2</sup> `Cell` objects which define the board). You are to program the `Cell` class according to the following design criteria:

1. The `Cell` class **shall** define a public unscoped enumeration member type `Color`, i.e., `Cell::Color` where the enumeration is declared within the class scope, with values `white` and `black`. This enumeration type is used to determine the "color" of the `Cell` and therefore how `Gary` change's his orientation. 
2. The `Cell` class **shall** be constructed using the [default constructor](https://en.cppreference.com/w/cpp/language/default_constructor), i.e., will not accept any arguments. The constructor **shall** set `color` to `white` upon construction. 
3. The `Cell` class **shall** contain a public member function named `next_color` to toggle the `Color`-type member. I.e., if the color is currently set to `white`, calling `next_color()` will change `color` to `black` and vise versa. The member function `next_color` will return type `void` and will accept no input parameters. 
4. The `Cell` class **shall** have a "getter" function to return the `Color` named `get_color()` which returns the Cell's current color. 


## Gary Class:
This class is the "Ant" in "Langton's Ant". Gary moves around the grid of cells and changes orientation based on the current cell he occupies. You are to program `Gary` to the following criteria:

1. `Gary` **shall** be constructed with a parameterized constructor accepting an unsigned integer input parameter representing the size of the board (denote here as BoardSize). Gary **shall** initialize his position to be the middle cell of the board, e.g., if the BoardSize is given as 5 Gary would be initialized at index (2,2). The `Gary` constructor should assume the parameter given is odd (and therefore you should make sure the parameter is odd before constructing the `Gary`-type member of `Board`)
2. `Gary` **shall** disallow default construction, i.e., `Gary() = delete;`. Note this means you will either have to allocate in the `Board` class via dynamic memory allocation or construct the `Gary`-type member via the `Board` constructor's member initialization list (the [ternary operator](https://www.cplusplus.com/articles/1AUq5Di1/) is how I constructed Gary in the member initialization list). 
3. `Gary` **shall** contain a public member function `get_location` which accepts no input and returns a [`std::tuple<unsigned int, unsigned int>`](https://www.cplusplus.com/reference/tuple/tuple/?kw=tuple) type where the 0<sup>th</sup> element denotes the row and the 1<sup>st</sup> element denotes the column Gary current occupies. 
4. `Gary` **shall** contain a public member function which returns type void and accepts a Cell pointer called `Gary::move(Cell*)` which **shall** (a) alter Gary's orientation based on the Cell's color (b) change the Cell's color (c) move Gary one unit forward in the new orientation. 
5. `Gary` **shall** wrap around the board when moving out of bounds, e.g., from the top row to the bottom row. See the last section for more information. 
6. `Gary` **shall** contain a public member function which returns type `orientation` which is a scoped enumeration type, i.e., `enum class orientation`, which has values (*in order*) "up, right, down, left". 

## Main Program:
The main function will be compiled into an executable named *FindGary*. The main function **shall** accept two (2) or three (3) command line arguments and will be called either as `./FindGary BoardSize Steps` or `./FindGary BoardSize Steps OutputFilename` where `BoardSize` and `Steps` will be unsigned integer values and `OutputFilename` will be a char array. The main program should construct a *Board* object, optionally **shall** set the output filename if given as a command line argument, and **shall** execute Gary's movement through Board's member function. 
#### Main Program's grading:
Student's main program will be used to generate output files. These output files will be compared to the solution output files and also to output files generated through instructor code, i.e., C++ code that will call the appropriate members of the Board class with the appropriate command line arguments. Students are free to implement their main program however they like but the output must be correct (according to the solution) and must match the output using student's Board class. Pseudocode for generating the output files from the instructor's end is shown below

``` 
#include "Cell.hpp"
#include "Board.hpp"
#include "Gary.hpp"

int main(int argc, char** argv){
	unsigned int boardSize = (from command line arguments)
	unsigned int numberSteps = (from command line arguments)
	std::string outputFilename = (from optional command line argument)
	
	Board B(boardSize);
	if (an output filename is given){
		B.setOutputFilename(outputFilename);
	}
	
	B.move_gary(numberSteps);

	return 0;
}
```
and student code must be capable of generating the correct output in the correct location when calling these member functions of the Board class. Please note that the only "pseudo" above is the parsing of command line arguments and the if statement - the member functions and construction of variable B of type Board is valid C++ syntax that is used during testing. 


## Testing Framework:

### Project Requirements Overview:
- The `Gary` class will be tested independently via another unit testing executable. This will test `Gary`'s functionality by constructing with various board sizes and performing random movement operations given random Cell inputs. The behavior will be tested against the expected behavior. 
	- Note if you define the symbol `GARY_TEST_VERBOSE` there will be verbose output from the tester when testing Gary's movement. 
- Project 1 will also be tested via output-comparison tests as in previous assignments
	- The output comparison will be run against output produces from your FindGary.cpp file and against a solution file which implements the correct `main` function (i.e., is the implemented pseudocode above)
- The `Cell` class will similarly be tested via a unit-test application for the functionality outlined above. 

### Grading:
Your score will be calculated from the tests passed. Find results in the job artifacts results.ini (open in a text editor) and the output comparison files. 

### A note on wrapping boundary conditions
Gary will never "walk" off the board but will rather have "wrapping boundary conditions" where, e.g., if Gary moves up from the top row he will be on the bottom row at the same column or if Gary moves left from the 0<sup>th</sup> column he will be then on the (N-1)<sup>th</sup> column (i.e., the rightmost column).

Please be aware that the board size will be strictly less than 2<sup>32</sup>. Why is this important? Because Gary's location on the board should be stored as an unsigned integer value (note that we cannot have a negative number of cells) and how will we tell if Gary's moved off the left or top side of the board? If Gary is positioned at index (0,i) and moves in the up orientation he must wrap around to index (N-1, i). Consider the following piece of code:

```
#include <iostream>

int main(void){
	unsigned int i = 3;
	for (int j = 3; j > -4; j--) {
		std::cout << "i = " << i << std::endl;
		i--; // Decriment i
	}	
	
	return 0;
}
```

what might happen to an unsigned integer when its assigned a value of -1? Remember that numbers are represented in binary and in the absence of a [sign bit](https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html) we experience over/underflow. So can we compare an unsigned integer with -1? What value is that really? Consider the following code snippet:

```
#include <iostream>
int main(void) {
	unsigned int i = -1;
	if (i == -1)
		std::cout << "i = " << i << std::endl;

	return 0;
}
```
This may be useful when considering how to "wrap" Gary's movement around the rows and columns. 
