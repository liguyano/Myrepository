#include <REGX52.H>
//
// Created by kurum on 西暦2023年3月22日.
//
#ifndef PRO_DHT22_DHT22_H
#define PRO_DHT22_DHT22_H
#include <SSS.h>
#define data P3_7
void Delay1000ms();
void Delay20us();
void Delay80us();
void dht_start();
uint dht_read();

#endif //PRO_DHT22_DHT22_H
