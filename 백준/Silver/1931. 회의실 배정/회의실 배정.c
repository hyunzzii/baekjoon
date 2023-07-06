#include <stdio.h>
typedef struct node {
	int num, b, se;
}node;
int* mergeSort(node* arr,int N, int n) {
    int u, q = 0, tem, s;
	node* c = malloc(sizeof(node) * 2 * N);
	if (n > 2 * N) return arr;
	for (int i = 0; i < 2 * N;) {
		u = s = i + n;
		if (i + 2 * n < 2 * N - 1) tem = i + 2 * n;
		else tem = 2 * N ;
		if (u > 2 * N - 1) {
			while (q != tem) c[q++] = arr[i++];
			break; }
		else {
			while (q != tem) {
				if ((u != tem && arr[i].num > arr[u].num) || i == s ) c[q++]= arr[u++];
				else if (arr[i].num < arr[u].num || u == tem) c[q++]= arr[i++];
				else if (arr[i].num == arr[u].num) {
					if (arr[i].se * arr[u].se == 2) {
						if (arr[i].se > arr[u].se) c[q++] = arr[u++];
						else c[q++] = arr[i++]; }
					else if (arr[i].se < arr[u].se) c[q++] = arr[u++];
					else c[q++]= arr[i++]; }}} 
        i = tem; }
    free(arr); mergeSort(c, N, 2 * n);}
int main(void) {
	int N, sum = 1;
	scanf("%d", &N);
	node *arr = malloc(sizeof(node) * 2 * N);
    int *brr=malloc(sizeof(int) * 2 * N);
	for (int i = 0; i < 2 * N; i++) {
		scanf("%d", &arr[i].num);
		arr[i].se = (i + 2) % 2;
		if (arr[i].se == 1 && arr[i - 1].num == arr[i].num) arr[i].se = arr[i - 1].se = 2;
		arr[i].b = (i + 2) / 2; }
	node * d = mergeSort(arr,N, 2);
	for (int i = 0; i < 2 * N; i++) {
		if (brr[d[i].b] == sum) sum++;
		else brr[d[i].b] = sum; }
	printf("%d\n", --sum); }