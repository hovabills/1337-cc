#include "inc/ft_printf.h"

int main()
{
	
	printf("|% ---------++++++++++#####10.20d|,|% -10.20d|,|% -10.20d|\n",0,-23,23);
	printf("------------------------------\n");
	ft_printf("|% ---------++++++++++#####10.20d|,|% -10.20d|,|% -10.20d|\n",0,-23,23);
	printf("------------------------------\n");
	ft_printf("|% -20.10d|,|% -20.10d|,|% -20.10d|\n",0,-23,23);
	printf("------------------------------\n");
	printf("|% -20.d|,|% -20.10d|,|% -20.10d|\n",0,-23,23);

}

