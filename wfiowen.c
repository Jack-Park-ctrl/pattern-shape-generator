#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_triangle(int, int);
void prn_start(int);
void prn_numt(int);
void prn_changet(int);

void print_pyramid(int, int);
void prn_starp(int);
void prn_nump(int);
void prn_changep(int);

void print_stairs(int height, int pattern, int floors, int width);
void prn_stars(int, int, int);
void prn_nums(int, int, int);
void prn_changes(int, int, int);

int main()
{
	while (1)
	{
		int shapes, height, pattern;

		printf("도형을 선택하세요 (1: 삼각형, 2: 피라미드, 3: 계단): ");
		scanf("%d", &shapes);
		printf("도형의 높이 (1~9): ");
		scanf("%d", &height);
		printf("패턴을 선택하세요 (1: *, 2: 줄번호, 3: 0과 1 교차): ");
		scanf("%d", &pattern);

		if (shapes == 1)
			print_triangle(height, pattern);
		else if (shapes == 2)
			print_pyramid(height, pattern);
		else if (shapes == 3)
		{
			// 계단 선택 시에만 추가 입력 받기
			int floors, width;
			printf("계단의 층수 (1~5): ");
			scanf("%d", &floors);
			printf("계단의 폭 (1~9): ");
			scanf("%d", &width);

			print_stairs(height, pattern, floors, width);
		}

	
	}

	return 0;
}

void print_triangle(int height, int pattern)
{
	if (pattern == 1)
	{
		prn_start(height);
	}
	if (pattern == 2)
	{
		prn_numt(height);
	}
	if (pattern == 3)
	{
		prn_changet(height);
	}
}
void prn_numt(int height)
{
	int i, j;

	for (i = 1; i <= height; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
}
void prn_start(int height)
{
	int i, j;

	for (i = 1; i <= height; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void prn_changet(int height)
{
	int i, j;
	int k = 0;

	for (i = 1; i <= height; i++)
	{
		if (i % 2 != 0)
		{
			for (j = 1; j <= i; j++)
			{
				if (j % 2 != 0)
				{
					printf("0");
				}
				if (j % 2 == 0)
				{
					printf("1");
				}
			
			}
			printf("\n");
		}
		if (i % 2 == 0)
		{
			for (j = 1; j <= i; j++)
			{
				if (j % 2 != 0)
				{
					printf("1");
				}
				if (j % 2 == 0)
				{
					printf("0");
				}
		
			}
			printf("\n");

		}

	}
}

void print_pyramid(int height, int pattern)
{
	if (pattern == 1)
	{
		prn_starp(height);
	}
	if (pattern == 2)
	{
		prn_nump(height);
	}
	if (pattern == 3)
	{
		prn_changep(height);
	}
}
void prn_starp(int height)
{
	int i, j, k;

	for (i = 1; i <= height; i++)
	{
		for (j = i; j <= height - 1; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void prn_nump(int height)
{
	int i, j;
	int k, p = 1;

	for (i = 1; i <= height; i++)
	{
		for (k = i; k <= height - 1; k++)
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("%d", p);
		}
		p++;
		printf("\n");
	}
}
void prn_changep(int height)
{
	int i, j, k, p;

	for (i = 1; i <= height; i++)
	{
		for (p = i; p <= height - 1; p++)
		{
			printf(" ");
		}

		if (i % 2 != 0)
		{
			for (j = 1; j <= 2 * i - 1; j++)
			{
				if (j % 2 != 0)
				{
					printf("0");
				}
				if (j % 2 == 0)
				{
					printf("1");
				}

			}
			printf("\n");
		}
		if (i % 2 == 0)
		{
			for (j = 1; j <= 2 * i - 1; j++)
			{
				if (j % 2 != 0)
				{
					printf("1");
				}
				if (j % 2 == 0)
				{
					printf("0");
				}

			}
			printf("\n");

		}
	}
}

void print_stairs(int height, int pattern, int floors, int width)
{
	if (pattern == 1)
	{
		prn_stars(height, floors, width);
	}
	if (pattern == 2)
	{
		prn_nums(height, floors, width);
	}
	if (pattern == 3)
	{
		prn_changes(height, floors, width);
	}
}
void prn_stars(int height, int floors, int width)
{
	int i, j, k, p;
	int offset = width;
	int origin = width;

	for (i = 1; i <= floors; i++)
	{
		
		if ( i == 1)
		{
			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= width; k++)
				{
					printf("*");
				}
				printf("\n");
			}
			
		}
		if (i >= 2)
		{
			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= offset; k++)
				{
					printf(" ");
				}
				for (p = 1; p <= origin; p++)
				{
					printf("*");
				}
				printf("\n");
				if (j == height)
				{
					offset = offset + width;
				}
			}


		}


	}
}
void prn_nums(int height, int floors, int width)
{
	int i, j, k, p = 1;

	for (i = 1; i <= floors; i++)
	{
		if (i == 1)
		{
			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= width; k++)
				{
					printf("%d", j);
				}
				printf("\n");
			}
		}
		if (i >= 2)
		{
			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= width * (i - 1); k++)
				{
					printf(" ");
				}
				for (k = 1; k <= width; k++)
				{
					printf("%d", j);
				}
				printf("\n");
			}
		}


	}
}
void prn_changes(int height, int floors, int width)
{
	int row = 0, col = 0;
	int i, j, k;

	for (i = 1; i <= floors; i++)
	{
		if (i == 1)
		{
			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= width; k++)
				{
					printf("%d", (col + row) % 2);
					col++;
				}
				printf("\n");
			}
		}

		if (i >= 2)
		{
			int col = 0, row = 0;

			for (j = 1; j <= height; j++)
			{
				for (k = 1; k <= width * (i - 1); k++)
				{
					printf(" ");
				}
				for (k = 1; k <= width; k++)
				{
					printf("%d", (col + row) % 2);
					row++;
				}
				printf("\n");

			}
		}
	}
}
