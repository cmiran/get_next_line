/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:55:01 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/29 21:30:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*list[OPEN_MAX];
	int			i;
	int			ret;
	char		buf[BUFF_SIZE];
	char		*tmp;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, NULL, 0))
		return (-1);
	else if (!(list[fd]) && (!(list[fd] = ft_strnew(BUFF_SIZE))))
		return (-1);
	else if (ft_strchr(list[fd], '\n') || ft_strchr(list[fd], '\0'))
	{
		i = ft_strclen(list[fd], '\n');
		tmp = list[fd];
		if (!(list[fd] = ft_strsub(list[fd], i + 1, ft_strlen(list[fd]) - i)))
			return (-1);
		free(tmp);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = list[fd];
		if (!(list[fd] = ft_strjoin(list[fd], buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (list[fd][0] == '\0')
		return (0);
	if (!(*line = ft_strcdup(list[fd], '\n')))
		return (-1);
	return (1);
}
