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

int blockState;
const int dogState = 0;
const int catState = 1;
const int humanState = 2;

bool isDog(char blockChar);
bool isCat(char blockChar);
bool isHuman(char blockChar);
bool isMath(char blockChar);
bool isValidChar(char currentChar);
bool isPosBlock(char currentChar, size_t i);
void updateCount(bool isPositiveBlock, char blockChar, int& counter, char expectedChar);

bool isValidAnimalParkString(string animalparkString);
int dogsLeft(string animalparkString);
int catsLeft(string animalparkString);
int peopleLeft(string animalparkString);


int main()
{
    string animalparkString;
    
    assert(isValidAnimalParkString("cp+dp-cp+dp-dp")); // testing that we can intersperese pluses and minuses
    assert(isValidAnimalParkString("cpppppppp+dddddddddp")); // testing that we can have any ammount of pets to owners and owners to pets
    assert(isValidAnimalParkString("dDpP+cCpP-DdPp-CcPp")); //checking that order of letters doesnt matter
    assert(!isValidAnimalParkString("dp-ddp")); // checking that more dogs can't leave than dogs have entered
    assert(!isValidAnimalParkString("cp-CCp")); // Checking that count keeps track of adult and adolescents
    assert(!isValidAnimalParkString("dp+p")); // no unaccompanied owners
    assert(!isValidAnimalParkString("d+dp")); // no unaccompanied pets
    assert(!isValidAnimalParkString("pd-dp")); //pets before owners
    
    assert(dogsLeft("dp")==1);
    assert(dogsLeft("DDDDdp")==5);
    assert(dogsLeft("dp+cp")==1);
    
    assert(catsLeft("cp")==1);
    assert(catsLeft("cp+cccp-ccp")==2);
    assert(catsLeft("cp+Ccpp+dp-cp")==2);
    
    assert(peopleLeft("cp")==1);
    assert(peopleLeft("cpPPP-cp")==3);
    assert(peopleLeft("cp-cp")==0);
    

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
    
    
    for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time (Outer loop @string level)
    {
        char currentChar = animalparkString[i];  // .at at runtime does bounds checking.
        
        if (!isValidChar(currentChar)) // checking if currentChar is a valid input
        {
            return false;
        }
        
        if (isMath(currentChar) || i == 0) //creating a fxn to check if char is a + or a -.
        {
            bool isPositiveBlock = isPosBlock(currentChar, i); //Setting block to pos or negative depending on the preceding operator
            
            size_t index = i+1;
            if (i==0)
            {
                index = i;
            }
            
            for (size_t j = index; j < lengthOfS; j++) // inner loop at block level
            {
                char blockChar = animalparkString[j];
                
                if(!isValidChar(blockChar)) // checking if blockChar is vald input
                {
                    return false;
                }
            
                // Check that this is the FIRST char in the block
                if ((j == i + 1 && i != 0) || j == 0)
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
                    if (blockState == dogState) // checking current state
                    {
                        updateCount(isPositiveBlock, blockChar, numPups, 'd'); //helper function to increment or decrement counter based on positive or negative block state
                        updateCount(isPositiveBlock, blockChar, numDogs, 'D');
                        
                        if (isCat(blockChar) || isMath(blockChar)) {
                            return false;
                        }
                        
                        if (isHuman(blockChar)) {
                            blockState = humanState; // if human, reassigning block state to human so no more animal inputs accepted.
                            
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
                        updateCount(isPositiveBlock, blockChar, numKids, 'p');
                        updateCount(isPositiveBlock, blockChar, numAdults, 'P');
                        
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
    
    if (isMath(animalparkString[lengthOfS-1]))
    {
        return false;
    }
    else if (numPups < 0 || numDogs < 0 || numKittens < 0 || numCats < 0 || numKids < 0 || numAdults < 0)
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
    int countPups = 0;
    int countDogs = 0;
    
    size_t lengthOfS = animalparkString.length();
    
    if (!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    
    // --------------------actual dog counter code------------------------------------
    
    else
    {
        bool isPositiveBlock = true;
        for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time
        {
            char currentChar = animalparkString[i];
            
            if (isMath(currentChar) || i == 0)
            {
                isPositiveBlock = isPosBlock(currentChar, i); //using operator to determine if the proceeding chars are pos or neg  (until next operator)
            }
            updateCount(isPositiveBlock, currentChar, countPups, 'd');
            updateCount(isPositiveBlock, currentChar, countDogs, 'D');
        }
        int dogsRemaining = countPups + countDogs;
        return dogsRemaining;
    }
}





int catsLeft(string animalparkString)
{
    int countKittens = 0;
    int countCats = 0;
    
    size_t lengthOfS = animalparkString.length();
    
    if (!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    
    // --------------------actual cat counter code------------------------------------
    
    else
    {
        bool isPositiveBlock = true;
        for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time
        {
            char currentChar = animalparkString[i];
            
            if (isMath(currentChar) || i == 0)
            {
                isPositiveBlock = isPosBlock(currentChar, i);
            }
            updateCount(isPositiveBlock, currentChar, countKittens, 'c');
            updateCount(isPositiveBlock, currentChar, countCats, 'C');
        }
        int catsRemaining = countKittens + countCats;
        return catsRemaining;
    }
}




int peopleLeft(string animalparkString)
{
    int countKids = 0;
    int countAdults = 0;
    
    size_t lengthOfS = animalparkString.length();
    
    if (!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    
    // --------------------actual people counter code------------------------------------
    
    else
    {
        bool isPositiveBlock = true;
        for (size_t i = 0; i < lengthOfS; i++) // walking through the string 1 element at a time
        {
            char currentChar = animalparkString[i];
            
            if (isMath(currentChar) || i == 0)
            {
                isPositiveBlock = isPosBlock(currentChar, i);
            }
            updateCount(isPositiveBlock, currentChar, countKids, 'p');
            updateCount(isPositiveBlock, currentChar, countAdults, 'P');
        }
        int peopleRemaining = countKids + countAdults;
        return peopleRemaining;
    }
}












//--------------------------------------------------------------------------------------------------------------------------
//The following are my "helper" functions for the code.


bool isValidChar(char currentChar) // determines if inividual char is a valid character
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
