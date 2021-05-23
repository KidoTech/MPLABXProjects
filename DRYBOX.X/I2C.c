/*
 * File:   I2C.c
 * Author: alanlow
 *
 * Created on May 23, 2021, 8:06 AM
 */


#include <xc.h>
#include <PIC16F886.h>
#define _XTAL_FREQ 8000000

void I2C_Master_Init(const unsigned long c);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(unsigned d);
unsigned short I2C_Master_Read(unsigned short a);

void I2C_Master_Init(const unsigned long c) {
  SSPCON = 0x28;            //SSP Module as Master
  SSPCON2 = 0;
  SSPADD = (_XTAL_FREQ/(4*c))-1;
  SSPSTAT = 0;
  TRISCbits.TRISC3 = 1;
  TRISCbits.TRISC4 = 1;
}

void I2C_Master_Wait(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start(void)
{
  I2C_Master_Wait();
  SEN = 1;
}

void I2C_Master_Stop(void)
{
  I2C_Master_Wait();
  PEN = 1;
}

void I2C_Master_Write(unsigned d)
{
  I2C_Master_Wait();
  SSPBUF = d;
}

unsigned short I2C_Master_Read(unsigned short a)
{
  unsigned short temp;
  I2C_Master_Wait();
  RCEN = 1;
  I2C_Master_Wait();
  temp = SSPBUF;
  I2C_Master_Wait();
  ACKDT = (a)?0:1;
  ACKEN = 1;
  return temp;
}
