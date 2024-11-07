/*
 * File:   IOCheck.c
 * Author: Mark Guerta, John Tumacder, Bhavna Rikhi
 * 
 * Created on November 1, 2024, 2:13 PM
 */

#include "xc.h"
#include "math.h"
#include "string.h"
#include "IOCheck.h"
#include "PotCheck.h"
#include "UART.h"
#include "timeDelay.h"
#include <p24F16KA101.h>


extern uint16_t PB1_event;
extern uint16_t PB1_state;

extern uint16_t programMode;
extern uint16_t outputMode1;
#define MODE0 0
#define MODE1 1


uint16_t tempPotOutput = 0;

#define LED LATBbits.LATB8

extern uint16_t interruptTimerFlag;

void IOinit(){
    AD1PCFG = 0xFFFF;
//    TRISBbits.TRISB8 = 0;
//    LATBbits.LATB8 = 0;
//    TRISAbits.TRISA4 = 1; //pb3 stuff
//    CNEN1bits.CN0IE = 1;
//    CNPU1bits.CN0PUE = 1;
//    
//    TRISBbits.TRISB4 = 1; //pb2 stuff
//    CNEN1bits.CN1IE = 1;
//    CNPU1bits.CN1PUE = 1;
    
    TRISAbits.TRISA2 = 1; // pb1 stuff
    CNEN2bits.CN30IE = 1;
    CNPU2bits.CN30PUE = 1;
    
    AD1CON1bits.ADON = 0b1;
    AD1CON1bits.FORM = 0b00;
    
    
    IPC4bits.CNIP = 6;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    
    T2CONbits.T32 = 0; 

}

void IOcheck(){
    // pb1 events
    if (programMode == MODE0) {
//        AD1CON1bits.SAMP=1; //Stop sampling
//        AD1CON1bits.ADON=1; //Turn off ADC, ADC value stored in ADC1BUF0;
        Disp2String("\r");
        tempPotOutput = do_ADC();
        //DispTesting(tempPotOutput);
        DispAsterisks(tempPotOutput);
        delayTimer(500);
    } else {
        Disp2String("\rMode 1\n");
        
        while (outputMode1 == 1){
            tempPotOutput = do_ADC();
            DispMode1(tempPotOutput);
            delayTimer(250);
        }
        
    }

    
    
    
}
