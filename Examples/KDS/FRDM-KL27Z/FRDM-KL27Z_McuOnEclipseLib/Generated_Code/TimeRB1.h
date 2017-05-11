/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TimeRB1.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : RingBuffer
**     Version     : Component 01.051, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-05-11, 11:56, # CodeGen: 137
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : TimeRB1
**          SDK                                            : MCUC1
**          Reentrant                                      : yes
**          Critical Section                               : CS1
**          Buffer Elements                                : 4
**          Element Size                                   : 2 Bytes
**     Contents    :
**         Clear           - void TimeRB1_Clear(void);
**         Put             - uint8_t TimeRB1_Put(TimeRB1_ElementType elem);
**         Get             - uint8_t TimeRB1_Get(TimeRB1_ElementType *elemP);
**         Peek            - uint8_t TimeRB1_Peek(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP);
**         Update          - uint8_t TimeRB1_Update(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP);
**         Putn            - uint8_t TimeRB1_Putn(TimeRB1_ElementType *elem, TimeRB1_BufSizeType nof);
**         Getn            - uint8_t TimeRB1_Getn(TimeRB1_ElementType *buf, TimeRB1_BufSizeType nof);
**         Compare         - uint8_t TimeRB1_Compare(TimeRB1_BufSizeType index, TimeRB1_ElementType...
**         Delete          - uint8_t TimeRB1_Delete(void);
**         NofElements     - TimeRB1_BufSizeType TimeRB1_NofElements(void);
**         NofFreeElements - TimeRB1_BufSizeType TimeRB1_NofFreeElements(void);
**         Deinit          - void TimeRB1_Deinit(void);
**         Init            - void TimeRB1_Init(void);
**
**     * Copyright (c) 2014-2017, Erich Styger
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
** @file TimeRB1.h
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup TimeRB1_module TimeRB1 module documentation
**  @{
*/         

#ifndef __TimeRB1_H
#define __TimeRB1_H

/* MODULE TimeRB1. */
#include "MCUC1.h" /* SDK and API used */
#include "TimeRB1config.h" /* configuration */

/* Include inherited components */
#include "MCUC1.h"
#include "CS1.h"


#if TimeRB1_CONFIG_ELEM_SIZE==1
  typedef uint8_t TimeRB1_ElementType; /* type of single element */
#elif TimeRB1_CONFIG_ELEM_SIZE==2
  typedef uint16_t TimeRB1_ElementType; /* type of single element */
#elif TimeRB1_CONFIG_ELEM_SIZE==4
  typedef uint32_t TimeRB1_ElementType; /* type of single element */
#else
  #error "illegal element type size in properties"
#endif
#if TimeRB1_CONFIG_BUF_SIZE<256
  typedef uint8_t TimeRB1_BufSizeType; /* up to 255 elements (index 0x00..0xff) */
#else
  typedef uint16_t TimeRB1_BufSizeType; /* more than 255 elements, up to 2^16 */
#endif

uint8_t TimeRB1_Put(TimeRB1_ElementType elem);
/*
** ===================================================================
**     Method      :  TimeRB1_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TimeRB1_Get(TimeRB1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  TimeRB1_Get (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

TimeRB1_BufSizeType TimeRB1_NofElements(void);
/*
** ===================================================================
**     Method      :  TimeRB1_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void TimeRB1_Init(void);
/*
** ===================================================================
**     Method      :  TimeRB1_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

TimeRB1_BufSizeType TimeRB1_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  TimeRB1_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void TimeRB1_Clear(void);
/*
** ===================================================================
**     Method      :  TimeRB1_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t TimeRB1_Peek(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  TimeRB1_Peek (component RingBuffer)
**     Description :
**         Returns an element of the buffer without removiing it.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define TimeRB1_Deinit() \
   /* nothing to deinitialize */
/*
** ===================================================================
**     Method      :  TimeRB1_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t TimeRB1_Delete(void);
/*
** ===================================================================
**     Method      :  TimeRB1_Delete (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TimeRB1_Putn(TimeRB1_ElementType *elem, TimeRB1_BufSizeType nof);
/*
** ===================================================================
**     Method      :  TimeRB1_Putn (component RingBuffer)
**     Description :
**         Put a number new element into the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elem            - Pointer to new elements to be put into
**                           the buffer
**         nof             - number of elements
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TimeRB1_Compare(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP, TimeRB1_BufSizeType nof);
/*
** ===================================================================
**     Method      :  TimeRB1_Compare (component RingBuffer)
**     Description :
**         Compares the elements in the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to elements to compare with
**         nof             - number of elements to compare
**     Returns     :
**         ---             - zero if elements are the same, -1 otherwise
** ===================================================================
*/

uint8_t TimeRB1_Getn(TimeRB1_ElementType *buf, TimeRB1_BufSizeType nof);
/*
** ===================================================================
**     Method      :  TimeRB1_Getn (component RingBuffer)
**     Description :
**         Get a number elements into a buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buf             - Pointer to buffer where to store the
**                           elements
**         nof             - number of elements
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TimeRB1_Update(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  TimeRB1_Update (component RingBuffer)
**     Description :
**         Updates the data of an element.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END TimeRB1. */

#endif
/* ifndef __TimeRB1_H */
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
