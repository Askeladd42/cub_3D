/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:42:13 by plam              #+#    #+#             */
/*   Updated: 2021/01/07 08:52:40 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	j = ft_strlen(&s1[i]);
	while (j > 0 && ft_strchr(set, s1[i + j - 1]) != 0)
		j--;
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
		return (NULL);
	k = 0;
	while (k < j)
	{
		dest[k] = s1[i + k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
