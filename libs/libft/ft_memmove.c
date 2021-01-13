/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:22:35 by plam              #+#    #+#             */
/*   Updated: 2019/10/25 11:21:32 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp;
	unsigned char	*sc;
	unsigned char	*dst;

	tmp = 0;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dst > sc)
	{
		while (n)
		{
			tmp = sc[n - 1];
			dst[n - 1] = tmp;
			n--;
		}
	}
	else
		ft_memcpy(dst, sc, n);
	return (dest);
}
