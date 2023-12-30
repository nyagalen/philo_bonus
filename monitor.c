/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:29:02 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 15:55:08 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	rip(t_philo *philo)
{
	sem_wait(philo->meal_s);
	if (get_time() - philo->last_meal >= philo->data->time_to_die
			&& philo->eating == 0)
		return (sem_post(philo->meal_s), 1);
	sem_post(philo->meal_s);
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = pointer;
	sem_wait(philos[0].data->death_s);
	stop(philos, params);
	return (NULL);
}
