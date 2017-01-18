#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, sum, i;
	char sign;
	char arr[10];
	scanf("%d%d", &a, &b);
	sum = a + b;
	sign = (sum < 0) ? '-' : '+';
	sum = abs(sum);

	if (sum == 0)
	{
		printf("0\n");
		return 0;
	}
	int num, comma = 0;
	for (i = 0; sum != 0; i++)
	{
		num = sum % 10;
		arr[i] = 48 + num;
		sum /= 10;
		comma++;
		if (comma % 3 == 0 && sum != 0)
			arr[++i] = ',';
	}

	sign == '-' ? arr[i] = sign : i--;

	for (; i >= 0; i--)
		printf("%c", arr[i]);
	printf("\n");
	return 0;
}