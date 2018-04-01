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
 * @file <stats.h> 
 * @brief <stats.c header file >
 *
 * <File containing function prototypes and function documentation for statistics program>
 *
 * @author <Saurabh Yadav>
 * @date <18th March 2018>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
*   @brief Print the statistics of an array.
*   This function takes input char array and its size of type int.
*   It then calls functions to calculate mean, median, min, max values and prints them.
*
*   @param statarray: Char array of numbers whose stats are to be printed.
*   @param n: The size of array.
*   @return : Doesn't return a value.
*
**/void print_statistics(unsigned char stat_array[], int n); 

/**
*   @brief Prints an array.
*   Given an array of data and its length, it prints its values.
*
*   @param stat_array: Char array of numbers to be printed.
*   @param n: The size of array.
*   @return : Doesn't return a value.
*
**/void print_array(unsigned char stat_array[], int n);

/**
*   @brief Sorts an array.
*   Given an array of data and its length, it sorts it in descending order.
*
*   @param stat_array: Char array of numbers to be sorted.
*   @param n: The size of array.
*   @return : No return, only sorting the array.
*
**/void sort_array(unsigned char stat_array[], int n);

/**
*   @brief Finds median of an array of numbers.
*   Given an array of data and its length, it finds the median value.
*
*   @param stat_array: Char array of numbers to be sorted.
*   @param n: The size of array.
*   @return : Returns median value as integer.
*
**/int median(unsigned char stat_array[], int n);

/**
*   @brief Finds mean of an array of numbers.
*   Given an array of data and its length, it finds the mean value.
*
*   @param stat_array: Char array of numbers.
*   @param n: The size of array.
*   @return : Returns mean value as integer.
*
**/int mean(unsigned char stat_array[], int n);

/**
*   @brief Finds maximum value of an array of numbers.
*   Given an array of data and its length, it finds the maximum value.
*
*   @param stat_array: Char array of numbers.
*   @param n: The size of array.
*   @return : Returns maximum value.
*
**/int max(unsigned char stat_array[], int n);

/**
*   @brief Finds minimum value of an array of numbers.
*   Given an array of data and its length, it finds the minimum value.
*
*   @param stat_array: Char array of numbers.
*   @param n: The size of array.
*   @return : Returns minimum value.
*
**/int min(unsigned char stat_array[], int n);
#endif /* __STATS_H__ */
