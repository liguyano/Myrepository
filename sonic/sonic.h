//
// Created by kurum on 2/28/2023.
//

#ifndef CMAKELISTS_TXT_SONIC_H
#define CMAKELISTS_TXT_SONIC_H
#include <STC15F2K60S2.H>
#include <INTRINS.H>
#define Tx P37
#define Rx P36

void sonic_sent();
unsigned int sonic_recv();

#endif //CMAKELISTS_TXT_SONIC_H
