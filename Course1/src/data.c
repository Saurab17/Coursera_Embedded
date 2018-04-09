/******************************************************************************
 * Copyright (C) 2018 by Saurabh Yadav - IITRAM, Ahmedabad.
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Saurabh Yadav and IITRAM Ahmedabad are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief This file does some very basic data manipulation
 *
 * This implementation file provides a way to convert integer to ASCII codes
 * and vice versa via function calls.
 * 
 * @author Saurabh Yadav
 * @date April 4, 2018
 *
 */

/* ASCII Codes: (Code,Symbol): (43,+),(45,-),(48,0),(49,1),(50,2),(51,3),(52,4),(53,5),(54,6),(55,7),(56,8),(57,9)	
				(65,A),(66,B),(67,C),(68,D),(69,E),(70,F)
****************************************************************************************************************/

#include "data.h"

uint8_t conv_to_ASCII(uint8_t x){
	uint8_t code;
	switch(x){
		case 0: 
			code=48;
			break;
		case 1: 
			code=49;
			break;
		case 2: 
			code=50;
			break;
		case 3: 
			code=51;
			break;
		case 4: 
			code=52;
			break;
		case 5: 
			code=53;
			break;
		case 6: 
			code=54;
			break;
		case 7: 
			code=55;
			break;
		case 8: 
			code=56;
			break;
		case 9: 
			code=57;
			break;
		case 10: 
			code=65;  //0xA
			break;		
		case 11: 
			code=66;  //0xB
			break;
		case 12: 
			code=67;  //0xC
			break;
		case 13: 
			code=68;  //0xD
			break;
		case 14: 
			code=69;  //0xE
			break;
		case 15: 
			code=70;  //0xF	
			break;
		default: 
			code=48;
	}	
	return code;
}

uint8_t conv_from_ASCII(uint8_t x){
	uint8_t value;
	switch(x){
		case 48: 
			value=0;
			break;
		case 49: 
			value=1;
			break;
		case 50: 
			value=2;
			break;
		case 51: 
			value=3;
			break;
		case 52: 
			value=4;
			break;
		case 53: 
			value=5;
			break;
		case 54: 
			value=6;
			break;
		case 55: 
			value=7;
			break;
		case 56: 
			value=8;
			break;
		case 57: 
			value=9;
			break;		
		case 65: 
			value=10;
			break;
		case 66: 
			value=11;
			break;
		case 67: 
			value=12;
			break;
		case 68: 
			value=13;
			break;
		case 69: 
			value=14;
			break;
		case 70: 
			value=15;
			break;
		default: value=0;	
	}
	return value;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	if (base<2 || base>16){
		printf("Base out of bounds...Returning 0");
		return 0;
	}
	uint8_t sign = '+';
	uint8_t len = 1;	
	uint8_t * track = ptr;
        if (data<0){
		sign = '-';
		data = (-1)*data;	
	}
	uint8_t rem;
	while (data>=base){
		rem = (uint8_t)(data%base);
		data = data/base;
		*ptr = conv_to_ASCII(rem);
		ptr++;
		len++;	
	}
	*ptr = conv_to_ASCII((uint8_t)data);
        ptr++;
	len++;
	*ptr = sign;
        	
	uint8_t swap;
	while(track<ptr){
		swap = *ptr;
		*ptr = *track;
		*track = swap;
		ptr--;
		track++;
	}
	return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t num = 0;
	int32_t place_value = 1;
	int32_t face_value;
	digits = digits-1;  		//since digits contain sign also;  
	uint8_t sign;
	if ((*ptr) == 43){
		sign = '+';	
	}
	else if ((*ptr) == 45){
		sign = '-';	
	}
	else{
		printf("Wrong ASCII code for sign...Returning 0!");
		return num;	
	}
	
	if (base<2 || base>16){
		printf("Base out of bounds...Returning 0!");
		return num;	
	}
	uint8_t i;
	uint8_t j;
	ptr++;
	for(j=digits;j>0;j--){
		face_value = conv_from_ASCII(*ptr);
		if (face_value != 0){
			for(i=j-1;i>0;i--){
				place_value = place_value*base;			
			}
		}
		num = num + face_value*place_value;
		ptr++;
		place_value = 1;		
	}
	if (sign == '-'){
		return num*(-1);
	}
	return num; 
}



