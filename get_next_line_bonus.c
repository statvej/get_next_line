/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:12:14 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/11 14:18:13 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// //Function should return a string trimed of reminder after nl or '\0'
char	*trim_ret_str(char *left_over)
{
	int		ind;
	char	*ret;

	ind = 0;
	if (!left_over[0])
		return (NULL);
	while (left_over[ind] && left_over[ind] != '\n')
		ind++;
	ret = (char *)malloc(sizeof(char) * (ind + 2));
	if (!ret)
		return (NULL);
	ind = 0;
	while (left_over[ind] && left_over[ind] != '\n')
	{
		ret[ind] = left_over[ind];
		ind++;
	}
	if (left_over[ind] == '\n')
	{
		ret[ind] = left_over[ind];
		ind++;
	}
	ret[ind] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*left_over[4096];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_over[fd] = get_untrimed(left_over[fd], fd);
	if (!(left_over[fd]))
	{
		return (NULL);
	}
	ret = NULL;
	ret = trim_ret_str(left_over[fd]);
	left_over[fd] = get_left_over(left_over[fd]);
	return (ret);
}
