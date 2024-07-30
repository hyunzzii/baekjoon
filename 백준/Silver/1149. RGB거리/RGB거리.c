#include <stdio.h>
#define min(a,b) a<b?a:b
int arr[1000][3], b[1000][3] = { 0, };
void sum(int s, int i, int j) {
	if (b[i][j] == 0 || (b != 0 && b[i][j] > s))
		b[i][j] = s;}
void maze(int N, int i, int j) {
	if (j == 0) {
		sum(b[i][j] + arr[i + 1][j + 1], i + 1, j + 1);
		sum(b[i][j] + arr[i + 1][j + 2], i + 1, j + 2);
	}
	else if (j == 1) {
		sum(b[i][j] + arr[i + 1][j - 1], i + 1, j - 1);
		sum(b[i][j] + arr[i + 1][j + 1], i + 1, j + 1);
	}
	else {
		sum(b[i][j] + arr[i + 1][j - 2], i + 1, j - 2);
		sum(b[i][j] + arr[i + 1][j - 1], i + 1, j - 1);
	}}
int main(void) {
	int N, i, j, k = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) for (j = 0; j < 3; j++) scanf("%d", &arr[i][j]);
	for (j = 0; j < 3; j++) b[0][j] = arr[0][j];
	for (i = 0; i < N-1; i++) for (j = 0; j < 3; j++) maze(N, i, j);
	printf("%d", min((min(b[i][0], b[i][1])), b[i][2]));}