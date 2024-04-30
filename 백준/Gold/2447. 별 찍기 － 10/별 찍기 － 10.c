#include <stdio.h>
int main(void) {
	int num, p;scanf("%d", &num);
	for (int i = 0; i < num; i++) {for (int j = 0; j < num;) {p = 0;
			if (i/(num/3)==1 && j /(num / 3)==1) {for (int T = 0; T < num / 9; T++) {
                printf("   "); j += 3;}}
			else {
				for (int k = num / 3; k != 1; k /= 3) {
					if ((i % k >= k/3 && i%k <2*(k/3)) && j % k == k/3) {
						for (int T = 0; T < k / 9; T++) {printf("   "); j += 3;}
						p = 1;break;}}
				if (p == 0) {if (i % 3 == 1 && j % 3 == 0) printf("* *");else printf("***");
					j += 3;}}}printf("\n");}}