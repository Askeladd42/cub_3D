/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:22:57 by plam              #+#    #+#             */
/*   Updated: 2019/10/24 11:55:00 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	while (n--)
	{
		*dst = *sc;
		if (*dst == (unsigned char)c)
			return (dest + 1);
		dst++;
		dest++;
		sc++;
	}
	return (0);
}
