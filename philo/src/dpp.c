/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:55:49 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 14:33:32 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

static int	init_err(enum e_init_errno init_errno)
{
	if (init_errno == ENUMARG)
		ft_putstr_fd("dpp: number of arguments is invalid\n", 2);
	if (init_errno == EINVARG)
		ft_putstr_fd("philo: invalid argument\n", 2);
	if (init_errno == EALLOC)
		ft_putstr_fd("dpp: allocate error", 2);
	return (-1);
}

static int	parse_arg(t_dpp *dpp, int argc, char **argv)
{
	int		i;

	if (argc != 5 && argc != 6)
		return (init_err(ENUMARG));
	i = 1;
	while (i < argc)
		if (!is_numeric(argv[i++]))
			return (init_err(EINVARG));
	dpp->number_of_philosophers = ft_atoi(argv[1]);
	dpp->time_to_die = ft_atoi(argv[2]);
	dpp->time_to_eat = ft_atoi(argv[3]);
	dpp->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dpp->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		dpp->number_of_times_each_philosopher_must_eat = 0;
	return (0);
}

/*
 * int dpp_init(t_dpp *dpp, int argc, char **argv)
 *  - dpp: pointer of the object to initialize
 *  - argc, argv: command line arguments
 *  - return value: 0 if success, -1 other
 *
 *  - instant argument check
 *  - set value of dpp object
 *  - allocate mem of philosopher objects
 *     - not initialized;
 *  - allocate mem of mutex objects
 *  - init mutex object
 */
int			dpp_init(t_dpp *dpp, int argc, char **argv)
{
	int		i;

	if (!parse_arg(dpp, argc, argv))
		return (-1);
	dpp->fin_flag = false;
	if (!(dpp->philosophers = malloc(dpp->number_of_philosophers * sizeof(t_philosopher))))
		return (init_err(EALLOC));
	if (!(dpp->forks = malloc(dpp->number_of_philosophers * sizeof(pthread_mutex_t))))
	{
		free(dpp->philosophers);
		return (init_err(EALLOC));
	}
	i = 0;
	while (i < dpp->number_of_philosophers)
		if (pthread_mutex_init(&dpp->forks[i++], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&dpp->forks[i]);
			free(dpp->philosophers);
			free(dpp->forks);
			return (init_err(EMUTINIT));
		}
	return (0);
}

void		dpp_destroy(t_dpp *dpp)
{
	int		i;

	free(dpp->philosophers);
	i = 0;
	while (i < dpp->number_of_philosophers)
		pthread_mutex_destroy(&dpp->forks[i]);
}
