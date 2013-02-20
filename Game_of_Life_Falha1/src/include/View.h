/* 
 * File:   View.h
 * Author: Igor
 *
 * Created on February 18, 2013, 2:23 PM
 */

#ifndef VIEW_H
#define	VIEW_H

#include "../include/GameOfLife.h"

#include <string>
using namespace std;

#include "GameOfLife.h"


const string line  = "+-----+";  
const string dead  = "|     |";  
const string alive = "|  o  |";



/*! Controller class definition 
 *
 * This class deals with the user inputs, 
 * and based on the user actions it triggers 
 * the proper functionality. 
 *
 * Besides that, its interface is really simple. Only 
 * one public method is available, which just start a game. 
 */
class View{
 private:
  GameOfLife game;
  void printsatisticsurvive();   
  void printsatistickill();
  void update(GameOfLife& game);
  void printLine();   
  void printLineIds();   
  void clearScreen();   
  void revive();
  void nextGeneration();
 public:
  /*! Controller constructor, taking a game instance (model) and a game board (view) */
  
  
  /*! Start the execution of the game */
  void startGame();

};

#endif	/* VIEW_H */

