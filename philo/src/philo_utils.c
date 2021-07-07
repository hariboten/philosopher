/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:38:23 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 15:18:18 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

long	get_timestamp()
{
	struct timeval tp;
	struct timezone tzp;

	if (gettimeofday(&tp, &tzp))
		return (-1);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int		rightside_fork(t_dpp *dpp, int id)
{
	if (id == 0)
		return (dpp->number_of_philosophers - 1);
	return (id - 1);
}

int		leftside_fork(t_dpp *dpp, int id)
{
	(void) dpp;
	return id;
}
