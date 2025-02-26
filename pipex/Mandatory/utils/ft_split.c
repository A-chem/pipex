#include "../include/pipex.h"
static int	count_word(char const *str, char c)
{
	int		i;
	int		limit;

	i = 0;
	limit = 0;
	while (*str)
	{
		if (*str != c && limit == 0)
		{
			limit = 1;
			i++;
		}
		else if (*str == c)
			limit = 0;
		str++;
	}
	return (i);
}

static char	*word(char const *s, size_t start, size_t end)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

static void	free_split(char **split, size_t j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
}

static int	split_words(char **split, char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = word(s, index, i);
			if (!split[j++])
			{
				free_split(split, j - 1);
				return (0);
			}
			index = -1;
		}
		i++;
	}
	split[j] = NULL ;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!split_words(split, s, c))
		return (NULL);
	return (split);
}