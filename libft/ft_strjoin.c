/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:45:58 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 14:34:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères “fraiche”
** terminée par un ’\0’ résultant de la concaténation de s1 et s2.
** Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

/*
** char	*ft_strjoin(char const *s1, char const *s2)
** {
**	size_t	i;
**	char	*str;
**
**	if (s1 || !s2)
**		return (NULL);
**	if (!(str = (char *)malloc(sizeof(*str)
**					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
**		return (NULL);
**	i = 0;
**	while (*s1)
**		str[i++] = *s1++;
**	while (*s2)
**		str[i++] = *s2++;
**	str[i] = '\0';
**	return (str);
** }
*/
