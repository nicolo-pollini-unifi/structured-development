#include "average.h"

#define RANGE_MIN 0
#define RANGE_MAX 100

static int value_in_range(int value)
{
	return (RANGE_MIN <= value && value <= RANGE_MAX);
}

static void process_value(int value, int *sum, int *count)
{
	if (value_in_range(value))
	{
		*sum += value;
		(*count)++;
	}
}

static float compute_average(int sum, int count)
{
	if (count == 0)
		return 0.0f;
	else
		return (float)sum / count;
}

float average(const int *arr, int size)
{
	int i = 0;
	int valid_count = 0;
	int sum = 0;

	while (i < size)
	{
		process_value(arr[i], &sum, &valid_count);
		i++;
	}

	return compute_average(sum, valid_count);
}
