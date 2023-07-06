#include <stdio.h>

struct counter{
	int id;
	int w;
	int num;
};

int N, K, num = 0, time = 0, r = 1;
int flag = 0, cnt_num[100002], cn = -1;
long long result = 0;

struct counter cnt[100002];

void enqueue(int id, int w) {
	cnt[++num].id = id;
	cnt[num].w = w + time;
	
	if (!flag)
		cnt[num].num = num;
	else
		cnt[num].num = cnt_num[cn--];

	struct counter tem;
	for (int i = num; i / 2 > 0 && cnt[i].w <= cnt[i / 2].w; i /= 2) {
		if (cnt[i].w == cnt[i / 2].w && cnt[i].num < cnt[i / 2].num)
			break;
		tem = cnt[i];
		cnt[i] = cnt[i / 2];
		cnt[i / 2] = tem;
	}
}

void dequeue(void) {
	while (1) {
		struct counter pre = cnt[1];

		cnt[1] = cnt[num];
		cnt[num--].w = 10000000;

		result += (long long)(r++) * pre.id;
		cnt_num[++cn] = pre.num;
		time += pre.w - time;

		int max;
		struct counter tem;
		for (int i = 1; i * 2 <= num; i = max) {
			
			max = i * 2;

			if (max < num){
				if (cnt[max].w == cnt[max + 1].w)
					max += cnt[max].num < cnt[max + 1].num ? 1 : 0;
				else
					max += cnt[max].w < cnt[max + 1].w ? 0 : 1;
			}
			if (cnt[i].w > cnt[max].w || (cnt[i].w == cnt[max].w && cnt[i].num < cnt[max].num)) {
				tem = cnt[i];
				cnt[i] = cnt[max];
				cnt[max] = tem;
			}
			else break;
		}
		
		if (pre.w != cnt[1].w) 
			break;
	}
}

int main(void) {
	scanf("%d %d", &N, &K);

	int id, w;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &id, &w);
		if (num == K) {
			dequeue();
			flag = 1;
		}
		enqueue(id,w);
	}
	
	while(num)
        dequeue();
    
	printf("%lld\n", result);
    return 0;
}