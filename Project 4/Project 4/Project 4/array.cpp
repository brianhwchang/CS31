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

using namespace std;

int locateMaximum(const string array[], int n);
bool hasDuplicates( const string array[ ], int n );
int countSs( const string array[ ], int n );
int shiftLeft( string array[ ], int n, int amount, string placeholderToFillEmpties );
//bool isInDecreasingOrder( const string array[ ], int n );
//bool matchingValuesTogether( const string array[ ], int n );
//int divide( string array[ ], int n, string divider );

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    string folks[8] = {
       "samwell", "jon", "margaery", "daenerys",
       "tyrion", "sansa", "howard123", "jon"
    };

    locateMaximum(folks, 8);
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










//bool matchingValuesTogether( const string array[ ], int n )
//{
//    return( false );
//}

//int divide( string array[ ], int n, string divider )
//{
//    return( false );
//}
