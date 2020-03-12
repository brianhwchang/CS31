//
//  main.cpp
//  Project 5
//
//  Created by Brian Chang on 2/23/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"

int main() {
    MegaMillionsTicket t(1,2,3,4,5,6);
    MegaMillionsLottery l(6,5,4,3,2,1);
    assert( l.checkTicket( t ) == MegaMillionsLottery::WinningPossibility::FOUR);
}



