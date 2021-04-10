/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LFT_ORG aliases
#define LFT_ORG_TRIS                 TRISAbits.TRISA0
#define LFT_ORG_LAT                  LATAbits.LATA0
#define LFT_ORG_PORT                 PORTAbits.RA0
#define LFT_ORG_WPU                  WPUAbits.WPUA0
#define LFT_ORG_OD                   ODCONAbits.ODCA0
#define LFT_ORG_ANS                  ANSELAbits.ANSELA0
#define LFT_ORG_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LFT_ORG_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LFT_ORG_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LFT_ORG_GetValue()           PORTAbits.RA0
#define LFT_ORG_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LFT_ORG_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LFT_ORG_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LFT_ORG_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LFT_ORG_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LFT_ORG_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LFT_ORG_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LFT_ORG_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LFT_YEL aliases
#define LFT_YEL_TRIS                 TRISAbits.TRISA1
#define LFT_YEL_LAT                  LATAbits.LATA1
#define LFT_YEL_PORT                 PORTAbits.RA1
#define LFT_YEL_WPU                  WPUAbits.WPUA1
#define LFT_YEL_OD                   ODCONAbits.ODCA1
#define LFT_YEL_ANS                  ANSELAbits.ANSELA1
#define LFT_YEL_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LFT_YEL_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LFT_YEL_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LFT_YEL_GetValue()           PORTAbits.RA1
#define LFT_YEL_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LFT_YEL_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LFT_YEL_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LFT_YEL_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LFT_YEL_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LFT_YEL_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LFT_YEL_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LFT_YEL_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LFT_PNK aliases
#define LFT_PNK_TRIS                 TRISAbits.TRISA2
#define LFT_PNK_LAT                  LATAbits.LATA2
#define LFT_PNK_PORT                 PORTAbits.RA2
#define LFT_PNK_WPU                  WPUAbits.WPUA2
#define LFT_PNK_OD                   ODCONAbits.ODCA2
#define LFT_PNK_ANS                  ANSELAbits.ANSELA2
#define LFT_PNK_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LFT_PNK_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LFT_PNK_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LFT_PNK_GetValue()           PORTAbits.RA2
#define LFT_PNK_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LFT_PNK_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LFT_PNK_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LFT_PNK_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LFT_PNK_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LFT_PNK_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LFT_PNK_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LFT_PNK_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LFT_BLU aliases
#define LFT_BLU_TRIS                 TRISAbits.TRISA3
#define LFT_BLU_LAT                  LATAbits.LATA3
#define LFT_BLU_PORT                 PORTAbits.RA3
#define LFT_BLU_WPU                  WPUAbits.WPUA3
#define LFT_BLU_OD                   ODCONAbits.ODCA3
#define LFT_BLU_ANS                  ANSELAbits.ANSELA3
#define LFT_BLU_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LFT_BLU_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LFT_BLU_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LFT_BLU_GetValue()           PORTAbits.RA3
#define LFT_BLU_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LFT_BLU_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LFT_BLU_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LFT_BLU_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LFT_BLU_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LFT_BLU_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LFT_BLU_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LFT_BLU_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RHT_ORG aliases
#define RHT_ORG_TRIS                 TRISAbits.TRISA4
#define RHT_ORG_LAT                  LATAbits.LATA4
#define RHT_ORG_PORT                 PORTAbits.RA4
#define RHT_ORG_WPU                  WPUAbits.WPUA4
#define RHT_ORG_OD                   ODCONAbits.ODCA4
#define RHT_ORG_ANS                  ANSELAbits.ANSELA4
#define RHT_ORG_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RHT_ORG_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RHT_ORG_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RHT_ORG_GetValue()           PORTAbits.RA4
#define RHT_ORG_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RHT_ORG_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RHT_ORG_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RHT_ORG_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RHT_ORG_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RHT_ORG_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RHT_ORG_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RHT_ORG_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RHT_YEL aliases
#define RHT_YEL_TRIS                 TRISAbits.TRISA5
#define RHT_YEL_LAT                  LATAbits.LATA5
#define RHT_YEL_PORT                 PORTAbits.RA5
#define RHT_YEL_WPU                  WPUAbits.WPUA5
#define RHT_YEL_OD                   ODCONAbits.ODCA5
#define RHT_YEL_ANS                  ANSELAbits.ANSELA5
#define RHT_YEL_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RHT_YEL_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RHT_YEL_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RHT_YEL_GetValue()           PORTAbits.RA5
#define RHT_YEL_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RHT_YEL_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RHT_YEL_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RHT_YEL_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RHT_YEL_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RHT_YEL_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RHT_YEL_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RHT_YEL_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RHT_PNK aliases
#define RHT_PNK_TRIS                 TRISAbits.TRISA6
#define RHT_PNK_LAT                  LATAbits.LATA6
#define RHT_PNK_PORT                 PORTAbits.RA6
#define RHT_PNK_WPU                  WPUAbits.WPUA6
#define RHT_PNK_OD                   ODCONAbits.ODCA6
#define RHT_PNK_ANS                  ANSELAbits.ANSELA6
#define RHT_PNK_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RHT_PNK_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RHT_PNK_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RHT_PNK_GetValue()           PORTAbits.RA6
#define RHT_PNK_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RHT_PNK_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RHT_PNK_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define RHT_PNK_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define RHT_PNK_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define RHT_PNK_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define RHT_PNK_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define RHT_PNK_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RHT_BLU aliases
#define RHT_BLU_TRIS                 TRISAbits.TRISA7
#define RHT_BLU_LAT                  LATAbits.LATA7
#define RHT_BLU_PORT                 PORTAbits.RA7
#define RHT_BLU_WPU                  WPUAbits.WPUA7
#define RHT_BLU_OD                   ODCONAbits.ODCA7
#define RHT_BLU_ANS                  ANSELAbits.ANSELA7
#define RHT_BLU_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RHT_BLU_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RHT_BLU_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RHT_BLU_GetValue()           PORTAbits.RA7
#define RHT_BLU_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RHT_BLU_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RHT_BLU_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define RHT_BLU_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define RHT_BLU_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define RHT_BLU_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define RHT_BLU_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RHT_BLU_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/