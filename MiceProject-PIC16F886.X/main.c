/*
 * File:   main.c
 * Author: alanlow
 *
 * Created on April 10, 2021, 7:27 PM
 */

#include <xc.h>
//#include <PIC16F886.h>


// BEGIN CONFIG
//#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
//#pragma config FOSC = 0x4   // Allow pins use for OSC input as GPIO
//#pragma config IRCF = 0x7   // Run Internal oscilator at 8MHz
//#pragma config SCS = ON     // Select system clock run from internal oscillator
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
#define C1          PORTBbits.RB1       // Switch matrix Col 1
#define C1_TRIS     TRISBbits.TRISB1    // Switch matrix Col 1 tri-state buffer
#define C2          PORTCbits.RC2       // Switch matrix Col 1
#define C2_TRIS     TRISCbits.TRISC2    // Switch matrix Col 1 tri-state buffer
#define C3          PORTCbits.RC5       // Switch matrix Col 1
#define C3_TRIS     TRISCbits.TRISC5    // Switch matrix Col 1 tri-state buffer
#define LFT         PORTBbits.RB3       // IR Sensor Left
#define LFT_TRIS    TRISBbits.TRISB3    // IR Sensor Left tri-sate buffer
#define FRT         PORTBbits.RB2       // IR Sensor Front
#define FRT_TRIS    TRISBbits.TRISB2    // IR Sensor Front tri-state buffer
#define RHT         PORTBbits.RB4       // IR Sensor Right
#define RHT_TRIS    TRISBbits.TRISB4    // IR Sensor Right tri-state buffer 


// PIC16F886 Configuration Bit Settings
// 'C' source line config statements
// CONFIG1
//#pragma config FOSC = EXTRC_CLKOUT// Oscillator Selection bits (RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
//#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
//#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
//#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
//#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
//#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
//#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
//#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
//#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
//#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
//#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
//#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

/*void high_priority interrupt tcInt(void)
{
 // process other interrupt sources here, if required
 return;
}
*/

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
       // __delay_ms(1000);
    }
            
    return;
}
