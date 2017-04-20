/* puzzleFactory.h
By Bisrat Belayneh
March 8, 2017
puzzleFactory.h contains the class definition for vitrual method createPuzzle().
*/
#pragma once
#include<iostream>
#include"puzzle.h"

using namespace std;

/*A PuzzleFactory is an abstract factory design pattern for producing puzzles.
A PuzzleFactory is provided at construction time with a Reproduction object that
it uses to create new instances of Puzzle*/

class puzzleFactory
{

public:
	//---------------------------------------------------------------------------------
	//createpuzzle
	//when provided at construction time with a sudokuOffspring object,
	//it uses this object to create new instances of sudoku 
	//takes nothing and returns a puzzle 
	virtual puzzle& createPuzzle() = 0;

};