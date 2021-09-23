#include <stdio.h>


void fullAdder(int A[], int B[], int C[]) {
	int sum[8], Cout[8];
	for (int i = 0; i < 8; i++) {
		if (A[i] + B[i] + C[i] == 3) {
			sum[i] = 1;
			Cout[i] = 1;
		} else if (A[i] + B[i] + C[i] == 2) {
			sum[i] = 0;
			Cout[i] = 1;
		} else {
			sum[i] = A[i] + B[i] + C[i];
			Cout[i] = 0;
		}
	}
	for (int i = 0; i < 8; i++)
		printf("%d ", sum[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", Cout[i]);

}

int main() {
	int A[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
	int B[8] = { 0, 0, 1, 1, 0, 0, 1, 1 };
	int C[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };
	fullAdder(A, B, C);
}