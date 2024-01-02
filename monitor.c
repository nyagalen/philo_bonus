/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:29:02 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/02 05:11:56 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eaten_max(t_philo *philo)
{
	if (philo->meals == philo->data->max_meals
		&& philo->data->max_meals > 0)
	{
		philo->data->all_eaten++;
		return (1);
	}
	return (0);
}

void	*rip(void *pointer)
{
	t_philo	*philo;
	long	cur;

	philo = (t_philo *)pointer;
	while (1)
	{
		cur = get_time();
		if (cur - philo->last_meal >= philo->data->time_to_die)
		{
			sem_wait(philo->data->print_s);
			printf("%ld %d died\n",
				cur - philo->data->start_time, philo->id);
			sem_post(philo->data->print_s);
			sem_post(philo->data->death_s);
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	sem_wait(philos[0].data->death_s);
	stop(philos, philos[0].data);
	return (NULL);
}
