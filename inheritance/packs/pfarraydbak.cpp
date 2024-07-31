//This is the file pfarraydbak.cpp
//This is the implementation of the class PFArrayDBak
//The interface for the class PFArrayDBak is in the file pfarradbak.h

#include"pfarraydbak.h"
#include<iostream>
using std::cout;

PFArrayDBak::PFArrayDBak(): PFArrayD(), usedB(0)
{
  b = new double[capacity];
}

PFArrayDBak::PFArrayDBak(int capacityValue):PFArrayD(capacityValue),
  usedB(0)
{
  b = new double[capacity];
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak& oldObject)
  :PFArrayD(oldObject), usedB(0)
{
  b = new double[getCapacity()];
  usedB = oldObject.usedB;
  for(int i = 0; i < usedB; i++)
    b[i] = oldObject.b[i];
}

void PFArrayDBak::backup()
{
  usedB = getNumberUsed();
  for(int i = 0; i < usedB; i++)
    b[i] = operator[](i);
}

void PFArrayDBak::restore()
{
  emptyArray();
  for(int i = 0; i< usedB; i++)
    addElement(b[i]);
}

PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak& rightSide)
{
  int oldCapacity= capacity;
  PFArrayD::operator =(rightSide);
  if (oldCapacity != rightSide.getCapacity())
  {
    delete[] b;
    b = new double[rightSide.getCapacity()];
  }

  usedB = rightSide.usedB;
  for(int i = 0; i< usedB; i++)
    b[i]=rightSide.b[i];
  
  return *this;
}
PFArrayDBak::~PFArrayDBak()
{
  delete [] b;
}
