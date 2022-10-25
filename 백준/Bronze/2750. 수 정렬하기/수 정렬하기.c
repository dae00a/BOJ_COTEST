#include<stdio.h>

int main()
{
	int n;
	int a[1001];
	int b[1001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	for (int j = 0; j < n; j++)
	{
		b[j] = a[0];
		for (int i = 0; i < n; i++)
		{
			if (b[j] > a[i])
				b[j] = a[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (b[j] == a[i])
				a[i] = 1001;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", b[i]);

	return 0;
}