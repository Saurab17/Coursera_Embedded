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
 * @file <stats.c> 
 * @brief <A program to find statistical values of a given data. >
 *
 * <This file contains the program to calculate mean, median, max and min values
 *   of a given data set and display the results.>
 *
 * @author <Saurabh Yadav>
 * @date <4 April 2018>
 *
 */




#include "stats.h"

void sort_array(unsigned char stat_array[], int n)
{
  int i,j;
  unsigned char large;
  for(i=0;i<n;i++)
  { large = stat_array[i];
    for(j=i+1;j<n;j++)
    {
      if (large<stat_array[j])
      {
        stat_array[i] = stat_array[j];
        stat_array[j] = large;
        large = stat_array[i];
      }
    }
  }
}

int median(unsigned char stat_array[], int n)
{
  int middle_value;
  sort_array(stat_array,n);
  if (n%2 == 0)
  {
    middle_value = (int)(((int)stat_array[n/2-1]+(int)stat_array[n/2])/2);
  }
  else
  {
    middle_value = (int)(stat_array[(n+1)/2-1]);
  }
  return middle_value;
}

int mean(unsigned char stat_array[], int n)
{
  int i,avg;
  int sum=0;
  for(i=0;i<n;i++)
  {
    sum+=(int)stat_array[i];
  }
  avg = (int)(sum/n);
  return avg;
}

int max(unsigned char stat_array[], int n)
{
  int i;
  unsigned char greatest = stat_array[0];
  for(i=1;i<n;i++)
  {
    if (greatest<stat_array[i])
    {
      greatest = stat_array[i];
    }
  }
  return (int)greatest;
}

int min(unsigned char stat_array[], int n)
{
  int i;
  unsigned char lowest = stat_array[0];
  for(i=1;i<n;i++)
  {
    if (lowest>stat_array[i])
    {
      lowest = stat_array[i];
    }
  }
  return (int)lowest;
}

void print_array(unsigned char stat_array[], int n)
{
  #ifdef VERBOSE
  PRINTF("\nThe data is:");
  for(int i=0;i<n;i++)
  {
    if(i%5==0)
    {
      PRINTF("\n");
    }
    PRINTF("%d ",(int)stat_array[i]);
  }
  #endif
}

void print_statistics(unsigned char stat_array[], int n)
{
  print_array(stat_array,n);
  PRINTF("\n\nMaximum value is: %d",max(stat_array,n));
  PRINTF("\nMinimum value is: %d",min(stat_array,n));
  PRINTF("\nMedian value is: %d",median(stat_array,n));
  PRINTF("\nMean value is: %d\n",mean(stat_array,n));
}
























