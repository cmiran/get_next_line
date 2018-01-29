/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:55:01 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/26 22:33:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int 		get_next_line(const int fd, char **line)
{
	static char	*list[OPEN_MAX];
	int					ret;
	char				buf[BUFF_SIZE];

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	if (!(list[fd]) && (!(list[fd] = ft_strnew(BUFF_SIZE))))
			return (-1);
	else if (ft_strchr(list[fd], '\n'))
	{
		if(!(*line = ft_strcdup(list[fd], '\n')))
			return (-1);
	}
	else
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
			ft_strjoin(list[fd], buf);
		if (!(*line = ft_strcdup(list[fd], '\n')))
			return (-1);
	}
	if ((ft_strclen(list[fd], '\n') != ft_strlen(list[fd]))
			&& (ft_strclen(list[fd], '\n') != (ft_strlen(list[fd]) - 1)))
	 if (!(list[fd] = ft_strsub(list[fd], ft_strclen(list[fd], '\n'),
				 ft_strlen(list[fd]) - ft_strclen(list[fd], '\n'))))
		 return (-1);
	return (1);
}
