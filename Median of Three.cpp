// Garrick Morley
// CPSC 300 Project 4
// This program uses the median-of-three method to quicksort integers from the file "nums"

// I just use all the include statements I know to cover everything

//Corrections say it only works for smaller lists

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string>

using namespace std;

//this function prints the list
void listPrint(int list[], int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
    	cout << list[i]<< endl;
	}
}

//this function swaps two numbers using pointers
void sort(int* ptr1, int* ptr2)
{
    int temp1;
	temp1 = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp1;
}

//RECCOMENDED FUNCTION
//this function returns the median of 3 numbers
int median3(int n1, int n2, int n3)
{
	//checks if median is n2
	if((n1 < n2 && n2 < n3) || (n3 < n2 && n2 < n1))
		return n2;
	
	//checks if median is n1
	else if((n2 < n1 && n1 < n3) || (n3 < n1 && n1 < n2))
		return n1;
	
	//if not those 2 must be n3
	else
		return n3;
}

//RECCOMENDED FUNCTION
//this function partitions the list into left and right
int partition(int list[], int left, int right)
{
    int pivotPoint;
    int index;
    int median;
    index = (left - 1);
	pivotPoint = list[right];

	//run the list as many times as there are integers in the file
    for (int counter = left; counter <= right - 1; counter++)
    {
        median = median3(pivotPoint, list[counter], list[index]);
        if (list[counter] < pivotPoint)
        {
            index++;
            sort(&list[index], &list[counter]);
        }
    }
    sort(&list[index + 1], &list[right]);
    return (index + 1);
}

//RECCOMENDED FUNCTION
//this function calls on the partition function to sort the list in ascending order
void quickSort(int list[], int left, int right)
{
	int partIndex;

    if (left < right)
    {
		partIndex = partition(list, left, right);
        quickSort(list, left, partIndex - 1);
        quickSort(list, partIndex + 1, right);
    }
}

//the main function runs the program and calls on the functions from above
main() 
{
	int list[1000];
	int numbers = 0;
	int counter = 0;
		
	//open the file "nums"
	ifstream infile;
	infile.open("nums");
	
	//check to ensure the file opened correctly
	if (infile.fail())
	{
		cout << "Error opening the file 'nums'" << endl;
	}
	
	//Prints the numbers in the file before sorting
	cout << "Before sorting, these are the numbers in file 'nums': " << endl;
	while(infile >> numbers)
	{
		list[counter] = numbers;
		counter++;
		cout << numbers << endl;
	}
	
	cout << endl;
		
	//Prints the numbers in the file after sorting
	cout << "After sorting, these are the numers in file 'nums': " << endl;
	while(infile >> numbers)
	{
		list[counter] = numbers;
		counter++;
		cout << numbers << endl;
	}
	
	//sort the list in ascending order
    quickSort(list, 0, counter-1);  
    
    //prints the now sorted list
    listPrint(list, counter);  
}
