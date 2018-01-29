/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:45:11 by jchung            #+#    #+#             */
/*   Updated: 2018/01/29 14:36:12 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			ft_strlen(const char *s1)
{
	const char *s2;

	s2 = s1;
	while (*s1)
		s1++;
	return (s1 - s2);
}

char	*ft_strstr(const char *big, const char *little)
{
	char	*b1;
	char	*b2;
	char	*l1;

	if (!*little)
		return ((char *)big);
	b1 = (char *)big;
	while (*b1)
	{
		b2 = b1;
		l1 = (char *)little;
		while (*b2 && *l1 && *b2 == *l1)
		{
			b2++;
			l1++;
		}
		if (!*l1)
			return (b1);
		b1++;
	}
	return ((char *)0);
}

int			is_latin(char **str, int arrlen)
{
	int		i;

	i = 0;
	while (++i < arrlen)
		if (!ft_strstr(str[i], "42"))
			return (0);
	return (1);
}

void		ft_latin(char **str, int arrlen)
{
	char	*tmp;
	int		tmpsize;
	int		len;
	int		i;
	int		j;
	int		k;

	if (arrlen > 1)
	{
		i = 1;
		if (!is_latin(str, arrlen))
		{
			//Write latin
			if (i < arrlen)
			{
				len = ft_strlen((const char *)str[i]);
				tmpsize = len + 2;
				tmp = (char *)malloc(sizeof(char) * tmpsize);
				j = 1;
				k = 0;
				while (j < len)
					tmp[k++] = str[i][j++];
				if (str[i][0])
					tmp[k++] = str[i][0];
				tmp[k++] = '4';
				tmp[k] = '2';
				write(1, tmp, tmpsize);
				i++;
			}
			while (i < arrlen)
			{
				len = ft_strlen((const char *)str[i]);
				tmpsize = len + 2;
				tmp = (char *)malloc(sizeof(char) * tmpsize);
				j = 1;
				k = 0;
				while (j < len)
					tmp[k++] = str[i][j++];
				if (str[i][0])
					tmp[k++] = str[i][0];
				tmp[k++] = '4';
				tmp[k] = '2';
				write(1, " ", 1);
				write(1, tmp, tmpsize);
				i++;
			}
		}
		else
		{
			if (i < arrlen)
			{
				len = ft_strlen((const char *)str[i]);
				tmpsize = len - 2;
				tmp = (char *)malloc(sizeof(char) * tmpsize);
				j = tmpsize - 1;
				k = 0;
				if (j >= 0)
					tmp[k++] = str[i][j];
				j = 0;
				while (k < tmpsize)
					tmp[k++] = str[i][j++];
				write(1, tmp, tmpsize);
				i++;
			}
			while (i < arrlen)
			{
				len = ft_strlen((const char *)str[i]);
				tmpsize = len - 2;
				tmp = (char *)malloc(sizeof(char) * tmpsize);
				j = tmpsize - 1;
				k = 0;
				if (j >= 0)
					tmp[k++] = str[i][j];
				j = 0;
				while (k < tmpsize)
					tmp[k++] = str[i][j++];
				write(1, " ", 1);
				write(1, tmp, tmpsize);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}
