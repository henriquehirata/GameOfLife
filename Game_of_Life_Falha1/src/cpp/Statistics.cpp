#include <iostream>

using namespace std;

#include "../include/Statistics.h"

void Statistics::survive() {
  ++survivors;
}

void Statistics::kill() {
  ++killed;
} 

int Statistics::getSurvivors(){
    return survivors;
}

int Statistics::getKilled(){
    return killed;
}