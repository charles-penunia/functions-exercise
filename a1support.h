#ifndef CMPSC311_A1SUPPORT_INCLUDED
#define CMPSC311_A1SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : a1support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 311 homework assignments.
//
//  Author   : Patrick McDaniel
//  Created  : Mon Feb  9 07:30:26 EST 2015

//
// Functional Prototypes

void print_array_float(float f[], int f_len);
	// Print out the list of float values

void print_array_integer(int i[], int i_len);
	// Print out the list of integer values

float sum_array_float(float f[], int f_len);
	// Compute the sum of the float values

int sum_array_integer(int i[], int i_len);
	// Compute the sum of the integer values

int euclids_algorithm(int a, int b);
	// Euclid's algorithm to calculate the greatest common divisor (GCD)

void selection_sort_float(float f[], int f_len);
	// Sort the list of float values

void selection_sort_integer(int l[], int l_len);
	// Sort the list of integer values

void graph_sin(float mult);
	// Graph the sin(multiplier*x) function

#endif // CMPSC311_A1SUPPORT_INCLUDED
