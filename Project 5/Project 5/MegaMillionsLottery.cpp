//
//  MegaMillionsLottery.cpp
//  Project 5
//
//  Created by Brian Chang on 2/23/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"
#include <iostream>
#include <string>

using namespace std;

int matchingNums( const int ticket[ ], const int lottery[]);
bool megaMatch( const int ticket[], const int lottery[]);
bool hasDuplicates( const int array[ ], int n );

MegaMillionsLottery::MegaMillionsLottery() //creating a constructor that takes no arguements to randomly generate 5 balls and a mega ball
{
    RandomNumber randomNumGenerator = RandomNumber(1, 75);
    int randNum1 = randomNumGenerator.random();
    int randNum2 = randomNumGenerator.random();
    int randNum3 = randomNumGenerator.random();
    int randNum4 = randomNumGenerator.random();
    int randNum5 = randomNumGenerator.random();
    
    RandomNumber randomMegaGenerator = RandomNumber(1, 25);
    int megaNum = randomMegaGenerator.random();
    
    mBall1 = randNum1;
    mBall2 = randNum2;
    mBall3 = randNum3;
    mBall4 = randNum4;
    mBall5 = randNum5;
    mMegaBall = megaNum;
}


MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaBall) //creaeting a constructor that takes 6 arguments to assign all ball values manually.
{
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaBall;
}


MegaMillionsTicket MegaMillionsLottery::quickPick() //generating a ticket using the random number generator.
{
    RandomNumber randomNumGenerator(1, 75);
    RandomNumber randomMegaGenerator(1, 25);
    
    int testTicket[5];
    
    do {
        for (int i = 0; i < 5; i++) {
            testTicket[i] = randomNumGenerator.random();
        }
        
    } while (hasDuplicates(testTicket, 5));
    
    int genMegaNum = randomMegaGenerator.random();
    
    MegaMillionsTicket ticket(testTicket[0], testTicket[1], testTicket[2], testTicket[3], testTicket[4], genMegaNum);
    return ticket;
}


MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket)
{
    int ticketnumbers[6] = {ticket.getBall1(), ticket.getBall2(), ticket.getBall3(), ticket.getBall4(), ticket.getBall5(), ticket.getMegaBall()};
    int lotterynumbers[6] = {mBall1, mBall2, mBall3, mBall4, mBall5, mMegaBall};
    
    int ballsMatched = matchingNums(ticketnumbers, lotterynumbers); //using my helper function to count the number of balls matched.
    
    switch (ballsMatched) {
        case 1:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::ONEPLUSMEGABALL : MegaMillionsLottery::NOTWINNING ;
            break;
        case 2:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::TWOPLUSMEGABALL : MegaMillionsLottery::NOTWINNING ;
            break;
        case 3:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::THREEPLUSMEGABALL : MegaMillionsLottery::THREE ;
            break;
        case 4:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::FOURPLUSMEGABALL : MegaMillionsLottery::FOUR ;
            break;
        case 5:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::FIVEPLUSMEGABALL : MegaMillionsLottery::FIVE ;
            break;
        default:
            return megaMatch(ticketnumbers, lotterynumbers) ? MegaMillionsLottery::MEGABALL : MegaMillionsLottery::NOTWINNING ;
            break;
    }
}

string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket)
{
    WinningPossibility outcome = checkTicket(ticket);
    
    switch (outcome) {
        case NOTWINNING:
            return "You didn't win anything at all!";
            break;
        case MEGABALL:
            return "You matched the megaball!";
            break;
        case ONEPLUSMEGABALL:
            return "You matched 1 ball plus the megaball!";
            break;
        case TWOPLUSMEGABALL:
            return "You matched 2 balls plus the megaball!";
            break;
        case THREEPLUSMEGABALL:
            return "You matched 3 balls plus the megaball!";
            break;
        case THREE:
            return "You matched 3 balls!";
            break;
        case FOURPLUSMEGABALL:
            return "You matched 4 balls plus the megaball!";
            break;
        case FOUR:
            return "You matched 4 balls!";
            break;
        case FIVEPLUSMEGABALL:
            return "You matched 5 balls plus the megaball!";
            break;
        case FIVE:
            return "You matched 5 balls!";
        default:
            break;
    }
}



int MegaMillionsLottery::getBall1()
{
    return mBall1;
}

int MegaMillionsLottery::getBall2()
{
    return mBall2;
}

int MegaMillionsLottery::getBall3()
{
    return mBall3;
}

int MegaMillionsLottery::getBall4()
{
    return mBall4;
}

int MegaMillionsLottery::getBall5()
{
    return mBall5;
}

int MegaMillionsLottery::getMegaBall()
{
    return mMegaBall;
}


//-----------------------------------------------------------------------------------------------------------------------------------
//helper functions below

int matchingNums( const int ticket[ ], const int lottery[])
{
    int ballsMatched = 0;
    
    for (int i = 0; i < 5 ; i++) // walking through the array 1 element at a time. (Outer loop)
    {
        for (int j = i; j < 5 ; j++) // walking through the array 1 element at a time. (Inner loop)
        if (lottery[i]==ticket[j]) // comparing [i] and [j] indexes to find duplicates
            ballsMatched++; //incrementing match counter
    }
    return ballsMatched;
}

bool megaMatch( const int ticket[], const int lottery[]) // creating a flag to check if megaballs match
{
    if (ticket[5] == lottery[5])
        return true;
    else
        return false;
}


bool hasDuplicates( const int array[ ], int n )
{

    for (int i = 0; i < n ; i++) // walking through the array 1 element at a time. (Outer loop)
    {
        for (int j = i+1; j < n ; j++) // walking through the array 1 element at a time. (Inner loop)
        if (array[i]==array[j]) // comparing [i] and [j] indexes to find duplicates
            return true;
    }
    return false;
}

