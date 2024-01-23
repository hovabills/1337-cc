#include "inc/ft_printf.h"

int main()
{
	//check if there is a digit 0-9
	//check if there is -
	char *str = NULL;
	// int d;

	// d = -1;
	// char ch = 'x';
	// ft_printf("%+++0.0s\n",str);
	// printf("%#+-- 03.-12c",ch);
	// printf("%+-12.4d",d);
	// ft_printf("%+-300.100u\n",d);
	// int np = printf("%#1000.0X\n",d);
	// printf("%d\n", np);
	int np = ft_printf("%.6s%%\n", str);
	printf("%d\n", np);
	np = printf("%.6s%%\n", str);
	printf("%d\n", np);
	// ft_printf("%02000.100u\n",d);
	// printf("%30.10u\n",d);
	// ft_printf("% -20.0d\n",d);
	// printf("%d", d);
	// printf("\n%d", y);
	// ft_printf("%#010x", 42)
}

