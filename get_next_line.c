/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:50:48 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/23 03:00:09 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

void	del(t_list *list)
{
	t_list *tmp;

	while (list->next != NULL)
	{
		tmp = list;
		tmp->content_size = 0;
		ft_bzero(tmp->content, ft_strlen(tmp->content));
		list = tmp->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&list);
}

char	*join(char const *s1, char const *s2, char **loss)
{
	size_t	i;
	size_t	j;
	char		*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strclen(s2, '\n'))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	j = 0;
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] && (*loss = ft_strnew(ft_strlen(s2))))
		while (s2[j])
			*loss++ = (char *)&s2[j++];
	return (str);
}

t_list	*get_fd(t_list **list, const int fd, char **loss)
{
	t_list *file;

	file = *list;
	while (file)
	{
		if ((int)file->content_size == fd)
		{
			if(loss)
			{
				file->content = ft_strdup(*loss);
				ft_strdel(loss);
			}
			break;
		}
		file = file->next;
	}
	if (!file)
	{
		if (!(file = ft_lstnew("\0", BUFF_SIZE)))
			return (0);
		file->content_size = fd;
		ft_lstadd(list, file);
	}
	return (file);
}

int 		get_next_line(const int fd, char **line)
{
	int						ret;
	t_list					*curr;
	static t_list	*list;
	char					buf[BUFF_SIZE + 1];
	static char		*loss;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL
			|| !(curr = get_fd(&list, fd, &loss)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((curr->content = join(curr->content, buf, &loss)))
			break;
	}
	if (!(*line = ft_strdup(curr->content)))
		return (-1);
	del(curr);
	return (1);
}
