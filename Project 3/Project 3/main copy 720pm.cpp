//
//  main.cpp
//  Project 3
//
//  Created by Brian Chang on 2/1/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include <iostream>
#include <climits>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int blockState; //Do i have to initialise this as something or can I leave it undefined?
const int dogState = 0;
const int catState = 1;
const int humanState = 2; //should I be storing these as ints?

bool isDog(char blockChar);
bool isCat(char blockChar);
bool isHuman(char blockChar);
bool isMath(char blockChar);
bool isValidChar(char currentChar);
bool isPosBlock(char currentChar, size_t i);
void updateCount(bool isPositiveBlock, char blockChar, int& counter, char expectedChar);

bool isValidAnimalParkString(string animalparkString);
int dogsLeft(string animalparkString);



int main(int argc, const char * argv[])
{
    string animalparkString;

    //size_t lengthOfS = animalparkString.length();


    std::cout << "Hello, World!\n";
    return 0;
}


bool isValidAnimalParkString(string animalparkString) {
    
    size_t lengthOfS = animalparkString.length();
    
    int numPups = 0;
    int numDogs = 0;
    int numKittens = 0;
    int numCats = 0;
    int numKids = 0;
    int numAdults = 0;
    
    
    for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time
    {
        char currentChar = animalparkString[i];  // .at at runtime does bounds checking.
        
        if (!isValidChar(currentChar)) // checking if currentChar is a valid input
        {
            return false;
        }

        if (isMath(currentChar) || i == 0)
        {
            bool isPositiveBlock = isPosBlock(currentChar, i);
            
            updateCount(isPositiveBlock, currentChar, numPups, 'd');
            updateCount(isPositiveBlock, currentChar, numDogs, 'D');
            updateCount(isPositiveBlock, currentChar, numKittens, 'c');
            updateCount(isPositiveBlock, currentChar, numCats, 'C');
            
            for (size_t j = i+1; j < lengthOfS; j++)
            {
                char blockChar = animalparkString[j];
                
                if(!isValidChar(blockChar)) // checking if blockChar is vald input
                {
                    return false;
                }
            
                // Check that this is the FIRST char in the block
                if (j == i + 1)
                {
                    // Then...assign 1st state of decision tree -- if dog or cat block.
                    if (isDog(blockChar))
                    {
                        blockState = dogState;
                        
                        updateCount(isPositiveBlock, blockChar, numPups, 'd');
                        updateCount(isPositiveBlock, blockChar, numDogs, 'D');
                    }
                    else if (isCat(blockChar))
                    {
                        blockState = catState;
                        
                        updateCount(isPositiveBlock, blockChar, numKittens, 'c');
                        updateCount(isPositiveBlock, blockChar, numCats, 'C');
                    }
                    // If the first character in a block isn't an animal, return false
                    else
                    {
                        return false;
                    }
                }
                
                // Now..we're past the first character
                else
                {
                    if (blockState == dogState)
                    {
                        updateCount(isPositiveBlock, blockChar, numPups, 'd');
                        updateCount(isPositiveBlock, blockChar, numDogs, 'D');
                        
                        if (isCat(blockChar) || isMath(blockChar)) {
                            return false;
                        }
                        
                        if (isHuman(blockChar)) {
                            blockState = humanState;
                            
                            updateCount(isPositiveBlock, blockChar, numKids, 'p');
                            updateCount(isPositiveBlock, blockChar, numAdults, 'P');
                            
                        }
                    }
                    else if (blockState == catState)
                    {
                        updateCount(isPositiveBlock, blockChar, numKittens, 'c');
                        updateCount(isPositiveBlock, blockChar, numCats, 'C');
                        
                        if (isDog(blockChar) || isMath(blockChar)) {
                            return false;
                        }
                        
                        if (isHuman(blockChar)) {
                            blockState = humanState;
                            
                            updateCount(isPositiveBlock, blockChar, numKids, 'p');
                            updateCount(isPositiveBlock, blockChar, numAdults, 'P');
                        }
                    }
                    else if (blockState == humanState)
                    {
                        if (!isHuman(blockChar))
                        {
                            updateCount(isPositiveBlock, blockChar, numKids, 'p');
                            updateCount(isPositiveBlock, blockChar, numAdults, 'P');
                            
                            if(isMath(blockChar))
                            {
                                break;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (numPups < 0 || numDogs < 0 || numKittens < 0 || numCats < 0 || numKids < 0 || numAdults < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}



int dogsLeft(string animalparkString)
{
    int numPups = 0;
    int numDogs = 0;
    
    size_t lengthOfS = animalparkString.length();
    
    if (!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    
    else
    {
        for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time
        {
            char currentChar = animalparkString[i];
            
            if (isMath(currentChar) || i == 0)
            {
                bool isPositiveBlock = isPosBlock(currentChar, i);
                
                updateCount(isPositiveBlock, currentChar, numPups, 'd');
                updateCount(isPositiveBlock, currentChar, numDogs, 'D');
                
                for (size_t j = i+1; j < lengthOfS; j++)
                {
                    char blockChar = animalparkString[j];
                    
                    updateCount(isPositiveBlock, blockChar, numPups, 'd');
                    updateCount(isPositiveBlock, blockChar, numDogs, 'D');
                    
                }
            }
        }
        int dogCount = numPups + numDogs;
        return dogCount;
    }
}

//int catsLeft(string animalparkString) {
//
//}
//
//int peopleLeft(string animalparkString) {
//
//}












//--------------------------------------------------------------------------------------------------------------------------
//The following are my "helper" functions for the code.


bool isValidChar(char currentChar)
{
    return currentChar == 'D' || currentChar == 'd' || currentChar == 'C' || currentChar == 'c' || currentChar == 'P' ||currentChar == 'p' || currentChar == '+' || currentChar == '-';
}
bool isDog(char blockChar)// creating a boolean value to test if current char of the block is dog state or not
{
    return blockChar == 'D' || blockChar == 'd';
}
bool isCat(char blockChar)// creating a boolean value to test if current char of the block is dog state or not
{
    return blockChar == 'C' || blockChar == 'c';
}
bool isHuman(char blockChar)// creating a boolean value to test if current char of the block is human state or not
{
    return blockChar == 'P' || blockChar == 'p';
}
bool isMath(char blockChar)// creating a boolean value to test if current char of the block is human state or not
{
    return blockChar == '+' || blockChar == '-';
}

bool isPosBlock(char currentChar, size_t i) // creating a boolean value to determine if the block is positive or negative
{
    return currentChar == '+' || i == 0;
}

void updateCount(bool isPositiveBlock, char blockChar, int& counter, char expectedChar)
{
    // Check if the actual character in the block is equal to the character
    // it should be for an update.
    if (blockChar == expectedChar)
    {
        // Now we need to know if we should incremement or decrement.
        if (isPositiveBlock)
        {
            counter++;
        }
        else
        {
            counter--;
        }
    }
}






//int dogsLeft(string animalparkString) {
//
//}
//
//int catsLeft(string animalparkString) {
//
//}
//
//int peopleLeft(string animalparkString) {
//
//}

//
//char firstChar = animalparkString[0];
//if (firstChar != 'D' || firstChar != 'd' || firstChar != 'C' || firstChar != 'c')
//{
//    return -1;
//}
