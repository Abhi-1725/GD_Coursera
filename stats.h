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
 * @file: stats.h
 *
 * Describes the functions and its parameters involved in calculating
 * attributes of statistics:
 *         1.Mean
 *         2.Median
 *         3.Minimum
 *         4.Maximum
 *
 * Author: Abhinand G D
 * Date: 09/12/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function that prints the statistics of an 
 * 		  
 * array including minimum, maximum, mean, and median
 * This function takes in 2 parameters first one being 
 * an unsigned char pointer to a pre-defined data array 
 * and second is an unsigned integer as the size of the 
 * array to print out mean, median, minimum and maximum.
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 *
 * @return the values of mean, median, minimum and 
 * maximum.
 */
unsigned char print_statistics(unsigned char median, unsigned char mean, unsigned char max, unsigned char min);

/**
 * @brief A function that prints the given array of  
 * 		  
 * elements on the console 
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the values of the given data array
 */
unsigned char print_array(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the median value of a
 * 		  
 * given array elements of pre-defined length.
 *
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the median value from the given array set
 */
unsigned char find_median(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the mean value of a 
 * 		  
 * given array elements of pre-defined length.
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the mean value from the given array set
 */
unsigned char find_mean(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the maximum value of 
 * 		  
 * the element amongst the given array elements.
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the maximum value of the array elements
 */
unsigned char find_maximum(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the minimum value of
 * 		  
 * the element amongst the given array elements. 
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the minimum value of the array elements
 */
unsigned char find_minimum(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the sorted array of a 
 * 		  
 * given array elements of pre-defined length, from 
 * largest to smallest with  zeroth element being  
 * the largest and (n-1)th element being the smallest. 
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return sorted values of the array elements
 */
unsigned char sort_array(unsigned char* array, unsigned int size);


#endif /* __STATS_H__ */
