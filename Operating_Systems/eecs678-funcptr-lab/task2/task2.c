#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int sub (int a, int b);
int mult (int a, int b);
int divi (int a, int b);
typedef int (*nothing) (int a, int b);
int main (void)
{
	int intChoice;
	int a = 6;
	int b = 3;
	nothing arr[4];

	arr[0] = add;
	arr[1] = sub;
	arr[2] = mult;
	arr[3] = divi;
	/* IMPLEMENT ME: Insert your algorithm here */
	printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : multiply | 3 : divide):");
	scanf("%d", &intChoice);
	int valueToReturn = arr[intChoice] (a,b);
	printf ("x = %d \n", valueToReturn);
	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int sub (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b; }
int mult (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }
int divi (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b; }
