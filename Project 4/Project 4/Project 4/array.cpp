//
//  main.cpp
//  Project 4
//
//  Created by Brian Chang on 2/18/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include <iostream>
#include <climits>
#include <string>
#include <cctype>
#include <cassert>
#include <vector>

using namespace std;

int locateMaximum(const string array[], int n);
bool hasDuplicates( const string array[ ], int n );
int countSs( const string array[ ], int n );
int shiftLeft( string array[ ], int n, int amount, string placeholderToFillEmpties );
bool isInDecreasingOrder( const string array[ ], int n );
bool matchingValuesTogether( const string array[ ], int n );
int divide( string array[ ], int n, string divider );

void swap( string *a , string *b);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    string folks[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard123", "jon"};
    
    string numbers[5] = { "5", "4", "3", "2", "15" };
    
    cout << divide(numbers, 5, "21");
    
    
    return 0;
}


//-------------------------------------------------------------------------------------------------


int locateMaximum(const string array[], int n)
{
    if (n <= 0)
        return -1;
    
    int largestInt=0;
    string largest = array[0];
    
    for (int i = 1; i < n ; i++) // walking through the array 1 element at a time.
    {
        if (array[i] > largest) // comparing current value of the for-loop to previously stored largest string
        {
            largest = array[i]; // reassigning largest to new largest
            largestInt = i; // keeping track of the index of the most recent largest
        }
    }
    return largestInt; // returning index
}


//--------------------------------------------------------------------------------------------------


bool hasDuplicates( const string array[ ], int n )
{
    
    if (n <= 0)
        return false;
    
    for (int i = 0; i < n ; i++) // walking through the array 1 element at a time. (Outer loop)
    {
        for (int j = i+1; j < n ; j++) // walking through the array 1 element at a time. (Inner loop)
        if (array[i]==array[j]) // comparing [i] and [j] indexes to find duplicates
            return true;
    }
    return false;
}


//--------------------------------------------------------------------------------------------------


int countSs( const string array[ ], int n )
{
    int sCount=0;
    if (n <= 0)
        return -1;
    
    for (int i = 0; i < n ; i++) // walking through the array 1 element at a time. (Outer loop)
    {
        string currentString = array[i]; //setting current element of the array as currentString
        
        for (int j = 0; j < currentString.length() ; j++) // walking through currentString char by char
        {
            char currentChar = currentString[j];
            
            if (currentChar == 's' || currentChar == 'S') // incrementing counter if there is an 's' or 'S'.
                sCount++;
        }
    }
    return (sCount);
}


//--------------------------------------------------------------------------------------------------


int shiftLeft( string array[ ], int n, int amount, string placeholderToFillEmpties )
{
    if (n <= 0)
        return (0); //returning 0 if string is empty or less than 0
    
    int shiftCount = 0;
    int myAmount = amount;
    int i; // initialising var 'i' outside of for loop so I can continue to use it for the while loop.
    
    for (i = 0; myAmount < n; i++)
    {
        array[i] = array[myAmount]; //replacing leading elements with later elements
        myAmount++;
    }
    
    while (i < n)
    {
        array[i] = placeholderToFillEmpties; //replacing later elements with placeholders
        shiftCount++;
        i++;
    }
    return(shiftCount); //returning number of placeholders inserted
}


//--------------------------------------------------------------------------------------------------


bool isInDecreasingOrder( const string array[ ], int n )
{
    if (n <= 0)
        return false;
    
    for (int i = 1; i < n; i++) //iterating through the array one element at a time
    {
        if (array[i-1] < array[i]) //creating a condition statement that check if current element is larger than preceding element
            return false; //if current > preceding, return false.
    }
    return true;
}


//--------------------------------------------------------------------------------------------------

// double check if this works for multiple duplicates in a row.

bool matchingValuesTogether( const string array[ ], int n )
{
    if (!hasDuplicates(array, n)) //checking that string has duplicates at all
        return true;
    
    for (int i = 0; i < n ; i++) //outer loop. Looping through array elements with counter i
    {
        string currentString = array[i];
        
        for (int j = i+1; j < n; j++) // inner loop. Looping through array elements with counter j, where j = 1+1
        {
            if (array[j] == currentString && array[j-1] != array[j] ) // if the element match but aren't sequential, return false.
            {
                return false;
            }
        }
    }
    return true;
}


//--------------------------------------------------------------------------------------------------

int divide( string array[ ], int n, string divider )
{
    for (int i = 0; i < (n-1); i++) //Using bubblesort to sort the list
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j + 1]); //calling a function I created to swap the values.
            }
        }
    }
    
    for (int k = 0; k < n; k++) //finding the index of the first value in the sorted list that is greater than the divider.
    {
        if (array[k] > divider)
            return k;
    }
    
    return 0;
}

void swap( string *a , string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}

//int divide( string array[ ], int n, string divider )
//{
//
//    int count = 0;
//    vector<string> greater;
//    vector<string> lesser;
//
//    for (int i = 0; i < n; i++) //for loop that runs through array and sorts into greater and lesser lists.
//    {
//        if (array[i] < divider)
//        {
//            lesser.push_back(array[i]);
//            count++;
//        }
//        else
//            greater.push_back(array[i]);
//        //what if array[i] = divider though?
//    }
//
//    int position = count;
//
//    for (int j = 0; j < lesser.size(); j++) //replacing the first 'n' elements of the array with 'lesser' vector
//    {
//        array[j] = lesser[j];
//    }
//
//    for (int k = count; k < greater.size(); k++)
//    {
//        array[k] = greater[k]; //replacing the remaining elements of the array with 'greater' vector.
//    }
//
//    return(position);
//}

//I could create a "greater than" array and a "lesser than" array using the fxn to sort them into lists first
//then reassign the values starting with the lesser than array follow by great than
//there would be some counter element be thats shared between the assinging for loops.

//I'd need to create a list that allows me to just add elements (like .append for python) so it can grow longer without knowing the length at first.


//int divide (string array[ ], int n, string divider)
//{
//    string newArray[n];
//
//    int start = 0;
//    int end = n - 1;
//
//    for (int i = 0; i < n; i++)
//    {
//        if (array[i] < divider)
//        {
//            newArray[start] = array[i];
//            start++;
//        }
//        else
//        {
//            newArray[end] = array[i];
//            end--;
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        array[i] = newArray[i];
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (newArray[i] > divider)
//        {
//            return i;
//        }
//    }
//
//    return 0;
//}
