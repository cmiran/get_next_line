/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 04:11:14 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 14:33:21 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char const *s2, char c)
{
	size_t	n;
	size_t	i;
	char	*str;

	if (!s2 || (n = ft_strclen(s2, c)) == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1)) + n + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (n--)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

/*
** char	*ft_strcjoin(char const *s1, char const *s2, char c)
**{
**	size_t 	n;
**	size_t	i;
**	char	*str;
**
**	if (s1 || !s2 || (n = ft_strclen(s2, c)) == 0)
**		return (NULL);
**	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1)) + n + 1)))
**		return (NULL);
**	i = 0;
**	while (*s1)
**		str[i++] = *s1++;
**	while (n--)
**		str[i++] = *s2++;
**	str[i] = '\0';
**	return (str);
**}
*/
