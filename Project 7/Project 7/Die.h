//
//  Die.h
//  Centennial
//
//  Created by Brian Chang on 3/10/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#ifndef Die_h
#define Die_h

namespace cs31
{
    
/*
 This class supports a random die of some number of sides.
 This class is completely finished.  There is no work for CS 31 students here.
 */
class Die
{
public:
    Die( int sides = 6 ); // by default, a six sided die
    // randomly toss the die
    void roll();
    // return the value that was previously tossed, whether randomly or cheated
    int  getValue( ) const;
    // cheat by setting a desired value for the die
    void setValue( int amount );
private:
    int  mSides;  // the number of side for this die
    int  mValue;  // the value that was just tossed, whether randomly or cheated
};

    
}
#endif /* Die_h */
