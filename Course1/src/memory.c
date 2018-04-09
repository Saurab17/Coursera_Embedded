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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Saurabh Yadav
 * @date April 5 2018
 *
 */
#include "memory.h"


/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * dest = dst;                //Track the target destination.
	int i;
	size_t dist;
	if (dst>src){
		dist = (dst-src);
		if (dist>length){
			for(i=0;i<length;i++){
				*dst = *src;
				dst++;
				src++;		
			}
		
			return dest;	        
		}	
		else {
			size_t diff = length-dist;
			uint8_t * tran = dst+length;
			for(i=0;i<diff;i++){       //Copying overlapping contents to other location.
				*tran = *dst;
				dst++;
				tran++;		
			}
			dst = dest;
			for(i=0;i<dist;i++){       //Copying contents between src and dst to address pointed by dst.
				*dst = *src;
				dst++;
				src++;
			}
			tran = tran-diff;
			for(i=0;i<diff;i++){       //Copying the remaining moved contents in first loop 
				*dst = *tran;
				dst++;
				tran++;
			}
			return dest;
			
		}
        }
	else if(src>dst) {
		for(i=0;i<length;i++){
			*dst = *src;
			dst++;
			src++;		
		}
		return dest;	
	}
	else {
		return dst;
	}
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * dest = dst;                //Track the target destination.
	for(int i=0;i<length;i++){
		*dst = *src;
		dst++;
		src++;		
	}
	return dest;

}
	
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	uint8_t * sour = src;                //Track the target destination.
	for(int i=0;i<length;i++){
		*src = value;
		src++;		
	}
	return sour;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	//return my_memset(src,length,0); I don't know if it can be used.
	uint8_t * sour = src;                //Track the target destination.
	for(int i=0;i<length;i++){
		*src = 0;
		src++;		
	}
	return sour;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t * rev = src+(length-1);
	uint8_t swap;
	while(rev>src){
		swap = *rev;
		*rev = *src;
		*src = swap;
		src++;
		rev--;
	}
	return rev;
}

int32_t * reserve_words(size_t length){
	int32_t * ptr;
	ptr = (int32_t*) malloc(sizeof(int32_t)*length);
	return ptr;
}

void free_words(int32_t * src){
	free((void*)src);
}



















