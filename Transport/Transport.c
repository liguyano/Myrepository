//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"
static uchar erro;
static uint timer;
void Timer0_Init(void)		//5ms@12.000MHz
{
    AUXR |= 0x80;			//imer clock is 1T mode
    TMOD &= 0xF0;			//Set timer work mode
    TL0 = 0xA0;				//Initial timer value
    TH0 = 0x15;				//Initial timer value
    TF0 = 0;				//Clear TF0 flag
    TR0 = 1;				//Timer0 start run
    EA=1;
    ET0=1;
}

void Delay10ms()		//@11.0592MHz
{
    unsigned char i, j;

    i = 18;
    j = 235;
    do
    {
        while (--j);
    } while (--i);
}

void Delay1000ms()		//@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    i = 8;
    j = 1;
    k = 243;
    do
    {
        do
        {while (--k);
        } while (--j);
    } while (--i);
}
void Tr_init()
{
    Timer0_Init();
    TT=1;
    RT=1;
}
void TR_send(unsigned char dat)
{
    unsigned char i;
    erro=0;
    timer=0;
    RT=1;
    TT=1;
    Delay10ms();
    TT=0;
    //UART_SendString("wait answ \0");
    while (RT)
    {
        Delay10ms();
        if(timer%50==0)
        {
            RT=1;
            TT=1;
            Delay10ms();
            TT=0;
        }
        if (timer>=3000)
        {
            erro=TRSND_ERRO_WAITSEND;
            return;
        }
    }
    //UART_SendString("send a char \0");
    for (i=0;i<8;i++)
    {
       // UART_SendString("wait RT to be high\0");
        Delay10ms();
        while (!RT)
        {
            timer=0;
            if (timer>=400)
            {
                erro=TRSND_ERRO_SENDING;
                return;
            }
        }
        TT=dat&(0x80>>i);
        Delay10ms();
        while (RT)
        {
            timer=0;
            if (timer>=400)
            {
                erro=TRSND_ERRO_SENDING;
                return;
            }
        }
    }
    Tr_init();
}
void Delay100ms()		//@11.0592MHz
{
    unsigned char i, j;

    i = 180;
    j = 73;
    do
    {
        while (--j);
    } while (--i);
}

unsigned char TR_recv()
{unsigned char re=0,i;
    Wait_send();
    //UART_SendString("send anser");
    TT=0;
    Delay10ms();
    for (i=0;i<8;i++)
    {
        RT=1;
        TT=1;
        Delay10ms();
        if (RT)
        {
            re |= (0x80>>i);
        }
        TT=0;
        Delay10ms();
    }
    Tr_init();
    return re;
}
void Wait_send()
{Delay10ms();
    UART_SendByte(RT==1);
    while (!RT);
    RT=1;
    Delay10ms();
    while (RT);
    UART_SendByte(RT==1);
}
void time1() interrupt NUM1
{
    TL0 = 0xA0;				//Initial timer value
    TH0 = 0x15;				//Initial timer value
    timer++;
}
uchar get_erro()
{

    return erro;
}