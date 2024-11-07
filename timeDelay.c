/*
 * File:   TimeDelay.c
 * Author: John Tumacder, Mark Guerta, Bhavna Rikhi
 *
 * Created on November 1, 2024, 2:13 PM
 */
#include "timeDelay.h"
#include <stdio.h>

extern uint16_t interruptTimerFlag;

// Timer2 delay function implementation

void delayTimer(uint16_t time_ms) {
    uint16_t prescaler;
    if (time_ms == 1){
        T2CONbits.TCKPS = 0;
        prescaler = 8;
    } else {
        T2CONbits.TCKPS = 3;
        prescaler = 256;
    }
    T2CONbits.TCS = 0; 

    IPC1bits.T2IP = 1; 
    IEC0bits.T2IE = 1; 
    T2CONbits.TSIDL = 0;
    IFS0bits.T2IF = 0; 

    PR2 = (uint16_t) (time_ms / ((2.0 / 500) * prescaler));
    TMR2 = 0; 

    T2CONbits.TON = 1;
    Idle();
    T2CONbits.TON = 0; 
    return;
}

