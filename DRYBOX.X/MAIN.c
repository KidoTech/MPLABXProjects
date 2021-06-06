/*
 * File:   MAIN.c
 * Author: alanlow
 * Reference: https://github.com/kiwih/pic16f877a-ssd1306-oled
 * Created on May 23, 2021, 7:03 AM
 */

#define SSD1306_128_64
#include "I2C.h"
#include "SSD1306.h"
#include "AHT10.h"
#include <xc.h>
#include <PIC16F886.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

//#define _XTAL_FREQ 8000000
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


#define DS1        PORTBbits.RB0       //Blinky
#define DS1_TRIS   TRISBbits.TRISB0    //Blinky-Tri state buffer

//void Setup(void);

void oled_puts(const char* c, uint8_t size) {
    while(*c != '\0') {
        SSD1306_PutStretchC(*c, size);
        c++;
    }
}

void toggle(void){
    if (DS1 == 0){
        DS1 = 1;
    }
    else {
        DS1 = 0;
    }
}

void Setup(void){
    
    // SCS FOSC; SPLLEN disabled; IRCF 8MHz_HF; 
    OSCCON = 0x78;
    // TUN 0; 
    OSCTUNE = 0x00;
    
    __delay_ms(1000);
    I2C_Initialize(100);      //Initialize I2C Master with 100KHz clock
    // clear the display
    AHT10_INIT();
    SSD1306_Init(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
    __delay_ms(500);
    DS1_TRIS = 0;
    DS1 = 0;
    
    return;
}


void main(void) {
    
        unsigned char *p;
    
    Setup();
    SSD1306_ClearDisplay();
    
    while(1) {
        
        DS1 = 0;
        AHT10_MEASURE();
        __delay_ms(100);
        p = AHT10_READ();
        /*
        SSD1306_GotoXY(1,1);
        oled_puts("Our name is: ", 1);
        SSD1306_GotoXY(5,2);
        oled_puts("Low Si Hui,", 1);
        SSD1306_GotoXY(5,3);
        oled_puts("Low Si En, ", 1);
        SSD1306_GotoXY(5,4);
        oled_puts("Yong Mei Leng, ", 1);
        SSD1306_GotoXY(10,5);
        oled_puts("&", 1);
        SSD1306_GotoXY(5,6);
        oled_puts("Low Yong Siah, ", 1);
        */
        SSD1306_GotoXY(1,1);
        oled_puts("The pressure is: ", 1);
        SSD1306_GotoXY(1,2);
        oled_puts(*(p+2),1);
        __delay_ms(1000);
        
        //toggle();
        DS1 = 1;
        __delay_ms(1000);
        SSD1306_ClearDisplay();
    }
    
    return;
}