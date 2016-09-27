/*
 =========================================================================
 Name        : Matrix.c
 Author      : David Katz
 =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define Mx(arg,r,c) ((arg).pX[r][c])

struct Matrix {
	int rows;
	int cols;
	double **pX;
};

void MatPrint(struct Matrix M, char messg[]) {
	int r, c;
	// Print the message
	printf("%s\n",messg);
	// print the matrix
	for (r = 0; r < M.rows; r++) {
		for (c = 0; c < M.cols; c++) {
			printf("%7.3lf ", Mx(M,r,c));
		}
		printf("\n");
	}
}

struct Matrix MatAlloc();
void MatFree();
void MatAdd();

int main(void) {
	struct Matrix m = MatAlloc(2, 2);

	Mx(m, 0, 0) = 1.0;
	Mx(m, 0, 1) = 2.0;
	Mx(m, 1, 0) = 3.0;
	Mx(m, 1, 1) = 5.0;

	MatPrint(m, "Pre-free");

	MatFree(m);

	MatPrint(m, "Post-free");

	printf("Now testing MatAdd");

	struct Matrix a = MatAlloc(3, 3);
	struct Matrix b = MatAlloc(4, 3);

	MatAdd(a, b);

	return EXIT_SUCCESS;
}

// Parameters: r = rows, c = columns
struct Matrix MatAlloc(int r, int c) {
	// the struct to return after dynamic allocation
	struct Matrix m;
	m.rows = r;
	m.cols = c;
	// allocating memory for the array of pointers of
	// size: rows * sizeof a double pointer
	m.pX = (double**) malloc(r*sizeof(double *));
	// if m.pX has been defined, then loop through the rows for memory allocation
	if (m.pX) {
		int x;
		for (x = 0; x < r; x++) {
			// in each row allocate memory for the array of doubles of
			// size: columns * sizeof a double
			m.pX[x] = (double*) malloc(c * sizeof(double));
		}
	}

	// return the properly allocated struct
	return m;
}

// Frees the memory allocated to a Matrix struct
// Paramater: m = Matrix struct
void MatFree(struct Matrix m) {
	// iterate through the rows
	for (int r=0; r < m.rows; r++) {
		// iterate through the columns
		for (int c=0; c < m.cols; c++) {
			// set the value to 0
			Mx(m, r, c) = 0.0;
		}
	}
	// frees the allocated memory as designated by pX in the struct
	free(m.pX);
}

// Adds the contents of a Matrix to another
// Paramters: a = the first Matrix, b = the second Matrix
// Will add the contents of b to a
void MatAdd(struct Matrix a, struct Matrix b) {
	// create a new Matrix of memory size a*b
	// but if the dimensions are different, exit the program
	if (a.rows != b.rows) {
		printf("\nError: Your matrices have unmatched rows. Exiting...");
		exit(0);
	}
	if (a.cols != b.cols) {
		printf("\nError: Your matrices have unmatched columns. Exiting...");
	}
}
