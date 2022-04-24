#ifndef __HEATER_H__
#define __HEATER_H__

/**
 * @file heater.h
 * @author SAI SHIVA
 * @brief Project to automate Heater
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<avr/io.h>
#include <avr/interrupt.h>

unsigned volatile o_flow;//overflow flag

/**
 * @brief Timer runs for a one minute time given by temp() and during this Heater is OFF by opening Relay
 * 
 */
void tim();

/**
 * @brief function takes C0 pin input which is temperature then calculates time for which heater is ON
 * 
 */
void temp();

/**
 * @brief Timer runs for a particular time given by temp() and during this Heater is ON by closing Relay
 * 
 * @param a1 number of overflows
 * @param b1 number of ticks
 */
void led1(unsigned volatile a1,unsigned volatile b1);

#endif /*__HEATER_H__*/