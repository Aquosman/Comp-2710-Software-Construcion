// Ian fair
// hm4_izf0002.cpp
// homework 4
// Merging two files into one output file with numbers in order.
// I had no help bc I am boi genius.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;
const int MAX_SIZE = 100;
ifstream inStream;
ofstream outStream;

void selectionSort(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int minPosition = arr[i];
      int position = i;
   	
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < minPosition)
         {
            minPosition = arr[j];
            position = j;
         }
      }
   	
      int temp = arr[position];
      arr[position] = arr[i];
      arr[i] = temp;
   }
}

string getFile1()
{
   string name = "";
   cout << "Enter the first input file name: ";
   cin >> name;
   return name;
}

string getFile2()
{
   string name = "";
   cout << "Enter the second input file name: ";
   cin >> name;
   return name;
}

int fileLength(string fileName)
{
   ifstream inStream;
   int i = 0;
   int fileArr[MAX_SIZE];
   inStream.open((char*)fileName.c_str());
   if (!inStream.fail())
   {
      while (inStream >> fileArr[i])
      {
         i++;
      }
   }
	
   inStream.close();
   return i;
}


//main

int main()
{

	
	
   int fileArr1[MAX_SIZE];
   int fileArr2[MAX_SIZE];
   int fileArr3[MAX_SIZE];
	
   int i = 0;
   int j = 0;
	
   string input1 = "";
   string input2 = "";

   cout << "*** Welcome to Ian Fair's sorting program ***\n";
	//first function gets input and opens the required txt file then closes it after displaying contents.
   input1 = getFile1();
   cout << "The list of " << fileLength(input1) << " numbers in file " << input1 << " is:\n";
   inStream.open((char*)input1.c_str());
   if (!inStream.fail())
   {
      while (inStream >> fileArr1[i])
      {
         cout << fileArr1[i] << endl;
         i++;
      }
   }
   inStream.close();
   cout << endl;


	//same as first function just for the second input and required txt file supplied on canvas.
   input2 = getFile2();
   cout << "The list of " << fileLength(input2) << " numbers in file " << input2 << " is:\n";
   inStream.open((char*)input2.c_str());
   if (!inStream.fail())
   {
      while (inStream >> fileArr2[j])
      {
         cout << fileArr2[j] << endl;
         j++;
      }
   }
	
   inStream.close();
   cout << endl;
	// sets first array to third and second to third, basically merges data into third array.			
   int txtSize0 = i;
   int txtSize1 = j;
   int x = 0;

   while (x < i+j)
   {
      for (i = 0; i < txtSize0; i++)
      {
         fileArr3[x] = fileArr1[i];
         x++;
      
      }
      for (j = 0; j < txtSize1; j++)
      {
         fileArr3[x] = fileArr2[j];
         x++;
      }
   
   }

	// Sorts the input data and outputs into a new txt file.
   selectionSort(fileArr3, x);
   cout << "The sorted list of " << x << " numbers is: ";
   outStream.open("output.txt");
   for (int q = 0; q < x; q++)
   {
      outStream << fileArr3[q] <<" ";
      cout << fileArr3[q] <<" ";
   }
   cout << endl;
   outStream.close();


   return 0;
}

