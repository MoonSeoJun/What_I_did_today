#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fibo(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

/*
int Fibo(int n) {
	int result = 0;
	int f1 = 1, f2 = 0;

	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			result = f1 + f2;
			f2 = f1;
			f1 = result;
		}
	}

	return result;
}
*/

int main()
{
	int n;
	printf("숫자를 입력해주세요\n");
	while (scanf("%d", &n) == 1)
	{
		if (n <= 0)
		{
			printf("0보다 작은 수는 입력할 수 없습니다.\n");
		}
		else {
			printf("%d의 피보나치 수 = %d\n", n, Fibo(n));
		}
	}
	return 0;
}