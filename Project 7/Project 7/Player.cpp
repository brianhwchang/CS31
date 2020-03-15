//
//  Player.cpp
//  Centennial
//
//  Created by Brian Chang on 3/10/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include "Die.h"
#include "Player.h"
#include <iostream>


namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mDie3( 6 ), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {
        
    }
    
    // CS 31 TODO: cheat by accepting a particular set of dies for this player to use
    void Player::roll( Die d1, Die d2, Die d3 )
    {
        // assign each of the arguments to the Player's member variables to enable cheating...
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;
    }

    // CS 31 TODO: randomly roll each of the player's three dies
    void Player::roll( )
    {
        // randomly roll each of the three Die member variables
        mDie1.roll();
        mDie2.roll();
        mDie3.roll();
    }
    
    // CS 31 TODO: based on what has been tossed previously, determine the spot that is
    //             needed next
    // returning 1 means, in order to progress in the game at this point, the Player
    //             needs to toss a one
    // returning 2 means, in order to progress in the game at this point, the Player
    //             needs to toss a two
    // etc...
    int  Player::whatSpotIsNeededNext()
    {
        // for now to get it to build...
        //because boolean values return 1 if true, I can just add the bools together to get the current spot we're at, then add 1.
        int result = (hasRolled1 + hasRolled2 + hasRolled3 + hasRolled4 + hasRolled5 + hasRolled6 + hasRolled7 + hasRolled8 + hasRolled9 + hasRolled10 + hasRolled11 + hasRolled12 + 1);
        return( result );
    }
    
    // CS 31 TODO: this operation is called to indicate that the argument has been rolled
    //             in conjunction with the operation whatSpotIsNeededNext( ), adjust member
    //             variables correctly so that play can progress in the game
    // passing 1 means that a one was just tossed
    // passing 2 means that a two was just tossed
    // etc...
    void Player::rolled( int spot )
    {
        if (spot == whatSpotIsNeededNext())
        {
            // using a switch to call the corresponding boolean function to the interger arguement given. Update the boolean values of the member bools.
            switch (spot)
            {
                case 1:
                    hasRolled1 = true;
                    break;
                case 2:
                    hasRolled2 = true;
                    break;
                case 3:
                    hasRolled3 = true;
                    break;
                case 4:
                    hasRolled4 = true;
                    break;
                case 5:
                    hasRolled5 = true;
                    break;
                case 6:
                    hasRolled6 = true;
                    break;
                case 7:
                    hasRolled7 = true;
                    break;
                case 8:
                    hasRolled8 = true;
                    break;
                case 9:
                    hasRolled9 = true;
                    break;
                case 10:
                    hasRolled10 = true;
                    break;
                case 11:
                    hasRolled11 = true;
                    break;
                case 12:
                    hasRolled12 = true;
                    break;
                default:
                    break;
            }
        }
    }
    
    // trivial getter operation
    Die Player::getDie1() const
    {
        return( mDie1 );
    }
    
    // trivial getter operation
    Die Player::getDie2( ) const
    {
        return( mDie2 );
    }
    
    // trivial getter operation
    Die Player::getDie3( ) const
    {
        return( mDie3 );
    }
    
    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return( hasRolled1 );
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return( hasRolled2 );
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return( hasRolled3 );
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return( hasRolled4 );
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return( hasRolled5 );
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return( hasRolled6 );
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return( hasRolled7 );
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return( hasRolled8 );
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return( hasRolled9 );
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return( hasRolled10 );
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return( hasRolled11 );
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return( hasRolled12 );
    }
    
    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        s += " Die3: ";
        s += std::to_string( mDie3.getValue() );
        s += "\n";
        return( s );
    }
    
    

}
