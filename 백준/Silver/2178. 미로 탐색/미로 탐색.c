#include <stdio.h>
int xy[10000]={-1,},tem = 0;
int arr[1000][1000];
void maze(int N, int M, int i, int j, int k) {
	int flag = 0, r = 0;
	if (arr[i][j + 1] == 1 || (arr[i][j + 1]!=1 && arr[i][j] < arr[i][j + 1] - 1))
		flag = 1;
	if (arr[i + 1][j] == 1 || (arr[i + 1][j] != 1 && arr[i][j] < arr[i + 1][j] - 1))
		if (flag == 0) flag = 2;
		else r = 1;
	if (j > 0 && arr[i][j - 1] == 1 || (j > 0 && arr[i][j - 1] != 1 && arr[i][j] < arr[i][j - 1] - 1))
		if (flag == 0)  flag = 3;
		else r = 1;
	if (i > 0 && arr[i - 1][j] == 1 || (i > 0 &&arr[i - 1][j] != 1 && arr[i][j] < arr[i - 1][j] - 1))
		if (flag == 0) flag = 4;
		else r = 1;
	if (r == 1)
		xy[tem++] = i, xy[tem++] = j;
	switch (flag) {
	case 1:
		j++;arr[i][j] = arr[i][j - 1]+1;xy[k + 1]++;
		break;
	case 2:
		i++; arr[i][j] = arr[i - 1][j]+1;xy[k]++;
		break;
	case 3:
		j--; arr[i][j] = arr[i][j + 1]+1;xy[k + 1]--;
		break;
	case 4:
		i--; arr[i][j] = arr[i + 1][j]+1;xy[k]--;
		break;
	case 0:
		xy[k] = xy[k + 1] = -1;
		break;}}
int main(void) {
	int N, M, i, j, k;
    char b[1000][1000];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", &b[i]);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) 
			arr[i][j] = b[i][j] - '0';
	i = j = 0; arr[0][0] = 2;
	xy[tem++] = xy[tem++] = 0;
	while (1) {
		for ( k = 0; k < tem; k = k + 2) {
			if (xy[k] == -1) continue;
			maze(N,M, xy[k], xy[k + 1],k);}
		for (k = 0; k < tem; k = k + 2)
			if (xy[k] != -1) break;
		if (k == tem)break;}
	printf("%d", arr[N - 1][M - 1]-1);}