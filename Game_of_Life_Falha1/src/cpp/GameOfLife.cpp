#include <iostream>
#include <list>

using namespace std;

#include "../include/GameOfLife.h"




GameOfLife::GameOfLife() {
      
  killEnvironment();
  
}

void GameOfLife::killEnvironment() {
  for(int i = 0; i < model.height; i++) {
    for(int j = 0; j < model.width; j++) {
      model.cells[i*model.width + j]->kill();
    }
  }
}

int GameOfLife::aliveCells() {
  int r = 0;

  for(int i = 0; i < model.height; i++) {
    for(int j = 0; j < model.width; j++) {
      if(model.cells[i*model.width + j]->isAlive()) {
	r++;
      }
    }
  }
  return r;
}

int GameOfLife::aliveNeighborCells(int w, int h) {
  if(w < 0 || w >= model.width) return 0;
  if(h < 0 || h >= model.height) return 0;
  
  int r = 0;

  for(int i = h-1; i <= h + 1; i++) {
    for(int j = w-1; j <= w+1; j++) {
      if((! ((i == h) && (j == w))) && isCellAlive(j,i)) {
	r++;
      }
    }
  }
  return r;
}

bool GameOfLife::isCellAlive(int w, int h) {
  if(w < 0 || w >= model.width) return false;
  if(h < 0 || h >= model.height) return false;

  return  model.cells[h * model.width + w]->isAlive();
}


void GameOfLife::makeCellAlive(int w, int h) {
  if(w < 0 || w >= model.width) return;
  if(h < 0 || h >= model.height) return;

  Cell* c = model.cells[h * model.width + w];

  if(!c->isAlive()) {
    model.cells[h * model.width + w]->revive();
  }

  model.statistics->survive();
}


void GameOfLife::makeCellDead(int w, int h) {
  if(w < 0 || w >= model.width) return;
  if(h < 0 || h >= model.height) return;

  Cell* c = model.cells[h * model.width + w];

  if(c->isAlive()) {
    model.cells[h * model.width + w]->kill();
  }

  model.statistics->kill();
}

void GameOfLife::nextGeneration() {
  list<Cell*> mustRevive;
  list<Cell*> mustDie;

  for(int i = 0; i < model.height; i++) {
    for(int j = 0; j < model.width; j++) {
      if(shouldRevive(j,i)) {
      	mustRevive.push_back(model.cells[i*model.width+j]);
      }
      else if (shouldKill(j,i)) {
      	mustDie.push_back(model.cells[i*model.width+j]);
      }
    }
  }

  for (list<Cell*>::iterator it = mustRevive.begin(); it != mustRevive.end(); it++) {
    (*it)->revive();
    model.statistics->survive();
  }

  for (list<Cell*>::iterator it = mustDie.begin(); it != mustDie.end(); it++) {
    (*it)->kill();
     model.statistics->kill();
  }
}

 /* Usando o TM, deveriamos tornar shouldRevive e 
  * shouldKill abstratos.
  */ 

/*
 * Uma celula morta deve ressuscitar caso 
 * tenha tres celulas vizinhas vivas.

 */ 
bool GameOfLife::shouldRevive(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return ((!isCellAlive(w,h)) && (aliveNeighbors == 3));
}

/*
 * Uma celula viva deve morrer caso 
 * tenha duas ou tres celulas vizinhas vivas.
 */ 
bool GameOfLife::shouldKill(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return (isCellAlive(w,h) && (aliveNeighbors != 2 && aliveNeighbors != 3));
}
