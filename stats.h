/******************************************************************************
 * Copyright (C) 2017 by Abhinand G D
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Abhinand G D is not liable for any misuse of this material.
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
 * This function takes in 4 1 byte unsigned char as 
 * parameters to print out mean, median, minimum and maximum.
 * 
 * @param float median which takes the return
 * value from the function find_median() 
 * the array elements
 * @param float mean which takes the return 
 * value from the function find_mean()
 * @param unsigned char max which takes the return
 * value from the function find_maximum()
 * @param unsigned char max which takes the return value
 * from the function find_minimum()
 * @displays the values of min, median, mini and max.
 */
unsigned char print_statistics(float median, float mean, unsigned char max, unsigned char min);

/**
 * @brief A function that prints the given array of  
 * 		  
 * elements on the console 
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return doesn't return any value only prints the 
 * values of the given data array.
 */
unsigned char print_array(unsigned char* array, unsigned int size);

/**
 * @brief A function that returns the median value of a
 * 		  
 * given array elements of pre-defined length.
 *
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the median value(actual float value) from the given array set
 */
float find_median(unsigned char* array, unsigned int size);

/**
 * @brief A function that prints the mean value of a 
 * 		  
 * given array elements of pre-defined length.
 * 
 * @param unsigned char pointer which points and access 
 * the array elements
 * @param unsigned integer which gives size of array
 * @return the mean value(actual float value) from the given array set
 */
float find_mean(unsigned char* array, unsigned int size);

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
 * @return doesn't return any value only just stores
 * sorted array 
 */
unsigned char sort_array(unsigned char* array, unsigned int size);


#endif /* __STATS_H__ */
