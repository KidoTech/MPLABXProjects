/* 
 * File:   AHT10.h
 * Author: Alan
 *
 * Created on 06 Jun 2021
 */

#ifndef AHT10_H
#define	AHT10_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <PIC16F886.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "I2C.h"
    
//------------------------------ Definitions ---------------------------------//

#define AHT10_WRITE_ADDRESS         0x38  //Address 0011 1000 with LSB 0 for WRITE
#define AHT10_READ_ADDRESS          0x39  //Address 0011 1001 with LSB 1 for READ  
#define AHT10_INIT_CMD              0xE1  //initialization command for AHT10/AHT15
#define AHT10_START_MEASUREMENT_CMD 0xAC  //start measurment command
#define AHT10_SOFT_RESET_CMD        0xBA  //soft reset command
#define AHT10_READ_CMD              0x71  //Check Status command
#define AHT10_INIT_NORMAL_MODE      0x00  //enable normal mode
#define AHT10_INIT_CYCLE_MODE       0x20  //enable cycle mode
#define AHT10_INIT_CMD_MODE         0x40  //enable command mode
#define AHT10_INIT_CAL_ENABLE       0x08  //load factory calibration coeff
#define AHT10_DATA_MEASUREMENT_CMD  0x33  //no info in datasheet!!! my guess it is DAC resolution, saw someone send 0x00 instead
#define AHT10_DATA_NOP              0x00  //no info in datasheet!!!
#define AHT10_MEASUREMENT_DELAY     80    //at least 75 milliseconds
#define AHT10_POWER_ON_DELAY        40    //at least 20..40 milliseconds
#define AHT10_CMD_DELAY             350   //at least 300 milliseconds, no info in datasheet!!!
#define AHT10_SOFT_RESET_DELAY      20    //less than 20 milliseconds
#define AHT10_FORCE_READ_DATA       true  //force to read data
#define AHT10_USE_READ_DATA         false //force to use data from previous read
#define AHT10_ERROR                 0xFF  //returns 255, if communication error is occurred


void AHT10_RESET(void){
    I2C_Begin();
    I2C_Write(AHT10_WRITE_ADDRESS);
    I2C_Write(AHT10_SOFT_RESET_CMD);
    I2C_End();
} 

void AHT10_INIT(void){
    
    unsigned char stat;
    
    I2C_Begin();
    I2C_Write(AHT10_WRITE_ADDRESS);
    I2C_Write(AHT10_INIT_CMD);
    I2C_Write(AHT10_INIT_CAL_ENABLE);
    I2C_Write(AHT10_INIT_NORMAL_MODE);
    I2C_End();
    
    I2C_Begin();
    I2C_Write(AHT10_READ_ADDRESS);
    stat = I2C_Read(0);
    I2C_End();
}


void AHT10_MEASURE(void){
    I2C_Begin();
    I2C_Write(AHT10_WRITE_ADDRESS);
    I2C_Write(AHT10_START_MEASUREMENT_CMD);
    I2C_Write(AHT10_DATA_MEASUREMENT_CMD);
    I2C_Write(AHT10_INIT_NORMAL_MODE);
    I2C_End();
}

unsigned char* AHT10_READ(void){
    
    unsigned char dat[6];
    int cnt;
    
    I2C_Begin();
    I2C_Write(AHT10_READ_ADDRESS);
    //I2C_Write(AHT10_READ_CMD);
    for (cnt = 0; cnt < 6; ++cnt){
        dat[cnt] = I2C_Read(0);     
    }
    I2C_End();
    return dat;
}    
    
#ifdef	__cplusplus
}
#endif
    
#endif	/* SSD1306_H */

