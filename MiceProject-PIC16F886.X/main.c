/*
 * File:   main.c
 * Author: alanlow
 *
 * Created on April 10, 2021, 7:27 PM
 */

#define _XTAL_FREQ 8000000
#include <stdio.h>
#include <xc.h>
#include <PIC16F886.h>

// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG


void interrupt isr()
{
    //reset the interrupt flag
    //INTCONbits.INTF = 0;
}

void SYS_Init(void){
    
    
    // Setup System Clock
    
    
    
    // Setup GPIO
    
    
    ////// For Stepper Motor
    
    
    ////// For I2C
    
    
    ////// For Interrupt
    
    
    ////// For IR Sensor
    
    
    ////// For Switch
    
    
    return;
}



void main(void) {
    SYS_Init();
            
    return;
}
