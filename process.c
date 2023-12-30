/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:26 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 11:44:59 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_process(t_philo *philos)
{
	int		i;
	pthread_t	vigil;

	i = -1;
	while (++i < philos[0].data->nb_ph)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			return (process(&philos[i]));
	}
	if (pthread_create(&vigil, NULL, &monitor, philos))
			return (0);
	return (1);
}


