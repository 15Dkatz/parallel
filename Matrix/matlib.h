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

// Returns a Matrix struct with properly allocated memory
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

	// return the properly allocated Matrix struct
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
		exit(0);
	}

	// iterate through the rows of a and b
	// having a.rows as the limit is safe because we know a.rows == b.rows
	for (int r=0; r < a.rows; r++) {
		// iterate through the columns of a and b
		// having a.cols is the limit is safe because we know a.cols == b.cols
		for (int c=0; c < a.cols; c++) {
			// add to the value of a[r][c] with b[r][c]
			Mx(a, r, c) = Mx(a, r, c) + Mx(b, r, c);
		}
	}
}
