#include "libft.h"

size_t ft_nbrbase_len(unsigned long long nbr, size_t blen)
{
	size_t len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= blen;
		len++;
	}
	return (len);
}