#include <stdio.h>
unsigned long long int arr[10] = { 0,1,1,1,1,1,1,1,1,1 }, brr[10] = { 0,1,1,1,1,1,1,1,1,1 };
int main (void){
	long long int n, sum = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				if (arr[j] != 0) {
					brr[1] += arr[0];
					brr[0] -= arr[0];
				}
			}
			else if (j == 9) {
				if (arr[j] != 0) {
					brr[8] += arr[9];
					brr[9] -= arr[9];
				}
			}
			else if(arr[j] != 0){
				brr[j - 1] += arr[j];
				brr[j + 1] += arr[j];
				brr[j] -= arr[j];
			}
		}
		for (int i = 0; i < 10; i++)
			arr[i] = brr[i] % 1000000000;
	}
	for (int i = 0; i < 10; i++) 
		sum += arr[i] % 1000000000;
	printf("%lld", sum % 1000000000);
}