/*
 * File:   main.c
 * Author: alanlow
 *
 * Created on March 31, 2021, 11:30 AM
 */


#include <xc.h>
#include <PIC16F886.h>


void delay(void) {
    
    unsigned int i;
    
    for (i=0; i<=30000; i++);
}


void main(void) {

    int tmp = 0x01;
    
    TRISB = 0x00;
    PORTB = 0xFF;    
    return;
}
