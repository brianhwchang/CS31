//
//  MegaMillionsTicket.hpp
//  Project 5
//
//  Created by Brian Chang on 2/23/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#ifndef MegaMillionsTicket_h
#define MegaMillionsTicket_h

#include <stdio.h>

class MegaMillionsTicket {
    
public:
    MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaBall);
    int getBall1();
    int getBall2();
    int getBall3();
    int getBall4();
    int getBall5();
    int getMegaBall();
    
    
private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mMegaBall;
};

#endif /* MegaMillionsTicket_h */
