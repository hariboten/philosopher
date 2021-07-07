/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:24:02 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 14:24:05 by ewatanab         ###   ########.fr       */
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

void	act_take_a_fork(t_dpp *dpp, int id, int fork)
{
	pthread_mutex_lock(&dpp->forks[fork]);
	if (dpp->fin_flag)
		return ;
	printf("%ld %d has taken a fork\n", get_timestamp(), id);
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

void	act_eat(t_dpp *dpp, int id)
{
	if (!dpp->fin_flag)
	{
		printf("%ld %d is eating\n", get_timestamp(), id);
		usleep(dpp->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&dpp->forks[rightside_fork(dpp, id)]);
	pthread_mutex_unlock(&dpp->forks[leftside_fork(dpp, id)]);
}

void	act_sleep(t_dpp *dpp, int id)
{
	printf("%ld %d is sleeping\n", get_timestamp(), id);
	usleep(dpp->time_to_sleep * 1000);
}

void	act_think(t_dpp *dpp, int id)
{
	(void)dpp;
	printf("%ld %d is thinking\n", get_timestamp(), id);
}
