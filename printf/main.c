#include "ft_printf.h"

int main()
{
	int num = 12;
	ft_printf("%199d\n", num);
	ft_printf("%1212p\n", &num);
}
