/* 
 * File:   Model.h
 * Author: Igor
 *
 * Created on February 19, 2013, 2:30 PM
 */

#ifndef MODEL_H
#define	MODEL_H

#include "Statistics.h"

enum EnumState {DEAD, ALIVE}; 
 
 const int rows = 10;
 const int cols = 10;
 
/*! Cell class definition
 *
 *  The cell class represents a Cell 
 *  in the game of life. Each cell has a 
 *  state and methods for killing or 
 *  reviving.   
 */
class Cell {
 private:
  EnumState state;
 public:
  Cell();
  /*! Changes the state of a cell to DEAD */
  void kill();

  /*! Changes the state of a cell to ALIVE */
  void revive();

  /*! Verifies whether a cell is alive or not */
  bool isAlive();
};

class Model {
public:
    Model();
    int width, height;
    Statistics* statistics;
    Cell** cells;
    
    /*! Access method to the number of columns */
  int getWidth() const { return width; }

  /*! Access method to the number of rows */
  int getHeight() const { return height; }
  
  int getSurvivors() const { return statistics->getSurvivors(); }
  int getKilled() const { return statistics->getKilled(); }
private:
    
    

};

#endif	/* MODEL_H */

