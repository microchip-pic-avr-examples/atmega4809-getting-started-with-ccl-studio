/**
* \file main.c
*
* \brief Main source file.
*
(c) 2021 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use this software and
    any derivatives exclusively with Microchip products. It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*
*/
#include <avr/io.h>

void PORT_init (void);
void CCL_init(void);

/**
 * \brief Initialize ports
 */
void PORT_init (void)
{

    PORTA.DIR &= ~PIN0_bm;         //PA0 - LUT0 IN[0]
    PORTA.DIR &= ~PIN1_bm;         //PA1 - LUT0 IN[1]
    PORTC.DIR &= ~PIN0_bm;         //PC0 - LUT1 IN[0]
    PORTC.DIR &= ~PIN1_bm;         //PC0 - LUT1 IN[1]
    PORTC.DIR &= ~PIN2_bm;         //PC0 - LUT1 IN[2]

    PORTA.DIR |= PIN3_bm;			//PA3 - LUT0 output
 
}

/**
 * \brief Initialize CCL peripheral
 */
void CCL_init(void)
{

//configure inputs for used LUTs
	CCL.LUT0CTRLB = CCL_INSEL0_IO_gc    /* IO pin LUTn-IN0 input source */
	                | CCL_INSEL1_IO_gc; /* IO pin LUTn-IN1 input source */
	CCL.LUT0CTRLC = CCL_INSEL2_LINK_gc; /* Linked LUT input source */

	CCL.LUT1CTRLB = CCL_INSEL0_IO_gc    /* IO pin LUTn-IN0 input source */
	                | CCL_INSEL1_IO_gc; /* IO pin LUTn-IN1 input source */
	CCL.LUT1CTRLC = CCL_INSEL2_IO_gc;   /* IO pin LUTn-IN2 input source */
	
//Configure Truth Tables
	CCL.TRUTH0 = 0x40; /* Truth 0: 64 */
	CCL.TRUTH1 = 0x20; /* Truth 1: 32 */
	
//Enable LUT0 output on IO pin
    CCL.LUT0CTRLA = CCL_OUTEN_bm;     /* Output Enable: enabled */

//Enable LUTs
	CCL.LUT0CTRLA |= CCL_ENABLE_bm;    /* LUT Enable: enabled */
	CCL.LUT1CTRLA = CCL_ENABLE_bm;    /* LUT Enable: enabled */

	
//Enable CCL module
	CCL.CTRLA = CCL_ENABLE_bm;         /* Enable: enabled */
}


int main(void)
{
    PORT_init();
    CCL_init();
    while (1) 
    {
        ;		
    }
}