/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:55:01 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/23 02:56:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int 		get_next_line(const int fd, char **line)
{
	int					ret;
	static char	list[OPEN_MAX][BUFF_SIZE + 1];
	char				buf[BUFF_SIZE];

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, buf, 0) < 0
			|| !(*line = ft_strnew(sizeof(char))))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ft_strchr(buf, '\n'))
		{
			ft_strcjoin(list[fd], buf, '\n');
			break;
		}
		ft_strjoin(list[fd], buf);
	}
	ft_putendl(list[fd]);
	ft_strcpy(*line, list[fd]);
	return (1);
}
