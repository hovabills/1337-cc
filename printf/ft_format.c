#include "ft_printf.h"

struct Format
{
	int ladj;
	int alt_fmt;
	char p_sign;
	char padd_ch;
	int padd_len;
	int prec;
	int n_parse;
};

struct Format *init_fmt()
{
	struct Format *fmt = (struct Format *)malloc(sizeof(struct Format));
	if (!fmt)
		return (NULL);
	fmt->p_sign = 0;
	fmt->ladj = 0;
	fmt->alt_fmt = 0;
	fmt->padd_ch = ' ';
	fmt->padd_len = 0;
	fmt->prec = -1;
	fmt->n_parse = 0;
	return fmt;
}

void parse_fmt(struct Format *fmt, char *str)
{
	while (1)
	{
		if (*str == '#')
			fmt->alt_fmt = 1;
		else if (*str == '-')
			fmt->ladj = 1;
		else if (*str == '+')
			fmt->p_sign = '+';
		else if (*str == ' ')
		{
			if (!fmt->p_sign)
				fmt->p_sign = ' ';
		}
		else
			break;
		fmt->n_parse += 1;
		str++;
	}
	return;
}

void parse_padd(struct Format *fmt, char *str)
{
	str += fmt->n_parse;
	if (*str == '0')
	{
		fmt->padd_ch = '0';
		fmt->n_parse++;
		str++;
	}
	while ((ft_isdigit(*str)))
	{
		fmt->padd_len = fmt->padd_len * 10 + (*str - '0');
		fmt->n_parse++;
		str++;
	}
	return;
}
void parse_prec(struct Format *fmt, char *str)
{
	str += fmt->n_parse;
	if (*str == '.')
	{
		fmt->prec = 0;
		fmt->n_parse++;
		str++;
		while ((ft_isdigit(*str)))
		{
			fmt->prec = fmt->prec * 10 + (*str - '0');
			fmt->n_parse++;
			str++;
		}
	}
}

struct Format *ft_format(char *str)
{
	struct Format *fmt = init_fmt();
	parse_fmt(fmt, str);
	parse_padd(fmt, str);
	parse_prec(fmt, str);
	return fmt;
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list	args;
// 	int len;

// 	len = 0;
// 	va_start(args, str);
// 	while(*str)
// 	{
// 		if (*str == '%')
// 			len += ft_format(str++, args);

// 		len += ft_printchar((char *)str);
// 		str++;
// 	}
// 	va_end(args);
// 	return (len);
// }

// int main()
// {
// 	struct Format *frmt = ft_format("#+ -.12d");
// 	printf("PLUS SIGN: %c\n", frmt->p_sign);
// 	printf("ALT FORMAT: %d\n", frmt->alt_fmt);
// 	printf("LEFT ADJ: %d\n", frmt->ladj);
// 	printf("PADD CHAR: %c\n", frmt->padd_ch);
// 	printf("PADD LEN: %d\n", frmt->padd_len);
// 	printf("PRECISION: %d\n", frmt->prec);
// 	printf("NUM PARSED %d\n", frmt->n_parse);

// 	free(frmt);

// 	return (0);
// }
