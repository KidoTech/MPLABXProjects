/*
 * File:   I2C.c
 * Author: alanlow
 *
 * Created on May 23, 2021, 8:06 AM
 */


#include <xc.h>
#include "I2C.h"
#include <PIC16F886.h>

void I2C_Initialize(const unsigned long feq_K) //Begin IIC as master
{
  TRISC3 = 1;  TRISC4 = 1;  //Set SDA and SCL pins as input pins

  SSPCON  = 0b00101000;    //pg84/234
  SSPCON2 = 0b00000000;    //pg85/234

  //SSPADD = (_XTAL_FREQ/(4*feq_K*100))-1; //Setting Clock Speed pg99/234
  SSPADD = (_XTAL_FREQ/(4*feq_K*1000))-1; //Setting Clock Speed pg99/234
  SSPSTAT = 0b00000000;    //pg83/234
}

void I2C_Hold()
{
    while (   (SSPCON2 & 0b00011111)    ||    (SSPSTAT & 0b00000100)   ) ; //check the this on registers to make sure the IIC is not in progress
}

void I2C_Begin()
{
  I2C_Hold();  //Hold the program is I2C is busy 
  SEN = 1;     //Begin IIC pg85/234
}
void I2C_End()
{
  I2C_Hold(); //Hold the program is I2C is busy 
  PEN = 1;    //End IIC pg85/234
}

void I2C_Write(unsigned data)
{
  I2C_Hold(); //Hold the program is I2C is busy
  SSPBUF = data;         //pg82/234
}

//unsigned short I2C_Read(unsigned short ack)
unsigned char I2C_Read(unsigned char ack)
{
  unsigned char incoming, buf_stat1, buf_stat2, buf_stat3;
  
  buf_stat1 = SSPSTAT;
  I2C_Hold();
  RCEN = 1;
  buf_stat2 = SSPSTAT;
  I2C_Hold();
  incoming = SSPBUF;      //get the data saved in SSPBUF
  buf_stat3 = SSPSTAT;
  //I2C_Hold();
  //ACKDT = (ack)?0:1;    //check if ack bit received 
  ACKEN = 1;          //pg 85/234

  return incoming;
}