#include <iostream>
using namespace std;

// M x N matrix
#define M 8
#define N 6

// Function to find the size of largest square sub-matrix of 1's
// present in the given binary matrix
int findLargestSquare(int mat[M][N], int m, int n, int &max_size)
{
	// base condition
	if (m == 0 || n == 0) {

		if (max_size != 0) {
			max_size = max(max_size, mat[m][n]);
			return mat[m][n];
		}

		for (int i = 0; i <= m; i++) {
			if (mat[i][n] == 1) {
				max_size = 1;
				break;
			}
		}

		for (int j = 0; j <= n; j++) {
			if (mat[m][j] == 1) {
				max_size = 1;
				break;
			}
		}

		return max_size;
	}

	// find largest square matrix ending at mat[m][n-1]
	int left = findLargestSquare(mat, m, n - 1, max_size);

	// find largest square matrix ending at mat[m-1][n]
	int top = findLargestSquare(mat, m - 1, n, max_size);

	// find largest square matrix ending at mat[m-1][n-1]
	int top_left = findLargestSquare(mat, m - 1, n - 1, max_size);

	// largest square matrix ending at mat[m][n] will be 1 plus
	// minimum of largest square matrix ending at mat[m][n-1],
	// mat[m-1][n] and mat[m-1][n-1]

	int size = 0;
	if (mat[m][n] != 0) {
		size = 1 + min (min(top, left), top_left);
	}

	// update maximum size found so far
	max_size = max(max_size, size);

	// return the size of largest square matrix ending at mat[m][n]
	return size;
}

int main()
{
	int mat[M][N] =
	{
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	// size stores the size of largest square sub-matrix of 1's
	// and it is passed by reference
	int size = 0;

	findLargestSquare(mat, M-1, N-1, size);

	cout << "The size of largest square sub-matrix of 1's is " << size;

	return 0;
}