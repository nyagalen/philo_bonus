/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:29:02 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/02 01:37:12 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_died(t_data *data)
{
	sem_wait(data->death_s);
	if (data->died == 1)
		return (sem_post(data->death_s), 1);
	sem_post(data->death_s);
	return (0);
}

int	rip(t_philo *philo)
{
	long	how_much_since_last_meal;
	long	cur;
	
	sem_wait(philo->meal_s);
	cur = get_time();
	how_much_since_last_meal = cur - philo->last_meal;
	if (how_much_since_last_meal > philo->data->time_to_die
		&& philo->eating == 0)
	{
		printf("What is cur? 	%ld\n", cur);
		printf("When was %d's last meal? %ld\n", philo->id, philo->last_meal);
		printf("How much since last meal?? %ld\n", how_much_since_last_meal);
		printf("is the motherfucker %d really not eating? %d\n", philo->id, philo->eating);
		sem_wait(philo->data->print_s);
		printf("%d died ALAS\n", philo->id);
		return (1);

	}
	sem_post(philo->meal_s);
	return (0);
}

int	dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].data->nb_ph)
	{
		if (rip(&philos[i]))
		{
			//print(&philos[i], "died");
			// sem_wait(philos[0].data->death_s);
			// philos[0].data->died = 1;
			// sem_post(philos[0].data->death_s);
			return (1);
		}
	}
	return (0);
}

int	all_ate(t_philo *philos)
{
	int	i;
	int	ate;

	i = -1;
	ate = 0;
	if (philos[0].data->max_meals == -1)
		return (0);
	while (++i < philos[0].data->nb_ph)
	{
		//sem_wait(philos[i].meal_s);
		if (philos[i].meals >= philos[0].data->max_meals)
			ate++;
		//sem_post(philos[i].meal_s);
		if (ate == philos[0].data->max_meals)
		{
			// sem_wait(philos[0].data->death_s);
			// philos[0].data->died = 1;
			// sem_post(philos[0].data->death_s);
			return (1);
		}
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	printf("did the monitor launch?\n");
	//sem_wait(philos[0].data->death_s);
	while (1)
	{
		if (dead(philos) || all_ate(philos))
		{
			sem_post(philos[0].data->death_s);
			break ;
		}
	}
	stop(philos, philos[0].data);
	return (NULL);
}
