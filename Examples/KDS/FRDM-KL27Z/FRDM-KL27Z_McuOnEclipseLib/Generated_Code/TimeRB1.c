/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TimeRB1.c
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
** @file TimeRB1.c
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup TimeRB1_module TimeRB1 module documentation
**  @{
*/         

/* MODULE TimeRB1. */

#include "TimeRB1.h"

#if TimeRB1_CONFIG_REENTRANT
  #define TimeRB1_DEFINE_CRITICAL() CS1_CriticalVariable()
  #define TimeRB1_ENTER_CRITICAL()  CS1_EnterCritical()
  #define TimeRB1_EXIT_CRITICAL()   CS1_ExitCritical()
#else
  #define TimeRB1_DEFINE_CRITICAL() /* nothing */
  #define TimeRB1_ENTER_CRITICAL()  /* nothing */
  #define TimeRB1_EXIT_CRITICAL()   /* nothing */
#endif
static TimeRB1_ElementType TimeRB1_buffer[TimeRB1_CONFIG_BUF_SIZE]; /* ring buffer */
static TimeRB1_BufSizeType TimeRB1_inIdx;  /* input index */
static TimeRB1_BufSizeType TimeRB1_outIdx; /* output index */
static TimeRB1_BufSizeType TimeRB1_inSize; /* size data in buffer */
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
uint8_t TimeRB1_Put(TimeRB1_ElementType elem)
{
  uint8_t res = ERR_OK;
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  if (TimeRB1_inSize==TimeRB1_CONFIG_BUF_SIZE) {
    res = ERR_TXFULL;
  } else {
    TimeRB1_buffer[TimeRB1_inIdx] = elem;
    TimeRB1_inIdx++;
    if (TimeRB1_inIdx==TimeRB1_CONFIG_BUF_SIZE) {
      TimeRB1_inIdx = 0;
    }
    TimeRB1_inSize++;
  }
  TimeRB1_EXIT_CRITICAL();
  return res;
}

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
uint8_t TimeRB1_Putn(TimeRB1_ElementType *elem, TimeRB1_BufSizeType nof)
{
  uint8_t res = ERR_OK;

  while(nof>0) {
    res = TimeRB1_Put(*elem);
    if (res!=ERR_OK) {
      break;
    }
    elem++; nof--;
  }
  return res;
}

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
uint8_t TimeRB1_Get(TimeRB1_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  if (TimeRB1_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    *elemP = TimeRB1_buffer[TimeRB1_outIdx];
    TimeRB1_inSize--;
    TimeRB1_outIdx++;
    if (TimeRB1_outIdx==TimeRB1_CONFIG_BUF_SIZE) {
      TimeRB1_outIdx = 0;
    }
  }
  TimeRB1_EXIT_CRITICAL();
  return res;
}

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
uint8_t TimeRB1_Getn(TimeRB1_ElementType *buf, TimeRB1_BufSizeType nof)
{
  uint8_t res = ERR_OK;

  while(nof>0) {
    res = TimeRB1_Get(buf);
    if (res!=ERR_OK) {
      break;
    }
    buf++; nof--;
  }
  return res;
}

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
TimeRB1_BufSizeType TimeRB1_NofElements(void)
{
  return TimeRB1_inSize;
}

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
TimeRB1_BufSizeType TimeRB1_NofFreeElements(void)
{
  return (TimeRB1_BufSizeType)(TimeRB1_CONFIG_BUF_SIZE-TimeRB1_inSize);
}

/*
** ===================================================================
**     Method      :  TimeRB1_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TimeRB1_Init(void)
{
  TimeRB1_inIdx = 0;
  TimeRB1_outIdx = 0;
  TimeRB1_inSize = 0;
}

/*
** ===================================================================
**     Method      :  TimeRB1_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TimeRB1_Clear(void)
{
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  TimeRB1_Init();
  TimeRB1_EXIT_CRITICAL();
}

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
uint8_t TimeRB1_Peek(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  int idx; /* index inside ring buffer */
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  if (index>=TimeRB1_CONFIG_BUF_SIZE) {
    res = ERR_OVERFLOW; /* asking for an element outside of ring buffer size */
  } else if (index<TimeRB1_inSize) {
    idx = (TimeRB1_outIdx+index)%TimeRB1_CONFIG_BUF_SIZE;
    *elemP = TimeRB1_buffer[idx];
  } else { /* asking for an element which does not exist */
    res = ERR_RXEMPTY;
  }
  TimeRB1_EXIT_CRITICAL();
  return res;
}

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
uint8_t TimeRB1_Compare(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP, TimeRB1_BufSizeType nof)
{
  uint8_t cmpResult = 0;
  uint8_t res;
  TimeRB1_ElementType val;

  while(nof>0) {
    res = TimeRB1_Peek(index, &val);
    if (res!=ERR_OK) { /* general failure? */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    if (val!=*elemP) { /* mismatch */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    elemP++; index++; nof--;
  }

  return cmpResult;
}

/*
** ===================================================================
**     Method      :  TimeRB1_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/**
void TimeRB1_Deinit(void)
{
  ** Function is implemented as macro in the header file
}
*/
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
uint8_t TimeRB1_Delete(void)
{
  uint8_t res = ERR_OK;
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  if (TimeRB1_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    TimeRB1_inSize--;
    TimeRB1_outIdx++;
    if (TimeRB1_outIdx==TimeRB1_CONFIG_BUF_SIZE) {
      TimeRB1_outIdx = 0;
    }
  }
  TimeRB1_EXIT_CRITICAL();
  return res;
}

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
uint8_t TimeRB1_Update(TimeRB1_BufSizeType index, TimeRB1_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  int idx; /* index inside ring buffer */
  TimeRB1_DEFINE_CRITICAL();

  TimeRB1_ENTER_CRITICAL();
  if (index>=TimeRB1_CONFIG_BUF_SIZE) {
    res = ERR_OVERFLOW; /* asking for an element outside of ring buffer size */
  } else if (index<TimeRB1_inSize) {
    idx = (TimeRB1_outIdx+index)%TimeRB1_CONFIG_BUF_SIZE;
    TimeRB1_buffer[idx] = *elemP; /* replace element */
  } else { /* asking for an element which does not exist */
    res = ERR_RXEMPTY;
  }
  TimeRB1_EXIT_CRITICAL();
  return res;
}

/* END TimeRB1. */

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
