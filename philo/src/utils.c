/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:41:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 15:38:24 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

bool	is_numeric(const char *str)
{
	if (!*str)
		return (false);
	if (*str == '0')
		return (false);
	if (*str == '-')
		str++;
	while  (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

int		ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	num = 0;
	while (*str >= '0'&& *str <= '9')
		num = num * 10 + *str++ - '0';
	num *= sign;
	return (num);
}
