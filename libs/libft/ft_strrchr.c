/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:49:44 by plam              #+#    #+#             */
/*   Updated: 2019/10/14 16:40:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		i;
	unsigned const char	*str;

	i = ft_strlen(s);
	str = (unsigned char *)s;
	while (i > 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return ((char *)&s[i]);
	return (0);
}
