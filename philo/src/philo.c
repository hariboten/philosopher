/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:04:05 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 14:54:17 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

static void				*philos_thread(void *arg)
{
	t_dpp *dpp;
	t_philosopher *philosopher;
	int		id;

	philosopher = arg;
	dpp = philosopher->dpp;
	id = philosopher->id;
	while (!dpp->fin_flag)
	{
		if (id % 2)
			act_take_a_fork(dpp, id, rightside_fork(dpp, id));
		act_take_a_fork(dpp, id, leftside_fork(dpp, id));
		if (!id % 2)
			act_take_a_fork(dpp, id, rightside_fork(dpp, id));
		act_eat(dpp, id);
		philosopher->ate_counter++;
		if (dpp->fin_flag)
			break ;
		act_sleep(dpp, id);
		if (dpp->fin_flag)
			break ;
		act_think(dpp, id);
	}
	return (NULL);
}

static t_philosopher	*init_philosopher(t_philosopher *to_init, t_dpp *dpp, int id)
{
	to_init->dpp = dpp;
	to_init->id = id;
	to_init->ate_counter = 0;
	to_init->last_ate = get_timestamp();
	return ((void *)to_init);
}

void					dining_philos_prob(t_dpp *dpp)
{
	pthread_t	*threads;
	pthread_t	observer;
	int			i;
	int			err_flag;

	if (!(threads = malloc(dpp->number_of_philosophers * sizeof(pthread_t))))
		return ;
	err_flag = 0;
	i = 0;
	while (i < dpp->number_of_philosophers)
		err_flag |= pthread_create(&threads[i], NULL, philos_thread, init_philosopher(&dpp->philosophers[i], dpp, i));
	if (!err_flag)
		err_flag |= pthread_create(&observer, NULL, observer_thread, dpp);
	if (!err_flag)
		err_flag |= pthread_join(observer, NULL);
	i = 0;
	while (i < dpp->number_of_philosophers)
		pthread_detach(threads[i]);
	free(threads);
	if (err_flag)
		ft_putstr_fd("philo: failed to create thread\n", 2);
	return ;
}
