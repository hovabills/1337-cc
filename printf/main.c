#include "inc/ft_printf.h"

int main()
{
	//check if there is a digit 0-9
	//check if there is -
	// char *str = "Hello World";
	int d;

	d = 2147483647;
	// char ch = 'Y';
	// ft_printf("%+++0.0s\n",str);
	// printf("%#+-- 03.-12c",ch);
	// printf("%+-12.4d",d);
	printf("% 300.100i\n",d);
	// ft_printf("% -20.0d\n",d);
	// printf("%d", d);
	// printf("\n%d", y);
	// ft_printf("%#010x", 42)
}

