//
//  MegaMillionsLottery.hpp
//  Project 5
//
//  Created by Brian Chang on 2/23/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#ifndef MegaMillionsLottery_h
#define MegaMillionsLottery_h

#include <string>
#include <stdio.h>
#include "MegaMillionsTicket.h"

using namespace std;

class MegaMillionsLottery {
    
public:
    
    enum WinningPossibility {
        MEGABALL,
        ONEPLUSMEGABALL,
        TWOPLUSMEGABALL,
        THREE,
        THREEPLUSMEGABALL,
        FOUR,
        FOURPLUSMEGABALL,
        FIVE,
        FIVEPLUSMEGABALL,
        NOTWINNING
    };
    
    MegaMillionsLottery();
    MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaBall);
    
    MegaMillionsTicket quickPick();
    WinningPossibility checkTicket(MegaMillionsTicket ticket);
    string whatHappened(MegaMillionsTicket ticket);
    
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

#endif /* MegaMillionsLottery_h */
