#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "translateHUB.hpp"
std::ofstream fileOUT;
std::ofstream fileJST;
std::string fileJ, fileD, fileR;

void readFile()
{
  fileOUT.open("storeDART.txt");
  std::string fileSP;
  std::ifstream fileI;
  fileI.open(fileD.c_str());
  while(std::getline(fileI, fileSP))
  {
    std::ostringstream fileO;
    fileO<<""<<fileSP<<"";
    std::string fileOS=fileO.str();
    int fileOSS=fileOS.length();
    for(int y=0; y<=fileOSS; y++)
    {
      int verifyA=2;
      if(fileOS[y]==(' '))
      {
        verifyA=1;
      }
      if(verifyA==2)
      {
      fileOUT<<""<<fileOS[y]<<"";
      }
    }
    fileOUT<<"\n"; 
  }
  fileI.close();
  std::string entireSI;
  int verifyVoidA=2;
  std::ifstream entireF;
  entireF.open(fileD.c_str());
  while(std::getline(entireF, entireSI))
  {
  std::ostringstream entireSIO;
  std::string entireIS;
  entireSIO<<""<<entireSI<<"";
  entireIS=entireSIO.str();
  int voidMainIS=entireIS.length();
  for(int voidMainI=0; voidMainI<=voidMainIS; voidMainI++)
    {
      if(entireIS[voidMainI]==('v') && entireIS[voidMainI+1]==('o') && entireIS[voidMainI+2]==('i') && entireIS[voidMainI+3]==('d') && 
entireIS[voidMainI+4]==(' ') && entireIS[voidMainI+5]==('m') && entireIS[voidMainI+6]==('a') && entireIS[voidMainI+7]==('i') && entireIS[voidMainI+8]==('n'))
      {
        verifyVoidA=1;
      }
    }
  }
  entireF.close();
  if(verifyVoidA==2)
  {
    std::cout<<"ERROR: Expected To Find: main()"<<std::endl;
    exit(0);
  }
  fileJST.open(fileJ.c_str());
  std::ifstream changeA;
  changeA.open(fileD.c_str());
  while(std::getline(changeA, fileR))
  {
    translateHUB();
  }
  changeA.close();
  fileJST.close();
}

//cli
int main()
{
  std::cout<<"DART2GDEVELOP"<<std::endl;
  std::cout<<"Enter A Dart File: ";
  std::getline(std::cin, fileD);
  std::cout<<"Enter A JavaScript File: ";
  std::getline(std::cin, fileJ);
  readFile();
  return 0;
}