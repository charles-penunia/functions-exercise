////////////////////////////////////////////////////////////////////////////////
//
//  File           : a1support.c
//  Description    : This is the implementations of all of the functions in
//       	     a1support.h
//
//   Author        : Charles Penunia
//   Last Modified : Fri Sept 11 19:34 EST 2015
//

// Include files
#include <stdio.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
//
// Function     : print_array_float
// Description  : Print out the list of float values
//
// Inputs       : f[] - an array of type float
//                f_len - the length of f[]
// Outputs      : 

void print_array_float(float f[], int f_len){
	// Initializes local variable
	int i;
	
	// Prints the elements in increasing order
	for (i=0; i<f_len; i++){
		printf("%7.3f\n", f[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : print_array_int
// Description  : Print out the list of integer values
//
// Inputs       : i[] - an array of type int
//                i_len - the length of i[]
// Outputs      : 

void print_array_integer(int i[], int i_len){
	// Initializes local variable
	int j;

	// Prints the elements in increasing order
	for (j=0; j<i_len; j++){
		printf("%3d\n", i[j]);
	}
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : sum_array_float
// Description  : Compute the sum of the float values
//
// Inputs       : f[] - an array of type float
//                f_len - the length of f[]
// Outputs      : sum - the sum of the elements

float sum_array_float(float f[], int f_len){
	// Initializes local variables
	int i;
	float sum = 0.0;

	// Sums up the elements
	for (i=0; i<f_len; i++){
		sum += f[i];
	}

	// Returns the sum
	return sum;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : sum_array_integer
// Description  : Compute the sum of the integer values
//
// Inputs       : i[] - an array of type int
//                i_len - the length of i[]
// Outputs      : sum - the sum of the elements

int sum_array_integer(int i[], int i_len){
	// Initializes local variables
	int j, sum = 0;

	// Sums up the elements
	for (j=0; j<i_len; j++){
		sum += i[j];
	}

	// Returns the sum
	return sum;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : euclids_algorithm
// Description  : Euclid's algorithm to calculate the greatest common divisor
//		  (GCD)
//
// Inputs       : a - an integer
//                b - another integer
// Outputs      : a - the GCD, or -1 if either of the integers are negative

int euclids_algorithm(int a, int b){
	// Checks if both integers are positive
	if(a<0||b<0){
		return -1;
	}
	
	// Initializes local variable
	int temp;

	// Carries out the algorithm
	while (b!=0){
		temp = a;
		a = b;
		b = temp % b;
	}

	// Returns the GCD
	return a;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : selection_sort_float
// Description  : Sort the list of float values
//
// Inputs       : f[] - an arraay of type float
//                f_len - the length of f[]
// Outputs      : 

void selection_sort_float(float f[], int f_len){
	// Initializes local variables
	int i, j, k;
	float temp;

	// Carries out the selection sort	
	for (i=0; i<f_len-1; i++){
		k = i;
		// Finds the smallest element from i to f_len-1
		for(j=i+1; j<f_len; j++){
			if (f[k] > f[j]){
				k = j;
			}
		}
		// Swaps only if the subscript of the smallest
		// element did not change
		if (k != i){
			temp = f[i];
			f[i] = f[k];
			f[k] = temp;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : selection_sort_integer
// Description  : Sort the list of integer values
//
// Inputs       : f[] - an array of type int
//                f_len - the length of f[]
// Outputs      : 

void selection_sort_integer(int l[], int l_len){
	// Initializes local variables
	int i, j, k, temp;
	
	// Carries out the selection sort
	for (i=0; i<l_len-1; i++){
		k = i;
		// Finds the smallest element from i to f_len-1
		for(j=i+1; j<l_len; j++){
			if (l[k] > l[j]){
				k = j;
			}
		}
		// Swaps only if the subscript of the smallest
		// element did not change
		if (k!=i){
			temp = l[i];
			l[i] = l[k];
			l[k] = temp;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : graph_sin
// Description  : Graph the sin(multiplier*x) function
//
// Inputs       : mult - a multiplier of type float
// Outputs      : 

void graph_sin(float mult){
	// Intializes local variables and constants
	const int MAX_ROW = 30;
	const int MAX_COL = 70;
	char graph[MAX_ROW][MAX_COL];
	double xVal, yVal, yLabel;
	int col, row;
	
	// Initializes array elements column by column
	for(col=0, xVal=-3.5; col<MAX_COL; col++, xVal+=0.1){
		// Calculates the corresponding output of the function
		yVal = sin(mult*xVal);
		
		// Initializes array elements within column number col
		for(row=0, yLabel=1.5; row<MAX_ROW; row++, yLabel-=0.1){
			// Determines if yVal is within the rounding range
			// of yLabel
			if (yVal<yLabel+0.05 && yVal>=yLabel-0.05){
				graph[row][col] = '*';
			}
			else{
				graph[row][col] = ' ';
			}
		}
	}

	// Prints the title of the graph
	printf("%43s%.1f%s\n", "Graph of y=sin(", mult, "*x)");

	// Prints the graph and y-axis labels row by row
	for(row=0, yLabel = 1.51; row<MAX_ROW; row++, yLabel-= 0.1){
		printf("%4.1f|", yLabel);
		for(col = 0; col < MAX_COL; col++){
			printf("%c", graph[row][col]);
		}
		printf("\n");
	}

	// Prints the bottom border of the graph
	printf("%5s", " ");
	for(col=0; col<MAX_COL; col++){
		printf("-");
	}
	printf("\n");

	// Prints the x-axis labels
	printf("%11d%10d%10d%10d%10d%10d%10d\n",-3,-2,-1,0,1,2,3);
}
