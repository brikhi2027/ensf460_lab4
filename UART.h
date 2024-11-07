/*
 * File:   UART.h
 * Author: John Tumacder, Mark Guerta, Bhavna Rikhi
 *
 * Created on November 1, 2024, 2:13 PM
 */
#ifndef UART2s_H
#define	UART2_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void InitUART2(void);
void XmitUART2(char, unsigned int);

void __attribute__ ((interrupt, no_auto_psv)) _U2RXInterrupt(void);
void __attribute__ ((interrupt, no_auto_psv)) _U2TXInterrupt(void); 

void Disp2Hex(unsigned int);
void Disp2Hex32(unsigned long int);
void Disp2String(char*);
void Disp2Dec(unsigned int);

void DispAsterisks(unsigned int);

void DispTesting(unsigned int);

void DispMode1(unsigned int);
#endif	/* UART2_H */

