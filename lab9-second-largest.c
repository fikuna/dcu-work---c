#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getting_array(int *len, char *argv[], float *p_array);
void sort(int *len, float *p_array);
void swap(float *a, float *b);
void get_second_large(int *len, float *p_array);
void print_result(float *second_large);

int main(int argc, char * argv[])
{
	int len = argc - 1;
	float *p_array = (float*)malloc(len * sizeof(float));
	if (!p_array)
	{
		printf("Error allocating space\n");
		return 0;
	}

	getting_array(&len, argv, p_array);
	sort(&len, p_array);
	get_second_large(&len, p_array);
	free(p_array);
	return 0;
}

void getting_array(int *len, char *argv[], float *p_array)
{
	for (int i = 0; i < *len; i++)
	{
		*(p_array + i) = atof(argv[i + 1]);
	}
}

void sort(int *len, float *p_array)
{
	int largest;
	for (int i = 0; i < *len; i++)
	{
		largest = i;
		for (int j = i + 1; j < *len; j++)
		{
			if (*(p_array + largest) < *(p_array + j))
			{
				largest = j;
			}
		}
		swap(p_array + i, p_array +  largest);
	}
}

void swap(float *a, float *b)
{
	float tmp = *a;
	*a = *b;
	*b = tmp;
}

void get_second_large(int *len, float *p_array)
{
	float tmp = *(p_array + 0);
	for (int i = 0; i < *len; ++i)
	{
		if (tmp != *(p_array + i))
		{
			tmp = *(p_array + i);
			break;
		}
	}
	print_result(&tmp);
}

void print_result(float *tmp)
{
	printf("%.1f\n", *(tmp));
}