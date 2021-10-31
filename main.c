#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define LENGTH 10 //The size of table

/* Conway's Game of Life On C 
 * It uses Sleep() from windows.h and system("cls") in the main function
 * So It smoothly works on the Windows, but errors can appear on other OS)
 */

void copy_table(int table[][LENGTH], int temp_table[][LENGTH])
{
	for (int i = 0; i < LENGTH; i++)
		for (int j = 0; j < LENGTH; j++)
			temp_table[i][j] = table[i][j];
}

void fill_table(int table[][LENGTH])
{
	for (int i = 0; i < LENGTH; i++)
		for (int j = 0; j < LENGTH; j++)
			table[i][j] = 0;
}	

void print_table(int table[][LENGTH])
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
			printf("%d ", table[i][j]);
		printf("\n");
	}
}

int count_neighbors(int table[][LENGTH], int i, int j)
{
	
	int count = 0;
	for (int a = (i - 1); a <= (i + 1); a++)
	{
		for (int b = (j - 1); b <= (j + 1); b++)
		{
			int a_temp = a, b_temp = b;
			if (a_temp == LENGTH)
				a_temp = 0;
			if (a_temp == -1)
				a_temp = LENGTH - 1;
			if (b_temp == LENGTH)
				b_temp = 0;
			if (b_temp == -1)
				b_temp = LENGTH - 1;
			if (a_temp != i || b_temp != j)
				if (table[a_temp][b_temp] == 1)
					count++;
		}
	}
	return count;
}

void make_step(int table[][LENGTH], int temp_table[][LENGTH])
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			int neighbors = count_neighbors(temp_table, i, j);
			if (table[i][j] == 0)
			{
				if (neighbors == 3)
					table[i][j] = 1;
			}
			else
			{
				if (neighbors == 2 || neighbors == 3)
					continue;
				else if (neighbors < 2 || neighbors > 3)
					table[i][j] = 0;	
			}
		}
	}
	copy_table(table, temp_table);
}

int main(void)
{
	system("cls");
	
	int table[LENGTH][LENGTH], temp_table[LENGTH][LENGTH];
	fill_table(table);

	//GLIDER
	table[4][5] = 1;
	table[5][4] = 1;
	table[6][4] = 1;
	table[6][5] = 1;
	table[6][6] = 1;
	
	copy_table(table, temp_table);
	
	for (;;)
	{
		print_table(table);
		make_step(table, temp_table);
		Sleep(1000);
		system("cls");
	}
	
	return 0;
}






