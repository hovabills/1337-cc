//#include "libft.h"


//int ft_strlen(char *str)
//{
	//int len;
	
	//len = 0;
	//if (!str)
		//return (0);
	//while(*str++)
		//len++;
	//return len;
//}

//size_t ft_nbrbase_len(unsigned long long nbr, size_t blen)
//{
	//size_t len;

	//len = 0;
	//if (!nbr)
		//return (1);
	//while (nbr)
	//{
		//nbr /= blen;
		//len++;
	//}
	//return (len);
//}
//int ft_isdigit(char ch)
//{
	//if(ch >= '0' && ch <= '9')
		//return (1);
	//return (0);	
//}
//int	ft_putchar(char ch)
//{
	//return write(1, &ch, 1);
//} 

//int ft_putstr(char *str)
//{
	//if (!str || !*str)
		//return (0);
	//write(1, str, 1);
	//return (1 + ft_putstr(++str));
//}

//int	ft_putnstr(char *str, int n)
//{
	//int	i;

	//i = 0;
	//while(i < n && str[i])
	//{
		//write(1, &str[i], 1);
		//i++;
	//}
	//return i;
//}

//char *ft_strdup(char *str)
//{
	//char	*dup;
	//size_t	len;

	//len = ft_strlen(str);
	//dup = (char *)malloc(len + 1);
	//while (*str)
		//*dup++ = *str++;
	//*dup = '\0';
	//return (dup - len);
//}

//char *ft_itoa_base(unsigned long long nbr, char *base, int blen)
//{
	//size_t len;
	//char *str;

	//len = ft_nbrbase_len(nbr, blen);
	//str = (char *)malloc(len + 1);
	//if (!str)
		//return (NULL);
	//str[len--] = '\0';
	//if (nbr == 0)
	//{
		//*str = '0';
		//return str;
	//}
	//while (nbr)
	//{	
		//str[len--] = base[nbr % blen];
		//nbr /= blen;
	//}
	//return (str);
//}