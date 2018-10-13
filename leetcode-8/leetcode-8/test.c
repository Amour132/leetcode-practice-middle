#include <stdio.h>
#include <string.h>

#define INT_MIN (-2147483647 -1)
#define INT_MAX 2147483647

int myAtoi(char* str) 
{
	int size = strlen(str);
	int i = 0;
	int j = 0;
	long long tmp = 0;
	int flag = 1;
	int bit = 0;
	int bit2 = 0;
	while (*str == ' ')
	{
		str++;
	}
	if (str[0] == '-')
	{
		i++;
		flag = -1;   //标记为负数
	}
	if (str[0] == '+')
	{
		i++;
		flag = 1;  //标记为正数
	}

	for (j = i; j < size; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			tmp = tmp * 10 + (str[j] - '0');

			if (str[j] != '0' && bit2 == 0)
			{
				bit2 = 1;
			}
			if (bit2 == 1)
			{
				bit++;
			}
		}
		else
		{
			break;
		}
	}
	if (bit > 10)
	{
		if (flag == -1)
		{
			return INT_MIN;
		}
		if (flag == 1)
		{
			return INT_MAX;
		}
	}
	if (flag == -1)
	{
		tmp = tmp * -1;
	}
	if (tmp > INT_MAX)
	{
		return INT_MAX;
	}
	if (tmp < INT_MIN)
	{
		return INT_MIN;
	}
	return (int)tmp;
}

int main()
{
	char str[] = "-000000001";
	int ret = myAtoi(str);
	printf("%d\n", ret);
	return 0;
}