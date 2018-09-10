/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:44:09 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/06 15:21:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"
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
	argc > 1 ? fd = open(argv[1], O_RDONLY) : 0;
	argc > 2 ? fe = open(argv[2], O_RDONLY) : 0;
	argc > 3 ? ff = open(argv[3], O_RDONLY) : 0;
	argc > 4 ? fg = open(argv[4], O_RDONLY) : 0;
	if (argc > 1)
	{
		while (get_next_line(fd, &line) > 0)
		{	
			ft_putendl(line);
			free(line);
		}
		close(fd);
	}
	if (argc > 2)
	{
		while (get_next_line(fe, &line) > 0)
		{	
			ft_putendl(line);
			free(line);
		}
		close(fe);
	}
	if (argc > 3)
	{
		while (get_next_line(ff, &line) > 0)
		{
			ft_putendl(line);
			free(line);
		}
		close(ff);
	}
	if (argc > 4)
	{
		while (get_next_line(fg, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
		close(fg);
	}
	return (0);
} 
