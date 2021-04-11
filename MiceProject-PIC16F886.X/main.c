/*
 * File:   main.c
 * Author: alanlow
 *
 * Created on April 10, 2021, 7:27 PM
 */

#include <xc.h>
#include <PIC16F886.h>


// BEGIN CONFIG
//#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config FOSC = INTOSCIO // Allow pins use for OSC input as GPIO
#pragma config IRCF = HFINTOSC // Run Internal oscilator at 8MHz
#pragma config SCS = ON // Select system clock run from internal oscillator
#pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#define MOT         PORTA               // Stepper motor control port
#define MOT_TRIS    TRISA               // Stepper motor port tri-state buffer
#define LED         PORTBbits.RB5       // System Status LED 
#define LED_TRIS    TRISBbits.TRISB5    // System Status LED tri-state buffer
#define R1          PORTBbits.RB7       // Switch matrix Row 1
#define R1_TRIS     TRISBbits.TRISB7    // Switch matrix Row 1 tri-sate buffer
#define R2          PORTBbits.RB6       // Switch matrix Row 2
#define R2_TRIS     TRISBbits.TRISB6    // Switch matrix Row 2 tri-state buffer



void interrupt isr()
{
    //reset the interrupt flag
    //INTCONbits.INTF = 0;
}

void SYS_Init(void){
    
    
    // Setup System Clock
    //Clock already setup as above
    
    
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
    
    
    while(1){
        __delay_ms(1000);
    }
            
    return;
}
