/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:50:48 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/19 13:12:21 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

void		*del(char *str, size_t n)
{
	ft_bzero(str, n + 1);
	free(str);
	return (0);
}

t_list	*get_fd(t_list **list, const int fd)
{
	t_list *file;

	file = *list;
	while (file)
	{
		if ((int)file->content_size == fd)
			break;
		file = file->next;
	}
	if (!(file = ft_lstnew("\0", BUFF_SIZE)))
		return (0);
	ft_lstadd(list, file);
	file = *list;
	file->content_size = fd;
	return (file);
}

int 		get_next_line(const int fd, char **line)
{
	int						ret;
	t_list				*curr;
	static t_list	*list;
	char					buf[BUFF_SIZE + 1];

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, buf, 0) < 0
			|| (!(curr = get_fd(&list, fd))))
		return (-1);
	if (!(*line = ft_strnew(sizeof(char))))
		return (-1);
	ft_print_memory(line, sizeof(t_list));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ft_strchr(buf, '\n'))
		{
			curr->content = ft_strcjoin(curr->content, buf, '\n');
			break;
		}
		curr->content = ft_strjoin(curr->content, buf);
	}
	ft_strcpy((char *)line, curr->content);
	ft_print_memory(line, sizeof(t_list));
	printf("%s\n", (char *)line);
	ft_lstdel(&curr, del(curr->content, BUFF_SIZE));
	return (1);
}
