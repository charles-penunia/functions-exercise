////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f15-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311 at Penn State University.  See the related
//                   assignment page for details.
//
//   Author        : Charles Penunia
//   Last Modified : Fri Sept 11 19:34 EST 2015
//

// Include Files
#include <stdio.h>
#include <math.h>

// Project Includes
#include <a1support.h>

//
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CRUD simulator
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

	// Local variables
	const int MAX = 20;
	float f_arr[MAX];
   	int i, j, k, l, g_arr[MAX];

	// First, lets read in the float numbers to process
	for (i=0; i<MAX; i++) {
		scanf("%f", &f_arr[i]);
	}

	// Step 2: Convert first array
    	for (j=0; j<MAX; j++) {
		if (f_arr[j] >= 10){
			f_arr[j] = M_PI * f_arr[j];
		}
		else {
			f_arr[j] = 42.4 * f_arr[j];
		}
	}

	// Step 3: Assign second array to rounded absolute values
	for (k=0; k<MAX; k++) {
		if (f_arr[k] < 0.0){
			g_arr[k] = -1*(int)(f_arr[k] - 0.5);
		}
		else{
			g_arr[k] = (int)(f_arr[k] + 0.5);
		}
	}

	// Step 4: Print out the arrays
	printf("%s\n", "This is the float array:");
	print_array_float(f_arr, MAX);
	printf("\n");
	printf("%s\n", "This is the integer array:");
	print_array_integer(g_arr, MAX);
	printf("\n");

	// Step 6: Print out GCD of neighboring elements of integer array
	printf("%s\n", "Here are the GCDs:");
	for (l=0; l<MAX-1; l++){
		printf("(%3d,%3d) = %d\n", g_arr[l], g_arr[l+1], euclids_algorithm(g_arr[l], g_arr[l+1]));
	}
	printf("\n");

	// Step 7: Print out the sums of the arrays
	printf("Sum of float array = %.3f\n", sum_array_float(f_arr, MAX));
	printf("Sum of integer array = %d\n", sum_array_integer(g_arr, MAX));
	printf("\n");

	// Step 8: Sort and print out the arrays
	selection_sort_float(f_arr, MAX);
	printf("%s\n", "Sorted float array:");
	print_array_float(f_arr, MAX);
	printf("\n");
	
	selection_sort_integer(g_arr, MAX);
	printf("%s\n", "Sorted integer array:");
	print_array_integer(g_arr, MAX);
	printf("\n");

	// Step 10: Graph the sine function with different multipliers
	graph_sin(1.0);
	printf("\n");
	graph_sin(1.5);
	printf("\n");
	graph_sin(2.0);
	printf("\n");
	graph_sin(3.0);
	printf("\n");

	// Return successfully
	return(0);
}
