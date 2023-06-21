//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef CAR_DRIVER_TRANSPORT_H
#define CAR_DRIVER_TRANSPORT_H
#include <STC89C5xRC.H>
#include "INTRINS.H"
#include "UART.h"
#include "SSS.h"
#define TRSND_ERRO_WAITSEND 1
#define TRSND_ERRO_SENDING 2
#define sn(p,v) DIAPlaySMG_Bit(SMG_duanma[v],p); Delay10ms()
#define snd(p,v) DIAPlaySMG_Bit(SMG_duanma[v]&0x7f,p); Delay10ms()
#define RT P32
#define TT P33
void Delay10ms();
void Timer0_Init(void);		//5ms@11.0592MHz
void Delay100ms();
void Wait_send();
void TR_send(unsigned char dat);
void Tr_init();
unsigned char TR_recv();
void Delay1000ms();
uchar get_erro();
#endif //CAR_DRIVER_TRANSPORT_H
