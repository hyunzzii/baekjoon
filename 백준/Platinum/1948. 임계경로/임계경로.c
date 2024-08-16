#include <stdio.h>
#include <stdlib.h>
int n, m, start, end, doro[10001][10001] = { {0,} }, q[1000001], h = 1, t = 0, hm = 0, tm = 0,  *out[10001], * in[10001], ind[10001] = { 0, }, outd[10001] = { 0, };
int M(int a, int b) { if (a > b)return a; else return b; }
int main(void) {
	int a, b, c, sum = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (doro[a][b] == 0) {
			doro[a][b] = c;
			outd[a]++;
			ind[b]++;
		}
		else
			doro[a][b] = M(doro[a][b], c);
	}
	scanf("%d", &start);
	scanf("%d", &end);
	for (int i = 1; i < 10001; i++) {
		out[i] = malloc(sizeof(int) * outd[i]);
		in[i] = malloc(sizeof(int) * ind[i]);
		ind[i] = outd[i] = 0;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 1; j < 10001; j++) {
			if (i != j && doro[i][j] > 0) {
				out[i][outd[i]++] = j;
			}
		}
	}
	q[t] = start;
	while (1) {
		for (int i = 0; i < outd[q[t]]; i++) {
			int next = out[q[t]][i];
			if (h == 1000001) {
				hm++;
				h = 0;
			}
			if (doro[q[t]][next] > 0) {
				if (doro[next][0] < doro[q[t]][0] + doro[q[t]][next]) {
					in[next][ind[next]++] = q[t];
					q[h++] = next;
					doro[next][0] = doro[q[t]][0] + doro[q[t]][next];
					doro[q[t]][next] = -doro[q[t]][next];
				}
				else if (doro[next][0] == doro[q[t]][0] + doro[q[t]][next]) {
					doro[q[t]][next] = -doro[q[t]][next];
					in[next][ind[next]++] = q[t];
				}
			}
			if (doro[q[t]][next] < 0) {
				if (doro[next][0] < doro[q[t]][0] - doro[q[t]][next]) {
					doro[next][0] = doro[q[t]][0] - doro[q[t]][next];
					q[h++] = next;
				}
			}
		}
		if (t == 1000000) {
			tm++;
			t = 0;
		}
		else t++;
		if (tm == hm && t >= h)
			break;
	}
	t = 0; h = 1;
	q[t] = end;
	while (1) {
		for (int i = 0; i < ind[q[t]]; i++) {
			int pre = in[q[t]][i];
			if (h == 1000001) {
				hm++;
				h = 0;
			}
			if (doro[pre][q[t]] < 0 && doro[q[t]][0] == doro[pre][0] - doro[pre][q[t]]) {
				doro[pre][q[t]] = -doro[pre][q[t]];
				q[h++] = pre;
				sum++;
			}
		}
		if (t == 1000000) {
			tm++;
			t = 0;
		}
		else t++;
		if (tm == hm && t >= h)
			break;
	}
	printf("%d\n%d", doro[end][0], sum);
}