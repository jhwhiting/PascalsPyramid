#include <stdio.h>
#include <malloc.h>

int** buildPyramid(int depth) {
	int** rowPtr = (int**)malloc(depth * sizeof(int*));

	for (int r = 0; r < depth; r++) {
		int* row = (int*)malloc((r + 1) * sizeof(int));

		row[0] = 1;
		row[r] = 1;

		for (int c = 1; c < r; c++) {
			row[c] = rowPtr[r - 1][c] + rowPtr[r - 1][c - 1];
		}

		rowPtr[r] = row;
	}

	return rowPtr;
}

int main() {
	int depth = 10;

	int** pyramid = buildPyramid(depth);

	for (int r = 0; r < depth; r++) {
		for (int c = 0; c <= r; c++) {
			printf("%d ", pyramid[r][c]);
			if (c == r) {
				printf("\n");
			}
		}
		free(pyramid[r]);
	}

	free(pyramid);

	return 0;
}