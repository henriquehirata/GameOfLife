/* 
 * File:   Model.cpp
 * Author: Igor
 * 
 * Created on February 19, 2013, 2:30 PM
 */

#include "Model.h"


Cell::Cell(){ 
  state = ALIVE;
}

void Cell::kill() {
  state = DEAD;
}

void Cell::revive() {
  state = ALIVE;
}

bool Cell::isAlive() {
  return state == ALIVE;
}


Model::Model() {
 
  width = cols;
  height = rows;
  
  cells = new Cell*[cols*rows];
    
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cells[i*width + j] = new Cell();
    }
  }
  
  statistics = new Statistics();
}


