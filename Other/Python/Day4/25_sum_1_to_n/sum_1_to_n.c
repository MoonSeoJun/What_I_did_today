#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

/*int SumOfN(int n) {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}
*/

int SumOfN(int n, int sum) {
	if (n == 0) {
		return sum;
	}
	else {
		return SumOfN(n - 1, sum + n);
	}
}

int main() {
	int n;

	printf("n까지의 합을 위해 n의 값을 입력해주세요\n");
	while (scanf("%d", &n) == 1) {
		if (n < 1) {
			printf("1 보다 작은 수는 입력할 수 없습니다\n");
		}
		else {
			printf("1부터 %d까지의 합 = %d\n", n, SumOfN(n, 0));
		}
	}

	return 0;
}