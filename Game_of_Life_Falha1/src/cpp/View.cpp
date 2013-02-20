/* 
 * File:   View.cpp
 * Author: Igor
 * 
 * Created on February 18, 2013, 2:23 PM
 */

#include "../include/View.h"

#include <iostream>

using namespace std;



void View::startGame() {

  while(true) {
    cout << "Select one option: " << endl << endl;
    cout << "[1] Cell revive " << endl;
    cout << "[2] Next generation " << endl; 
    cout << "[3] Halt " << endl << endl;
    
    int menu = 0;
    
    cout << "Opcao: " ;
    
    cin >> menu;
    switch(menu) {
     case 1: revive(); break;
     case 2: nextGeneration(); break;
     case 3: return; 
     defaut: cout << endl << "Opcao invalida. Tente novamente." << endl << endl;
    } 
  }
}

void View::revive() {
  
  int cols = game.getWidth();
  int rows = game.getHeight();
  int c, r = 0;

  cout << "Enter the cell collumn number (0 -- " << (cols-1) << "): " ;
  cin >> c;

  if(c == -1) return;

  while(c >= cols) {
     cout << "Enter the cell collumn number (0 -- " << (cols-1) << "). Type -1 to exit: " ;
     cin >> c;

     if(c == -1) return;
  }

  cout << "Enter the cell row number (0 -- " << (rows-1) << "): " ;
  cin >> r;

  if(rows == -1) return;

   while(r >= rows) {
     cout << "Enter the cell row number (0 -- " << (rows-1) << "). Type -1 to exit: " ;
     cin >> r;

     if(c == -1) return;
   }
   
   game.makeCellAlive(c, r);
   printsatisticsurvive();
   update(game);
}

void View::nextGeneration() {
  
  game.nextGeneration();
  printsatisticsurvive();
  printsatistickill();
  update(game);
}

void View::clearScreen() {
  cout << ".\n";
  cout << ".\n";
  cout << ".\n";
  cout << ".\n";
  cout << ". Nova geracao \n";
  cout << ".\n";
  cout << ".\n";
  cout << ".\n";
  cout << ".\n";
  cout << ".\n";
}

void View::printLineIds() {
   for(int i = 0; i < cols; i++) {
     cout << "   " << i << "   " ;
   }
   cout << endl;
}

void View::printLine() {
  for(int i = 0; i < cols; i++) {
    cout << line;
  }
  cout << endl;
}

void View::update(GameOfLife& game) {
  clearScreen();

  printLineIds();
  printLine();

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      cout << (game.isCellAlive(j,i) ? alive : dead) ;
    }
    cout << "   " << i << endl;
    printLine();
  }
}

void View::printsatistickill(){
    cout << "Number of cells killed: " << game.getKilled()  << endl;
}

void View::printsatisticsurvive(){
     cout << "Number of cells revived: " << game.getSurvivors() << endl;
}