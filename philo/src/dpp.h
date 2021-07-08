/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:26:42 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 18:16:57 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPP_H
# define DPP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define U2M 1000L

enum	e_init_errno
{
	ENUMARG = 1,
	EINVARG,
	EALLOC,
	EMUTINIT
};

struct s_philosopher;
typedef struct s_philosopher t_philosopher;

typedef struct s_dpp
{
	int				number_of_philosophers;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	bool			fin_flag;
	t_philosopher	*philosophers;
	pthread_mutex_t *forks;
	pthread_mutex_t output_mutex;
} t_dpp;

struct s_philosopher
{
	t_dpp		*dpp;
	int			id;
	int			ate_counter;
	long long	last_ate;
};

/*
 * dpp.c
 */
void	dpp_destroy(t_dpp *dpp);
int		dpp_init(t_dpp *dpp, int argc, char **argv);

/*
 * philo.c
 */
void	dining_philos_prob(t_dpp *dpp);

/*
 * observer.c
 */
void	*observer_thread(void *arg);

/*
 * action.c
 */
void	act_take_a_fork(t_dpp *dpp, int id, int fork);
void	act_eat(t_dpp *dpp, int id);
void	act_sleep(t_dpp *dpp, int id);
void	act_think(t_dpp *dpp, int id);

/*
 * philo_utils.c
 */
long	get_timestamp();
int		rightside_fork(t_dpp *dpp, int id);
int		leftside_fork(t_dpp *dpp, int id);

/*
 * utils.c
 */
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);
bool	is_numeric(const char *str);

#endif
