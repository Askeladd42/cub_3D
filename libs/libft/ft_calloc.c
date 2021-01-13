/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:29:37 by plam              #+#    #+#             */
/*   Updated: 2021/01/06 15:11:27 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dest;
	size_t			i;
	size_t			bytes;

	bytes = size * count;
	dest = (unsigned char *)malloc(bytes);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		dest[i] = '\0';
		i++;
	}
	return ((void *)dest);
}
