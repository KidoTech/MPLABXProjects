#include <p18f4520.h>
#include <stdio.h>
#include <stdlib.h>
#include<i2c.h>
#include <xc.h>
#include <htc.h>

///////////////////////////////////////////////////////////////////////////////
// CONFIG1H
#pragma config OSC = INTIO7     // Oscillator Selection bits (Internal oscillator block, CLKO function on RA6, port function on RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)


///////////////////////////////////////////////////////////////////////////////

#define OLED_SETCONTRAST 0x81
#define OLED_DISPLAYALLON_RESUME 0xA4
#define OLED_DISPLAYALLON 0xA5
#define OLED_NORMALDISPLAY 0xA6
#define OLED_INVERTDISPLAY 0xA7
#define OLED_DISPLAYOFF 0xAE
#define OLED_DISPLAYON 0xAF
#define OLED_SETDISPLAYOFFSET 0xD3
#define OLED_SETCOMPINS 0xDA
#define OLED_SETVCOMDETECT 0xDB
#define OLED_SETDISPLAYCLOCKDIV 0xD5
#define OLED_SETPRECHARGE 0xD9
#define OLED_SETMULTIPLEX 0xA8
#define OLED_SETLOWCOLUMN 0x00
#define OLED_SETHIGHCOLUMN 0x10
#define OLED_SETSTARTLINE 0x40
#define OLED_MEMORYMODE 0x20
#define OLED_COLUMNADDR 0x21
#define OLED_PAGEADDR   0x22
#define OLED_COMSCANINC 0xC0
#define OLED_COMSCANDEC 0xC8
#define OLED_SEGREMAP 0xA0
#define OLED_CHARGEPUMP 0x8D

///////////////////////////////////////////////////////////////////////////////

inline void setup();
void I2C_command(unsigned address, unsigned command);
void I2C_data(unsigned address, unsigned data);

int main(int argc, char** argv) {
    SSPADD = 0x10; //400kHz -- I2C clock = FOSC/(4(SSPADD+1))   1
    setup();
    while(1) I2C_command(0x3C, 0x00);
    return (EXIT_SUCCESS);
}

inline void setup() {
    OSCCON |=0b01110000; //Set FOSC to 8MHZ
    TRISC = 0;
    SSPSTATbits.CKE = 1;
    unsigned address = 0x3C;
    OpenI2C(MASTER, SLEW_OFF);
    Delay10TCYx(4);
    I2C_command(address, OLED_DISPLAYOFF);         // 0xAE
    I2C_command(address, OLED_SETDISPLAYCLOCKDIV); // 0xD5
    I2C_command(address, 0x80);                    // the suggested ratio 0x80
    I2C_command(address, OLED_SETMULTIPLEX);       // 0xA8
    I2C_command(address, 0x1F);
    I2C_command(address, OLED_SETDISPLAYOFFSET);   // 0xD3
    I2C_command(address, 0x0);                        // no offset
    I2C_command(address, OLED_SETSTARTLINE | 0x0); // line #0
    I2C_command(address, OLED_CHARGEPUMP);         // 0x8D
    I2C_command(address, 0xAF);
    I2C_command(address, OLED_MEMORYMODE);         // 0x20
    I2C_command(address, 0x00);                    // 0x0 act like ks0108
    I2C_command(address, OLED_SEGREMAP | 0x1);
    I2C_command(address, OLED_COMSCANDEC);
    I2C_command(address, OLED_SETCOMPINS);         // 0xDA
    I2C_command(address, 0x02);
    I2C_command(address, OLED_SETCONTRAST);        // 0x81
    I2C_command(address, 0x8F);
    I2C_command(address, OLED_SETPRECHARGE);       // 0xd9
    I2C_command(address, 0xF1);
    I2C_command(address, OLED_SETVCOMDETECT);      // 0xDB
    I2C_command(address, 0x40);
    I2C_command(address, OLED_DISPLAYALLON_RESUME);// 0xA4
    I2C_command(address, OLED_NORMALDISPLAY);      // 0xA6
    I2C_command(address, OLED_DISPLAYON);          //--turn on oled panel
    
}

void I2C_command(unsigned address, unsigned command) {

    SSPCON2bits.SEN=1;while(SSPCON2bits.SEN);//StartI2C();
    putcI2C(address); //send address
    putcI2C(0x00); //send data incomming
    putcI2C(command); //send command
    SSPCON2bits.PEN=1;while(SSPCON2bits.PEN); //StopI2C();
}