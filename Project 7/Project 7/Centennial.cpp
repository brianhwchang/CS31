//
//  Centennial.cpp
//  Centennial
//
//  Created by Brian Chang on 3/10/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include "Centennial.h"
#include <iostream>
#include <string>

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn( true )
    {
        
    }
    
    // prints the state of the game play with each round of play
    std::string Centennial::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return( s );
    }
    







    // CS 31 TODO: randomly play a human turn in the game
    void Centennial::humanPlay( )
    {
        // mark that it is the human's turn
        isHumanTurn = true;
        // let the human player randomly roll
        mHuman.roll();
        // look at what was rolled and update the board spots accordingly
        mHuman.getDie1();
    }




    // CS 31 TODO: force a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay( Die d1, Die d2, Die d3 )
    {
        // mark that it is the human's turn
        // force the human player to cheat
        // look at what was rolled and update the board spots accordingly
    }

    // CS 31 TODO: randomly play a computer turn in the game
    void Centennial::computerPlay( )
    {
        // mark that it is no longer the human's turn
        // let the computer player randomly roll
        // look at what was rolled and update the board spots accordingly
    }
    
    // CS 31 TODO: force a certain roll in the computer's turn of the game by cheating...
    void Centennial::computerPlay( Die d1, Die d2, Die d3 )
    {
        // mark that it is no longer the human's turn
        // force the computer player to cheat
        // look at what was rolled and update the board spots accordingly
    }
    


    // CS 31 TODO: determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome( ) const
    {
        // for now, just to get it to build...
        if ( mBoard.isGameOver() && mBoard.isHumanWinner() == true )
            return GAMEOUTCOME::HUMANWONGAME;
        else if ( mBoard.isGameOver() && mBoard.isHumanWinner() == false )
            return GAMEOUTCOME::COMPUTERWONGAME;
        else
            return GAMEOUTCOME::GAMENOTOVER;
    }
    
    // CS 31 TODO: determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
    {
        // if either human or computer reaches spot 12, set isGameOver = true.
        if (mBoard.getHumanSpot()==12 || mBoard.getComputerSpot()==12)
            return true;
        else
            return false;
    }






    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return( mHuman );
    }
    
    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return( mComputer );
    }
    
    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return( mBoard );
    }
}
