/*! *********************************************************************************
* \addtogroup Immediate Alert Service
* @{
********************************************************************************** */
/*!
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* All rights reserved.
*
* \file immediate_alert_interface.h
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* o Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
*
* o Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
*
* o Neither the name of Freescale Semiconductor, Inc. nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _IMMEDIATE_ALERT_INTERFACE_H_
#define _IMMEDIATE_ALERT_INTERFACE_H_

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public constants & macros
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

typedef uint8_t iasAlertLevel_t;

/*! Immediate Alert Service - Alert Level Values */
typedef enum
{
    gIas_NoAlert_c      = 0x00,
    gIas_MildAlert_c    = 0x01,
    gIas_HighAlert_c    = 0x02
} iasAlertLevel_tag;

/*! Immediate Alert Service - Configuration */
typedef struct iasConfig_tag
{
    uint16_t            serviceHandle;
    iasAlertLevel_t     initialAlertLevel;	
} iasConfig_t;

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!**********************************************************************************
* \brief        Starts Immediate Alert Service functionality
*
* \param[in]    pServiceConfig  Pointer to structure that contains server 
*                               configuration information.
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_Start (iasConfig_t *pServiceConfig);

/*!**********************************************************************************
* \brief        Stops Immediate Alert Service functionality
*
* \param[in]    pServiceConfig  Pointer to structure that contains server 
*                               configuration information.
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_Stop (iasConfig_t *pServiceConfig);

/*!**********************************************************************************
* \brief        Subscribes a GATT client to the Immediate Alert service
*
* \param[in]    clientdeviceId  Client Id in Device DB.
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_Subscribe(deviceId_t clientdeviceId);

/*!**********************************************************************************
* \brief        Unsubscribes the GATT client from the Immediate Alert service
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_Unsubscribe();

/*!**********************************************************************************
* \brief        Gets the alert level value on a specified service.
*
* \param[in]    serviceHandle   Service handle.
* \param[out]   pOutAlertLevel	Pointer to store the alert level value.
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_GetAlertLevel(uint16_t serviceHandle, iasAlertLevel_t *pOutAlertLevel);

/*!**********************************************************************************
* \brief        Sets the alert level value on a specified service.
*
* \param[in]    serviceHandle   Service handle.
* \param[in]    alertLevel		Alert level value.
*
* \return       gBleSuccess_c or error.
************************************************************************************/
bleResult_t Ias_SetAlertLevel(uint16_t serviceHandle, iasAlertLevel_t alertLevel);


#ifdef __cplusplus
}
#endif 

#endif /* _IMMEDIATE_ALERT_INTERFACE_H_ */

/*! *********************************************************************************
* @}
********************************************************************************** */
