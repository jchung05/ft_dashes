/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:45:11 by jchung            #+#    #+#             */
/*   Updated: 2018/01/29 14:08:53 by jchung           ###   ########.fr       */
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
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	ft_latin(argv, argc);
	return (0);
}
