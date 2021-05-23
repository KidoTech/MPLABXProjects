/*
 * File:   MAIN.c
 * Author: alanlow
 *
 * Created on May 23, 2021, 7:03 AM
 */


#include "I2C.h"
#include "FONT.h"
#include <xc.h>
#include <PIC16F886.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define I2C_SCL         PORTCbits.RC3       // I2C SCL 
#define I2C_SCL_TRIS    TRISCbits.TRISC3    // I2C SCL tri-state buffer
#define I2C_SDA         PORTCbits.RC4       // I2C SDA 
#define I2C_SDA_TRIS    TRISCbits.TRISC4    // I2C SDA tri-state buffer

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
void Setup(void);
void DisplayData(void);
void TMR0_Initialize(void);
uint8_t TMR0_ReadTimer(void);
void TMR0_WriteTimer(uint8_t timerVal);
void TMR0_Reload(void);
void TMR0_ISR(void);
void TMR0_SetInterruptHandler(void (* InterruptHandler)(void));
void TMR0_DefaultInterruptHandler(void);


int counter = 0;

void main(void) {
    Setup();
    return;
}

void Setup(void){
    
    // SCS FOSC; SPLLEN disabled; IRCF 8MHz_HF; 
    OSCCON = 0x78;
    // TUN 0; 
    OSCTUNE = 0x00;
    I2C_Master_Init(100000);      //Initialize I2C Master with 100KHz clock
    TMR0_Initialize();
 
}

void DisplayData(void){
    
}

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
	
    // PSA assigned; PS 1:256; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0xD7 & 0x3F)); 
	
    // TMR0 178; 
    TMR0 = 0xB2;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 178;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
}

void TMR0_ISR(void)
{

    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
     // ---------- Glyons ------------
        counter++;
        if(counter==120)
        { 
          counter=0;
         //LED_STATUS_Toggle();
        } 
}

void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}
