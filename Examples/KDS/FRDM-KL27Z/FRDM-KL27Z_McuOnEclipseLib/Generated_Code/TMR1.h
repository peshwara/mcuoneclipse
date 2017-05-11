/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TMR1.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : SDK_Timer
**     Version     : Component 01.014, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-05-11, 18:40, # CodeGen: 149
**     Abstract    :
**
**     Settings    :
**          Component name                                 : TMR1
**          SDK                                            : MCUC1
**          Timer Name                                     : TPM2
**     Contents    :
**         Enable             - void TMR1_Enable(void);
**         Disable            - void TMR1_Disable(void);
**         EnableIRQ          - void TMR1_EnableIRQ(void);
**         DisableIRQ         - void TMR1_DisableIRQ(void);
**         EnableOverflowIRQ  - void TMR1_EnableOverflowIRQ(void);
**         DisableOverflowIRQ - void TMR1_DisableOverflowIRQ(void);
**         SetPeriodTicks     - void TMR1_SetPeriodTicks(uint32_t ticks);
**         SetPeriodUS        - void TMR1_SetPeriodUS(uint32_t us);
**         Init               - void TMR1_Init(void);
**         Deinit             - void TMR1_Deinit(void);
**
**     * Copyright (c) 2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file TMR1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup TMR1_module TMR1 module documentation
**  @{
*/         

#ifndef __TMR1_H
#define __TMR1_H

/* MODULE TMR1. */
#include "MCUC1.h" /* SDK and API used */
#include "TMR1config.h" /* configuration */

#if MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  #error "only SDK v2.x supported"
#endif

void TMR1_OnInterrupt(void); /* event handler prototype */


void TMR1_Init(void);
/*
** ===================================================================
**     Method      :  TMR1_Init (component SDK_Timer)
**     Description :
**         Driver initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_Deinit(void);
/*
** ===================================================================
**     Method      :  TMR1_Deinit (component SDK_Timer)
**     Description :
**         Driver deinitialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_SetPeriodTicks(uint32_t ticks);
/*
** ===================================================================
**     Method      :  TMR1_SetPeriodTicks (component SDK_Timer)
**     Description :
**         Sets the timer period in ticks
**     Parameters  :
**         NAME            - DESCRIPTION
**         ticks           - counter value
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_Disable(void);
/*
** ===================================================================
**     Method      :  TMR1_Disable (component SDK_Timer)
**     Description :
**         Stops the timer from running
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_Enable(void);
/*
** ===================================================================
**     Method      :  TMR1_Enable (component SDK_Timer)
**     Description :
**         Enables the timer for running
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_SetPeriodUS(uint32_t us);
/*
** ===================================================================
**     Method      :  TMR1_SetPeriodUS (component SDK_Timer)
**     Description :
**         Sets the timer period in microseconds
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - number of microseconds
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_EnableIRQ(void);
/*
** ===================================================================
**     Method      :  TMR1_EnableIRQ (component SDK_Timer)
**     Description :
**         Enables the timer NVIC interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_DisableIRQ(void);
/*
** ===================================================================
**     Method      :  TMR1_DisableIRQ (component SDK_Timer)
**     Description :
**         Disables the timer NVIC interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_EnableOverflowIRQ(void);
/*
** ===================================================================
**     Method      :  TMR1_EnableOverflowIRQ (component SDK_Timer)
**     Description :
**         Enables the timer Overflow interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMR1_DisableOverflowIRQ(void);
/*
** ===================================================================
**     Method      :  TMR1_DisableOverflowIRQ (component SDK_Timer)
**     Description :
**         Disables the timer Overflow interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END TMR1. */

#endif
/* ifndef __TMR1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
