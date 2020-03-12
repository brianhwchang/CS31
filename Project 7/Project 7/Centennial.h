//
//  Centennial.h
//  Centennial
//
//  Created by Brian Chang on 3/10/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#ifndef Centennial_h
#define Centennial_h
#include <string>
#include "Player.h"
#include "Board.h"


namespace cs31
{
    
    class Centennial
    {
    public:
        Centennial();
        
        // the possible game outcomes:
        // either the human won, the computer won or the game isn't yet over
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        // prints the state of the game play with each round of play
        std::string display( std::string msg = "" );

        // CS 31 TODO: randomly play a human turn in the game
        void humanPlay( );
        // CS 31 TODO: force a certain roll in the human's turn of the game by cheating...
        void humanPlay( Die d1, Die d2, Die d3 );
        // CS 31 TODO: randomly play a computer turn in the game
        void computerPlay( );
        // CS 31 TODO: force a certain roll in the computer's turn of the game by cheating...
        void computerPlay( Die d1, Die d2, Die d3 );
        
        // CS 31 TODO: determine the current state of the game
        GAMEOUTCOME determineGameOutcome( ) const;
        
        // CS 31 TODO: determine if the game has ended
        bool isGameOver();
        
        // primarily to enable testing of the game...
        // trivial getter operations
        Player getHuman() const;
        Player getComputer() const;
        Board  getBoard() const;
    private:
        Player mHuman;          // this Centennial's human player
        Player mComputer;       // this Centennial's computer player
        Board  mBoard;          // this Centennial's game board
        bool   isHumanTurn;     // whose turn is it, human or computer?
    };
    
}

#endif /* Centennial_h */
