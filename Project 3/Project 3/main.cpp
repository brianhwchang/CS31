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
bool isValidChar(char currentChar);
bool isMath(char blockChar);

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
    
    
    for (size_t i = 0; i < lengthOfS; i++)
    {
        char currentChar = animalparkString[i];  // .at at runtime does bounds checking.
        
        if (!isValidChar(currentChar))
        {
            return false;
        }

        if (isMath(currentChar))
        {
            for (size_t j = i+1; j < lengthOfS; j++)
            {
                char blockChar = animalparkString[j];
                
                if(!isValidChar(blockChar))
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
                    }
                    else if (isCat(blockChar))
                    {
                        blockState = catState;
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
                        if (isCat(blockChar) || isMath(blockChar)) {
                            return false;
                        }
                        
                        if (isHuman(blockChar)) {
                            blockState = humanState;
                        }
                    }
                    else if (blockState == catState)
                    {
                        if (isDog(blockChar) || isMath(blockChar)) {
                            return false;
                        }
                        
                        if (isHuman(blockChar)) {
                            blockState = humanState;
                        }
                    }
                    else if (blockState == humanState)
                    {
                        if (!isHuman(blockChar))
                        {
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
}


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
