//
// Created by kurum on 2/28/2023.
//
#include "sonic.h"
void Delay12us()		//@11.0592MHz
{
    unsigned char i;

    _nop_();
    _nop_();
    _nop_();
    i = 30;
    while (--i);
}

void sonic_sent()
{   Tx=1;
    Delay12us();
    Tx=0;
    Delay12us();
    Tx=1;
    Delay12us();
    Tx=0;
    Delay12us();
    Tx=1;
    Delay12us();
    Tx=0;
    Delay12us();

}
void Delay1000ms()		//@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    _nop_();
    i = 30;
    j = 107;
    k = 115;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

unsigned int sonic_recv() {
    unsigned int time = 0;
    AUXR &= 0xBF;		//定时器时钟12T模式
    TMOD &= 0x0F;		//设置定时器模式
    TMOD |= 0x10;		//设置定时器模式
    TH1 = TL1 = 0;
    sonic_sent();
    while (!Rx);
    TR1 = 1;
    while ((Rx == 1) && (TF1 == 0));
    TR1 = 0;
    if (TF1 == 0) {
        time = TH1 << 8 | TL1;
        return (time * 0.017);
    } else
    {
        TF1=0;
        P2 = (P2 & 0x1f) | 0x80;
        P0=0x00;
        Delay1000ms();
        P0=0xff;
        P2 = (P2 & 0x1f);
        return 3;
    }

}

