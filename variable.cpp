#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "variable.hpp"
#include "translateHUB.hpp"

void variableRead();
void variableOperation();
void filterDart();
void alternativeVariable();

//declare variable
void variableRead()
{
  std::string nameV;
  std::string totalV;
  if(fileR[0]==('v') && fileR[1]==('a') && fileR[2]==('r') && fileR[3]!=('='))
  {
    int fileRI=fileR.length();
    std::ostringstream keepQ;
    std::ostringstream keepO;
    for(int i=0; i<=fileRI; i++)
    {
      if(fileR[i]==('='))
      {
        for(int t=4; t<=i-2; t++)
        {
          keepO<<fileR[t];
        }
        for(int q=i+1; q<=fileRI; q++)
        {
          keepQ<<fileR[q];
        }
        nameV=keepO.str();
        totalV=keepQ.str();
        fileJST<<"var "<<nameV<<" ="<<totalV<<"\n";
      }
    }
  }
}

//operator: anything that sets a variable
//list of operators:
// ' '
// " "
// +
// -
// *
// /
//find operators by finding an equal sign
void variableOperation()
{
  int rethinkV=2;
  int sizeOp=fileR.length();
  std::ostringstream scanOpO;
  std::string scanOpS;
  for(int scannerT=0; scannerT<=sizeOp; scannerT++)
  {
    if(fileR[0]!=('v') && fileR[1]!=('a') && fileR[2]!=('r') && fileR[scannerT]==('='))
    {
      for(int scannerY=scannerT; scannerY<=sizeOp; scannerY++)
      {

        //verify that it is not a runtime event
        for(int scannerBI=0; scannerBI<=sizeOp; scannerBI++)
        {
          if(fileR[scannerBI]==('r') && fileR[scannerBI+1]==('u') && fileR[scannerBI+2]==('n') && fileR[scannerBI+3]==('t') && fileR[scannerBI+4]==('i') && fileR[scannerBI+5]==('m') && fileR[scannerBI+6]==('e'))
          {
            workA=2;
          }
        }
        std::ostringstream coverCharO;
        coverCharO<<""<<fileR[scannerY];
        std::string coverChar=coverCharO.str();
       //string
        if(coverChar==("'") && rethinkV==2 && workA==1 || fileR[scannerY]==('"') && rethinkV==2 && workA==1)
        {
          for(int coverCharI=0; coverCharI<=sizeOp; coverCharI++)
          {
          int verifyCCI=2;
          if(fileR[coverCharI]==('='))
          {
            verifyCCI=1;
          }
          if(verifyCCI==2)
          {
          fileJST<<""<<fileR[coverCharI];
          }
          if(verifyCCI==1)
          {
            fileJST<<".setString(";
            std::ostringstream undoChOA;
            std::ostringstream undoChOB;
            std::string undoCHA;
            std::string undoCHB;
            for(int undoChI=sizeOp; undoChI>=coverCharI+2; undoChI--)
            {
              undoChOA<<""<<fileR[undoChI];
            }
            undoCHA=undoChOA.str();
            int undoChSI=undoCHA.length();
            for(int undoChII=undoChSI-1; undoChII>=1; undoChII--)
            {
              undoChOB<<""<<undoCHA[undoChII];
            }
            undoCHB=undoChOB.str();
            fileJST<<""<<undoCHB<<"";
            coverCharI=sizeOp+5;
          }
          }
          workA=2;
          fileJST<<"\n";
          rethinkV=1;
        }
        //not string
        if(fileR[scannerY]==('+') && workA==1 || fileR[scannerY]==('-') && workA==1 || fileR[scannerY]==('*') && workA==1 || fileR[scannerY]==('/') && workA==1 && fileR[scannerY+1]!=('/') && workA==1)
        {
          for(int ksize=0; ksize<=sizeOp; ksize++)
          {
            int verifyTY=2;
            if(fileR[ksize]==(' ') && fileR[ksize+1]==('='))
            {
              verifyTY=1;
            }
            if(verifyTY==2)
            {
            scanOpO<<""<<fileR[ksize]<<"";
            }
            if(verifyTY==1)
            {
              std::ostringstream undoROA;
              std::ostringstream undoROB;
              std::string undoRA;
              std::string undoRB;
              scanOpO<<".setNumber(";
              for(int osize=sizeOp-1; osize>=ksize+1; osize--)
              {
              undoROA<<""<<fileR[osize];
              }
              undoRA=undoROA.str();
              int undoRAS=undoRA.length();
              for(int reverUI=undoRAS-3; reverUI>=1; reverUI--)
              {
              undoROB<<""<<undoRA[reverUI]<<"";
              }
              undoRB=undoROB.str();
              scanOpO<<""<<undoRB<<");";
              ksize=sizeOp+5;
            }
          }
          scanOpS=scanOpO.str();
          fileJST<<""<<scanOpS<<"\n";
          workA=2;
        }
      }
    }
  }
}

//filter configuration
void filterDart()
{
  int filterDIS=fileR.length();
  std::cout<<""<<fileR<<""<<std::endl;
  for(int filterDI=0; filterDI<=filterDIS; filterDI++)
    {

      if(fileR[filterDI]==('{') || fileR[filterDI]==('}'))
      {
        workA=2;
      }
      
      if(fileR[filterDI]==('i') && fileR[filterDI+1]==('m') && fileR[filterDI+2]==('p') && fileR[filterDI+3]==('o') && fileR[filterDI+4]==('r') && fileR[filterDI+5]==('t'))
      {
        workA=2;
      }

      if(fileR[filterDI]==('v') && fileR[filterDI+1]==('o') && fileR[filterDI+2]==('i') && fileR[filterDI+3]==('d'))
      {
        workA=2;
      }
    }
}

//filter execution
void alternativeVariable()
{
  if(workA==1)
  {
    fileJST<<""<<fileR<<"\n";
  }
  workA=1;
}