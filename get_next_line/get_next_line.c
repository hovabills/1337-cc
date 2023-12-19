#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000 

size_t	ft_strlen(char *str)
{
	size_t	len;
	
	len = 0;
	while (*str++)
		len++;
	return len;
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strcat(char *dst, char *src)
{
	while (*dst)
		dst++;
	ft_strcpy(dst, src);
}	
	
char	*ft_strchrnl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return str;
		str++;
	}
	return NULL;
}

char	*ft_substr(char *str, size_t len)
{
	size_t	i;
	char	*sub;
	
	sub = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		sub[i] = str[i];
		i++;
	}
	sub[i] = '\0';
	return sub;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;

	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return result;
}

char	*ft_strdup(char *str)
{
	char	*dup;
	
	dup = (char *)malloc(ft_strlen(str) + 1);
	ft_strcpy(dup, str);
	return dup;
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	prev_line[BUFFER_SIZE + 1];
	char		*next_line;
	char		*tmp_line;
	char		*sub_line;
	char		*nl;
	int		br;
	
	if (( nl = ft_strchrnl(prev_line)))
	{
		next_line = ft_substr(prev_line, (nl + 1) - prev_line);	
		ft_strcpy(prev_line, nl + 1);
		return next_line;
	}
	next_line = ft_strdup(prev_line);
	br = read(fd, buff, BUFFER_SIZE); 
	while (br > 0)
	{
		buff[br] = '\0';
		if ((nl = ft_strchrnl(buff)))
		{
			sub_line = ft_substr(buff, (nl + 1) - buff);
			tmp_line = next_line;
			next_line = ft_strjoin(next_line, sub_line);
			free(sub_line);
			free(tmp_line);
			ft_strcpy(prev_line, nl + 1);
			return next_line;	
		}
		tmp_line = next_line;
		next_line = ft_strjoin(next_line, buff);
		free(tmp_line);
		br = read(fd, buff, BUFFER_SIZE);
	}
	if (br <= 0)
	{
		free(next_line);
		return NULL;
	}		
	return next_line;	
}

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}	
	free(line);
	close(fd);
	return 0;
}
