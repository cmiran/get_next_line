/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:33:55 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/20 20:10:46 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	ft_memset(str, c, size);
	str[size + 1] = '\0';
	return (str);
}
