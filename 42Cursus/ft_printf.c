#include "unistd.h"
#include "stdlib.h"
#include <stdarg.h>
#include <limits.h>

int d_case(int n)
{
	char c;
	if (n  == INT_MIN)
		return write(1, "-2147483648", 11);
	if (n < 0)
		return write(1, "-", 1) + d_case(-n);
	c = '0' + n % 10;
	if (n < 10)
		return write(1, &c, 1);
	return d_case(n / 10) + write(1, &c, 1);
}

int s_case(const char *str)
{
	if (!str)
		return write(1, "(null)", 6);
	int len = 0;
	while(str[len])
		len++;
	return write(1, str, len);
}

int x_case(unsigned int n)
{
	char hex[16] = "0123456789abcdef";

	if (n < 16)
		return write(1, &hex[n], 1);
	return x_case(n / 16) + write (1, &hex[n % 16], 1);
}

int ft_printf(char *fmt, ...)
{
	int check = 0;
	int count = 0;
	va_list args;

	va_start(args, fmt);
	while (*fmt)
	{
		if (check)
		{
			if (*fmt == 'd')
			{
				count += d_case(va_arg(args, int));
			}
			else if (*fmt == 's')
			{
				count += s_case(va_arg(args, const char *));
			}
			else if (*fmt == 'x')
			{
				count += x_case(va_arg(args, unsigned int));
			}
			check = 0;
		}
		else
		{
			if (*fmt == '%')
				check = 1;
			else
				count += write(1, fmt, 1);
		}
		fmt++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	ft_printf("%d\n%s\n%x\n", -532141227, "hello asfa", 255);
}
*/
