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
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	for (j=i; j < size; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			tmp = tmp * 10 + (str[j]-'0');
		}
		else
		{
			break;
		}
	}
	if (str[0] == '-')
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
	char str[] = "-42";
	int ret = myAtoi(str);
	printf("%d\n", ret);
	return 0;
}