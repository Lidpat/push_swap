/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:16:36 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 22:00:59 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_substr(char const *s, char c)
{
	char	*str;

	str = (char *)s;
	if (c == 0)
		return (str);
	while (*str != 0 && *str == c)
		str++;
	return (str);
}

static size_t	count_substr(char const *s, char c)
{
	char	*str;

	if (c == 0)
		return (2);
	str = trim_substr (s, c);
	str = ft_strchr(str, c);
	if (str == NULL)
		return (2);
	else
		return (count_substr(str, c) + 1);
}

static char	**init_matrix(size_t rows, char *str, char c)
{
	size_t	i;
	char	**matrix;

	matrix = (char **)ft_calloc (rows, sizeof(char *));
	if (matrix == NULL)
	{
		free (str);
		return (NULL);
	}
	matrix [0] = str;
	i = 1;
	while (i < rows - 1)
	{
		matrix[i] = ft_strchr(matrix[i - 1], c);
		*matrix[i] = 0;
		matrix[i] = trim_substr(matrix[i] + 1, c);
		i++;
	}
	return (matrix);
}

static char	**assign_matrix(size_t rows, char **matrix)
{
	size_t	i;

	i = 0;
	while (i < rows - 1)
	{
		matrix[i] = ft_substr(matrix[i], 0, ft_strlen(matrix[i]));
		if (matrix[i] == NULL)
		{
			while (--i)
				free(matrix[i]);
			free (matrix);
			return (NULL);
		}
		i++;
	}
	matrix[rows - 1] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	cs[2];
	char	*str;
	char	**matrix;
	size_t	rows;

	cs[0] = c;
	cs[1] = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strtrim(s, cs);
	if (str == NULL)
		return (NULL);
	if (*str == 0)
		rows = 1;
	else
		rows = count_substr(str, c);
	matrix = init_matrix(rows, str, c);
	if (matrix == NULL)
		return (NULL);
	matrix = assign_matrix(rows, matrix);
	free (str);
	return (matrix);
}
