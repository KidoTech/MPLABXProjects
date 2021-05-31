/*
 * File:   main.c
 * Author: alanlow
 *
 * Created on March 31, 2021, 11:30 AM
 */


#include "oled.h"
#include "I2C.h"
#include <xc.h>
#include <PIC16F886.h>
#include <stdbool.h>
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
#define I2C_SDA_TRIS    TRISbits.TRISC4    // I2C SDA tri-state buffer

void Setup(void);
void DisplayData(void);

void main(void) {

 
    I2C_Init();
    return;
}
