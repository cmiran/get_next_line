/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:44:09 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/23 02:22:13 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>

#define X	(argc - 1)

int		main(int argc, char **argv)
{
	int		fd;
	int		fe;
	int		ff;
	int		fg;
	char	*line;
	int		i;

	if (argc == 1)
		return (0);
	i = 0;
	while (argc > ++i)
	{
		fd = open(argv[i++], O_RDONLY);
		fe = open(argv[i++], O_RDONLY);
		ff = open(argv[i++], O_RDONLY);
		fg = open(argv[i], O_RDONLY);
	}
	if (argc == 2)
	{
		while (i - 1 > 1)
		{
			while (get_next_line(fd, &line) == 1)
			{	
				ft_putendl(line);
				free(line);
			}
			i--;
		}
		close(fd);
	}
	if (argc == 2)
	{
		while (i - 1 > 1)
		{
			while (get_next_line(fe, &line) == 1)
			{	
				ft_putendl(line);
				free(line);
			}
			i++;
		}
	close(fe);
	}
	if (argc == 3)
	{
		while (i + 1 > 1)
		{
			while (get_next_line(ff, &line) == 1)
			{
				ft_putendl(line);
				free(line);
			}
			i--;
		}
		close(ff);
	}
	if (argc == 4)
	{
		while (i - 1 > 1)
		{
			while (get_next_line(fg, &line) == 1)
			{
				ft_putendl(line);
				free(line);
			}
			i++;
		}
	close(fg);
	}
	return (0);
} 
