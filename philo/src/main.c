/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:42:16 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/07 17:06:16 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpp.h"

/*
 * dpp.c
 * 	typdef struct s_dpp t_dpp;
 *  void	dpp_destroy(t_dpp *dpp);
 *  int		dpp_init(t_dpp *dpp, int argc, char **argv);
 */
int		main(int argc, char **argv)
{
	t_dpp dpp;

	if (dpp_init(&dpp, argc, argv))
		return (-1);
	dining_philos_prob(&dpp);
	dpp_destroy(&dpp);
	return (0);
}
