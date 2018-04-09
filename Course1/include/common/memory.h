/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief This file does some very basic data manipulation
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Saurabh Yadav
 * @date April 5 2018
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h>
#include <stdlib.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a length of bytes from source to destination
 *
 * Given pointers to source and destination addresses and length of bytes,
 * this function will move the data bytes from source to destination 
 * address without any data corruption. Returns destination address
 *
 * @param src Pointer to source location
 * @param dst Pointer to destination location
 * @param length Number of bytes to move
 *
 * @return dest The destination address pointer.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Moves a length of bytes from source to destination
 *
 * Given pointers to source and destination addresses and length of bytes,
 * this function will move the data bytes from source to destination 
 * address. This function doesn't handle the case when distance between
 * two addresses is less than length of bytes to move. Hence data corruption
 * may occur.
 *
 * @param src Pointer to source location
 * @param dst Pointer to destination location
 * @param length Number of bytes to move
 *
 * @return dest The destination address pointer.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a length of bytes to given value
 *
 * Given pointer to source address,length of bytes, this function sets
 * those length of bytes starting from source address to a given value. 
 * Returns the source address.
 *
 * @param src Pointer to source location
 * @param value Value to set
 * @param length Number of bytes
 *
 * @return sour The source address pointer.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a length of bytes to zero.
 *
 * Given pointer to source address,length of bytes, this function sets
 * those length of bytes starting from source address to zero. 
 * Returns the source address.
 *
 * @param src Pointer to source location
 * @param length Number of bytes
 *
 * @return sour The source address pointer.
**/
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses a length of bytes.
 *
 * Given pointer to source address,length of bytes, this function reverses
 * the order of value stored by those bytes. Returns the source address.
 *
 * @param src Pointer to source location
 * @param length Number of bytes
 *
 * @return sour The source address pointer.
**/
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Dynamic memory allocation.
 *
 * Given a length of words, this function allocates that many bytes in dynamic
 * memory. Return the pointer to start address of allocated memory.
 
 * @param length Number of words
 *
 * @return ptr The start address of allocated dynamic memory.
**/
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamically allocated memory.
 *
 * Given a pointer to dynamic memory address, it frees the memory.
 
 * @param src Pointer to memory
 *
 * @return void.
**/
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
