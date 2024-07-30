#include <stdio.h>
int N, K;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int move2(int finish) {
	if (finish == N) return 0;
	else if (finish > N) return 1 + move2(finish - 1);
	else return 1 + move2(finish + 1);
}
int move1(int finish) {
	if (finish == N) return 0;
	else if (finish % 2 == 0 && finish / 2 >= N) return 1 + move1(finish / 2);
	else if (finish % 2 != 0) return 1 + min(move1(finish - 1), move1(finish + 1));
	else return min(move2(finish), 1 + move2(finish / 2));
}
int main(void) {
	scanf("%d %d", &N, &K);
	if (N < K)
		if (N == 0) {
			N = 1;
			printf("%d", move1(K) + 1);
        }
		else printf("%d", move1(K));
	else if (N == K) printf("0");
	else printf("%d", N - K);
}