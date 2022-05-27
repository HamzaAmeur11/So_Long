/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:24:32 by hameur            #+#    #+#             */
/*   Updated: 2022/05/17 01:51:59 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{
		while (src[j] != '\0' && j < dstsize - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	rouller;
	size_t	x;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	rouller = 0;
	x = len_dst;
	if (src[0] == 0)
		return (len_dst);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	if (len_dst < dstsize)
	{
		while (src[rouller] != 0 && x < dstsize - 1)
			dst[x++] = src[rouller++];
		dst[x] = 0;
		return (len_dst + len_src);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(len_s1 + len_s2 + 1);
	if (p == 0)
	{
		free(p);
		return (NULL);
	}
	ft_strlcpy(p, s1, (size_t)len_s1 + 1);
	ft_strlcat(p, s2, (size_t)len_s1 + len_s2 + 1);
	free(s1);
	return (p);
}
