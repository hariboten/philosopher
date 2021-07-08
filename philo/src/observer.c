/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:34:45 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 18:17:15 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"


static bool	is_starve(t_dpp *dpp, t_philosopher *philosopher)
{
	long	now;

	now = get_timestamp();
	if (now - philosopher->last_ate > dpp->time_to_die / U2M)
		return (true);
	return (false);
}

static bool	is_anyone_starve(t_dpp *dpp)
{
	int		i;

	i = 0;
	while (i < dpp->number_of_philosophers)
		if (is_starve(dpp, &dpp->philosophers[i++]))
		{
			pthread_mutex_lock(&dpp->output_mutex);
			printf("%ld %d is died\n", get_timestamp(), i + 1);
			dpp->fin_flag = true;
			pthread_mutex_unlock(&dpp->output_mutex);
			return (true);
		}
	return (false);
}

static bool	philosophers_ate_enough(t_dpp *dpp)
{
	int		i;

	if (dpp->number_of_times_each_philosopher_must_eat == 0)
		return (false);
	i = 0;
	while (i < dpp->number_of_philosophers)
		if (dpp->philosophers[i++].ate_counter < dpp->number_of_times_each_philosopher_must_eat)
			return (false);
	return (true);
}

void	*observer_thread(void *arg)
{
	t_dpp	*dpp;

	dpp = (t_dpp *)arg;
	while (true)
	{
		if (is_anyone_starve(dpp))
			break ;
		if (philosophers_ate_enough(dpp))
			break ;
		usleep(1000);
	}
	dpp->fin_flag = true;
	return (NULL);
}
