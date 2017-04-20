/* sudokuFactory.cpp
By Bisrat Belayneh
Mar 8,2017
sudokuFactory.cpp contains the implementations of the functions defined in sudokuFactory.h
*/
#include <iostream>
#include"sudokuOffspring.h"
#include "sudokuFactory.h"
#include "puzzle.h"

using namespace std;
//createpuzzle
//when provided at construction time with a sudokuOffspring object,
//it uses this object to create new instances of sudoku 
//takes nothing and returns a puzzle 
puzzle& sudokuFactory::createPuzzle()
{
	sudoku* s1 = new sudoku();     // allcate memory for a soduku puzzle
	 
	list.push_back(s1);           //add it to the list
	 
	return *s1;
}
// destructor 
//frees the memory used by list by deleting the contents of the list 

sudokuFactory:: ~sudokuFactory()   
{

	for (int i = 0; i < list.size(); i++)   // delete all the sudoku puzzles and free memory
	{
		delete list[i];
		list[i] = NULL;                        // set them to null
	}
}