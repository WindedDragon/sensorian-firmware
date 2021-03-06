/****************************************************************************
 * Copyright (C) 2015 Sensorian
 *                                                                          *
 * This file is part of Sensorian.                                          *
 *                                                                          *
 *   Sensorian is free software: you can redistribute it and/or modify it   *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Sensorian is distributed in the hope that it will be useful,           *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Sensorian.                                          *
 *   If not, see <http://www.gnu.org/licenses/>.                            *
 ****************************************************************************/
 
/**
 * @file /CAP1203/Example2/CAP1203.h
 * @author D.Qendri
 * @date 28 May 2015
 * @brief CAP1203 driver header.
 */
 
#ifndef __CAP1203_H__
#define __CAP1203_H__

#include "i2c.h"

/*! \def CAP1203ADDR
    \brief The I2C address of the CAP1203 capacitive touch controller
*/
#define CAP1203ADDR				0x28		//0x28 - not shifted

/*****************************Registers**************************/
#define MAIN_CTRL_REG			0x00
#define GEN_STATUS				0x02
#define SENSOR_INPUTS			0x03
#define NOISE_FLAG				0x0A
#define SENS1DELTACOUNT			0x10
#define SENS2DELTACOUNT			0x11
#define SENS3DELTACOUNT			0x12
#define SENSITIVITY				0x1F
#define CONFIG1					0x20
#define SENSINPUTEN				0x21
#define SENSINCONF1				0x22
#define SENSINCONF2				0x23
#define AVERAGE_SAMP_CONF		0x24
#define CAL_ACTIV				0x26
#define INT_ENABLE				0x27
#define REPEAT_RATE				0x28
#define MULTITOUCH				0x2A
#define MULTIPATCONF			0x2B
#define MULTIPATTERN			0x2D
#define BASECOUNT				0x2E
#define RECALCONFIG				0x2F
#define S1THRESHOLD				0x30
#define S2THRESHOLD				0x31
#define S3THRESHOLD				0x32
#define SENSTHRESHOLD			0x38

#define STANDBYCHAN				0x40
#define STANDBYCONF				0x41
#define STANDBY_SENS			0x42
#define STANDBY_THRE			0x43
#define CONFIG2					0x44
#define S1BASECOUNT				0x50
#define S2BASECOUNT				0x51
#define S3BASECOUNT				0x52
#define PWR_BUTTON				0x60
#define PWR_CONFIG				0x61
#define S1INPCAL				0xB1	
#define S2INPCAL				0xB2
#define S3INPCAL				0xB3
#define S1CALLSB				0xB9

#define PRODUCT_ID				0xFD
#define MAN_ID					0xFE
#define REV						0xFF	

/************************MAIN CTRL REG********************************/
#define STBY					0x20
#define SLEEP					0x08
#define INT						0x01
/************************GEN_STATUS REG*******************************/
#define BC_OUT          		0x40
#define ACAL_FAIL       		0x20
#define PWR             		0x10
#define MULT            		0x04
#define MTP             		0x02
#define TOUCH           		0x01

/************************SENSINPUTEN REG*******************************/
#define CS3             		0x04
#define CS2             		0x02
#define CS1             		0x01

/************************SENSINCONF1 REG*******************************/

#define DUR560MS
#define DUR840MS
#define DUR1120MS
#define DUR1400MS
#define DUR1680MS
#define DUR2240MS
#define DUR2800MS
#define DUR3360MS
#define DUR3920MS
#define DUR4480MS
#define DUR5600MS
#define DUR6720MS


#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS
#define REP_35MS

#define M_PRESS35MS
#define M_PRESS70MS
#define M_PRESS105MS
#define M_PRESS140MS
#define M_PRESS175MS
#define M_PRESS210MS
#define M_PRESS2455MS
#define M_PRESS280MS
#define M_PRESS315MS
#define M_PRESS350MS
#define M_PRESS385MS
#define M_PRESS420MS
#define M_PRESS455MS
#define M_PRESS490MS
#define M_PRESS560MS

/*********************Sensitivity Control Register***************************/

//Delta sense controls the sensitivity of a touch detection for sensor inputs enabled in the Active state
#define MOST_SENSITIVE 			0x00
#define DEFAULT					0x20
#define LEAST_SENSITIVE			0x70

/*********************Configuration Register**********************************/
#define TIMEOUT					0x80
#define DIS_DIG_NOISE			0x20
#define DIS_ANA_NOISE			0x10
#define MAX_DUR_EN				0x08


/**********************Averaging and Sampling Configuration Register**********/

#define AVG             0x30            //default value 0b01100000		8 samples
#define SAMP_TIME       0x80            //0b00001000    1.28 ms
#define CYCLE_TIME      0x01

/************************Multiple Touch Configuration**************************/
#define MULTBLK_EN      0x80


/************************Multiple Touch Pattern Configuration**************************/

#define MTP_EN 			0x80
#define MTP_TH1			0x08	
#define MTP_TH0			0x04
#define COMP_PTRN		0x02
#define MTP_ALERT		0x01

/************************Multiple Touch Pattern Register**************************/

#define CS3_PTRN		0x04
#define CS2_PTRN		0x02
#define CS1_PTRN		0x01

/***********************Power Button Configuration****************************/
#define PWR_EN			0x40
#define TIME280ms		0x00
#define TIME560ms		0x01
#define TIME1120ms		0x02
#define TIME2240ms		0x03

/**
 *  Channels that can be used
 */
typedef enum{
/**
 * Channel one
 */
ONE=0x00,
/**
 * Channel two
 */
TWO=0x01,
/**
 * Channel three
 */
THREE=0x02}  touch_type;

/**
 *  Buttons pressed.
 */
typedef enum{
/**
 * Button one.
 */
B1=0x01,
/**
 * Button two.
 */
B2 = 0x02,
/**
 * Button three.
 */
B3= 0x03}  button_type;


/**
 *  Sensitivity options.
 */
typedef enum{
/**
 * Option 1.
 */
S1,
/**
 * Option 2.
 */
S2} sensitivity_type;

void            CAP1203_Initialize(void);
unsigned char   CAP1203_ActiveMode(void);
unsigned char   CAP1203_StandbyMode(void);
unsigned char   CAP1203_DeepSleep(void);
unsigned char   CAP1203_ResumeFromDeepSleep(void);

unsigned char   CAP1203_ReadPressedButton(void);
void            CAP1203_EnableInterrupt(button_type pin);
void            CAP1203_SetSensitivity(sensitivity_type sensitivity);
unsigned char   CAP1203_CheckSensorStatus(void);
unsigned char   CAP1203_ClearInterrupt(void);
unsigned int    CAP1203_ReadID(void);

void            CAP1203_ConfigureMultiTouch(touch_type number,unsigned char chan);
unsigned char 	CAP1203_MultitouchEvent(void);

void            CAP1203_SetPowerButton(button_type button);
unsigned char   CAP1203_ReadPowerButton(void);

unsigned char   CAP1203_GetStatusReg(void);
void            CAP1203_Write(unsigned char reg, unsigned char data);
unsigned char   CAP1203_Read(unsigned char reg);

#endif
