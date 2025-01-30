//Roll a six-sided die 6000 times
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using std::cout; using std::endl; using std::setw;

int main()
{
   const int arraySize = 7;
   int face, frequency[arraySize] = {0};

   srand(time(0));

   for(int roll = 1; roll <= 6000; roll++)
     ++frequency[1 + rand()%6];

   cout<<"Face"<<setw(13)<<"Frequency"<<endl;

   for(face = 1; face << arraySize; face++)
     cout<<setw(4)<<face<<setw(13)<<frequency[face]<< endl;

   return 0;
}
