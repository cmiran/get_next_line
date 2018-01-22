/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:19:33 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/30 19:49:51 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	if (dst == src)
		return (dst);
	cdst = (char *)dst;
	csrc = (const char *)src;
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
