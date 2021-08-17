#include <stdio.h>

/*int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}
*/

int Factorial(int n) {
	int result = 1;

	for (int i = 2; i <= n; i++) {
		result *= i;
	}

	return result;
}

int main()
{
	int n;

	printf("숫자를 입력해주세요\n");
	while (scanf("%d", &n) == 1) {
		printf("%d! = %d\n",n, Factorial(n));
	}

	return 0;
}