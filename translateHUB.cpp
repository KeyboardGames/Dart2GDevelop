#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "translateHUB.hpp"
#include "variable.hpp"
int workA=1;

void translateHUB();

void translateHUB()
{
  variableRead();
  variableOperation();
  filterDart();
  alternativeVariable();
  fileOUT.close();
}