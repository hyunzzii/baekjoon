#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct pokemon {
	int number;     //도감 번호
	char name[21];   //포켓몬 이름
};
struct pokemon PM[100001];
int compare(const void* a, const void* b)
{
	struct pokemon *A = (struct pokemon*)a;
	struct pokemon *B = (struct pokemon*)b;
	return strcmp(A->name, B->name);
}
int m[100001][21],PM_1[100001][21];
int main(){
	int i, j, N, M, put = 0, tem, k;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", &PM[i].name);
		strcpy(PM_1[i],PM[i].name);
		PM[i].number=i;}
	qsort((void*)PM, N, sizeof(PM[0]), compare);
	int end,start,mid;
	for (i = 0; i < M; i++) { scanf("%s", m[i]);
		if ((char)m[i][0]>= '0' && (char)m[i][0] <= '9')
			printf("%s\n", PM_1[atoi(m[i]) - 1]);
		else{end = N - 1, start = 0, mid = (end + start) / 2;
		while (end - start >= 0) {
			if (strcmp(PM[mid].name,m[i])==0) {
				printf("%d\n", PM[mid].number + 1); break;}
			else if (strcmp(PM[mid].name, m[i])<0)	start = mid + 1;
			else end = mid - 1;
			mid = (end + start) / 2;}}}}