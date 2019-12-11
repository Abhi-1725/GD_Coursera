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
 * @file: stats.c
 * 
 *
 * Implementing simple C programming to display sorted array 
 * from the given array and display some of the statistics
 * of the given array:
 *         1.Mean
 *         2.Median
 *         3.Minimum
 *         4.Maximum
 * 
 * Author: Abhinand G D
 * Date: 09/12/2019
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE 40

/*function which prints the output of other function which are defined below*/
unsigned char print_statistics(float median, float mean, unsigned char max, unsigned char min)
{  

	printf(" The Median value of the array is: %f\n", median);
	printf(" The Mean value of the array is: %f\n", mean);
	printf(" The maximum value in the array is: %d\n", max);
	printf(" The minimum value in the array is: %d\n", min);

return 0;
}

unsigned char print_array(unsigned char* array, unsigned int size)
{
	// iterating through the given set of array and printing it out on console
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", array[i]);
	}
}

float find_median(unsigned char* array, unsigned int size)
{
	float median_arrayElements;

	// if number of elements are even then considerng the ele
	if(size%2 == 0)
	    median_arrayElements = (array[size/2] + array[(size + 2)/2])/2;
	// if number of elements are odd
	else
	    median_arrayElements = array[size/2];
    
return median_arrayElements;
}

float find_mean(unsigned char* array, unsigned int size)
{
	float sum = 0;
	float mean_arrayElements;

	for (int i = 0; i < size; ++i)
	{
		sum += array[i];  	
	}
	// formula to calculate average or mean of set of  numbers
	mean_arrayElements = sum / size;

return mean_arrayElements;
}

unsigned char find_maximum(unsigned char* array, unsigned int size)
{
	int maxValue_index = 0;
	for (int i = 0; i < size; ++i)
	{
		// comparing the rest of the array elements with the zeroth element
		if (array[i] > array[maxValue_index])
		{
			// updating the array index of the current maximum array value
			maxValue_index = i;
		}
	}

return array[maxValue_index];
}

unsigned char find_minimum(unsigned char* array, unsigned int size)
{
	int minValue_index = 0;
	for (int i = 1; i < size; ++i)
	{
		// comparing the rest of the array elements with the zeroth element
		if (array[i] < array[minValue_index]) 
		{
			//updating the array index of the current minimum array value
			minValue_index = i;
		}
	}

return array[minValue_index];

}

unsigned char sort_array(unsigned char* array, unsigned int size)
{
	int i=0 , j=0 , temp_element=0;

	// main loop to iterate through the entire array
	for(i=0 ; i < size ; ++i) 
	{
		//secondary loop to iterate through (n - 1)elements of same array 
	    for(j=0 ; j<size-1 ; j++)
	    {
	    	//checking if the 'next element' is greater than 'previous element'
	        if(array[j+1] > array[j])
	        {
	        	// temporary variable to swap 'next' and 'previous' element
	            temp_element = array[j];
	            array[j]     = array[j+1];
	            array[j+1]   = temp_element;
	        }
	   }
}

printf("The sorted array is shown below: \n"); 
for(i=0 ; i < size ; ++i)
{
    printf("\n array[%d] : %d",i,array[i]);
}
}


void main() 
{

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
	                              114, 88,   45,  76, 123,  87,  25,  23,
	                              200, 122, 150, 90,   92,  87, 177, 244,
	                              201,   6,  12,  60,   8,   2,   5,  67,
	                                7,  87, 250, 230,  99,   3, 100,  90};


	/* Variable Declarations to hold return values of functions*/
	unsigned char  array_maxValue, array_minValue; 
	float median_arrayElements, mean_arrayElements; 

	median_arrayElements = find_median(test, SIZE);
	mean_arrayElements = find_mean(test, SIZE);
	array_maxValue = find_maximum(test, SIZE);
	array_minValue = find_minimum(test, SIZE);

	/* Statistics and Printing and calling Functions */

	print_array(test, SIZE);
	sort_array(test, SIZE);
	printf("\n");
	print_statistics(median_arrayElements, mean_arrayElements, array_maxValue, array_minValue);

}
