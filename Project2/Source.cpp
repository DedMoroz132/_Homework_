#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	float epsi = 0.3;
	char t[4] = {"ABC"};
	int a[3][3], b, c, d, e,a1,a2,a3,r=0;
	for (int i = 0; i < 3; i++)
	{
		printf("My program needs coordinates of vector ");
		putchar(t[i]);
		printf("\n");
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &a[i][j]);
		printf("\n");
	}
	e = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
	if (e == 0)
		printf("Vectors are complanar\n");
	else
		printf("Vectors aren't complanar\n");
	a1 = (pow(a[0][0], 2) + pow(a[0][1], 2) + pow(a[0][2], 2));
	a2 = (pow(a[1][0], 2) + pow(a[1][1], 2) + pow(a[1][2], 2));
	a3 = (pow(a[2][0], 2) + pow(a[2][1], 2) + pow(a[2][2], 2));
	if (a1 != 0 && a2 != 0 && a3 != 0)
	{
		b = pow(abs(a[0][1] * a[1][1] + a[0][2] * a[1][2] + a[0][0] * a[1][0]),2);
		c = pow(abs(a[2][1] * a[1][1] + a[2][2] * a[1][2] + a[2][0] * a[1][0]),2);
		d = pow(abs(a[0][1] * a[2][1] + a[0][2] * a[2][2] + a[0][0] * a[2][0]),2);
		if ((a1 * a2 - b - epsi < 0) && (a3 * a2 - c - epsi < 0) && (a1 * a3 - d - epsi < 0))
			printf("All vectors are colliniar\n");
		else
		{
			if (a1 * a2 - b - epsi < 0)
			{
				printf("A and B are colliniar. Coefficient is %lf\n", (a1 > a2 ? sqrt(a2) / sqrt(a1) : sqrt(a1) / sqrt(a2)));
				r = 1;
			}
			if (a3 * a2 - c - epsi < 0)
			{
				printf("B and C are colliniar. Coefficient is %lf\n", (a2 > a3 ? sqrt(a3) / sqrt(a2) : sqrt(a2) / sqrt(a3)));
				r = 1;
			}
			if (a1 * a3 - d - epsi < 0)
			{
				printf("A and C are colliniar. Coefficient is %lf\n", (a1 > a3 ? sqrt(a3) / sqrt(a1) : sqrt(a1) / sqrt(a3)));
				r = 1;
			}
			if (r==0)
				printf("There are no colliniar vectors :(");
		}
	}
	else
	{
		if (a1 == 0)
		{
			if (a2 == 0 || a3 == 0)
			{
				printf("All vectors are colliniar\n");
			}
			else
			{
				printf("A and C are colliniar");
				printf("A and B are colliniar");
			}
		}
		if (a2 == 0)
		{
			if (a1 == 0 || a3 == 0)
			{
				printf("All vectors are colliniar");
			}
			else
			{
				printf("A and B are colliniar");
				printf("B and C are colliniar");
			}
		}
		if (a3 == 0)
		{
			if (a2 == 0 || a1 == 0)
			{
				printf("All vectors are colliniar");
			}
			else
			{
				printf("A and C are colliniar");
				printf("B and C are colliniar");
			}
		}
	}
	return 0;
}