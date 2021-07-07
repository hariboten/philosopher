/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:24:02 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 15:18:50 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

void	act_take_a_fork(t_dpp *dpp, int id, int fork)
{
	pthread_mutex_lock(&dpp->forks[fork]);
	if (dpp->fin_flag)
		return ;
	printf("%ld %d has taken a fork\n", get_timestamp(), id);
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
