/******************************************************************************
 * Copyright (C) 2017 by Saurabh Yadav - IITRAM, Ahmedabad.
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Saurabh Yadav and the IITRAM are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
  * This implementation file provides a way to convert integer to ASCII codes
 * and vice versa via function calls.
 *
 * @author Saurabh Yadav
 * @date April 4 2018
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stddef.h>
#include <stdint.h>
#include "platform.h"
/**
 * @brief Converts number into equivalent ASCII value 
 *
 * Given a unsigned integer number (0 to 15), this will return the corresponding 
 * ASCII code for the number.
 *
 * @param x: The number to convert into ASCII code.
 *
 * @return : The ASCII code of x.
 */
uint8_t conv_to_ASCII(uint8_t x);


/**
 * @brief Converts ASCII code into equivalent number. 
 *
 * Given a ASCII code, this will return the corresponding number (0 to 15).
 *
 * @param x: The ASCII code to convert.
 *
 * @return : The number corresponding to the code.
 */
uint8_t conv_from_ASCII(uint8_t x);


/**
 * @brief Converts integer data into an ASCII string. 
 *
 * Given a standard signed integer, this will return the corresponding ASCII
 * coded string with null termination at the end of string.
 *
 * @param data: The signed integer to convert.
 * @param ptr: The pointer pointing to start of ASCII string.
 * @param base: The base (2 to 16) of number.
 *
 * @return : The length of string including sign and null termination.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Computes integer number from ASCII string. 
 *
 * Given a ASCII string and length, this will return the computed
 * signed integer.
 *
 * @param digits: The length of the string.
 * @param ptr: The pointer pointing to start of ASCII string.
 * @param base: The base (2 to 16) of number.
 *
 * @return : The computed signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */












