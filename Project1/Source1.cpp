/*#include <stdio.h>
#include <math.h>
int main()
{
	int a,p=1,i=0,g=1,h=10;
	scanf_s("%d", &a);
	while (i <= a)
	{
		i = i + p;
		if (i / h != 0)
		{
			h = h * 10;
			p = p + 1;
		}
		g = g * h + i;
	}
	h = i - a;
	p = h - 1;
	g = (g % (int)pow(10, h)) / (int)pow(10, p);
	printf("%d", g);
	return 0;
}*/