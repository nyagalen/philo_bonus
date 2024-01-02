/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:26 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/02 01:28:32 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_ph)
		kill(philos[i].pid, SIGTERM);
	return (EXIT_FAILURE);
}

int	launch_process(t_philo *philos)
{
	int			i;
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

void	take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

int	process(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		if (philo->meals >= philo->data->max_meals
			&& philo->data->max_meals > 0)
			break ;
		take_fork(philo);
		take_fork(philo);
		print(philo, "is eating");
		philo->eating = 1;
		sem_wait(philo->meal_s);
		philo->eating = 1;
		printf("Does the eating for %d get updated? %d\n", philo->id, philo->eating);
		philo->meals++;
		philo->last_meal = get_time();
		printf("Does last meal for %d get updated? %ld\n", 
		philo->id, philo->last_meal);
		sem_post(philo->meal_s);
		ft_usleep(philo->data->time_to_eat);
		release_forks(philo);
		philo->eating = 0;
		print(philo, "is thinking");
	}
	sem_post(philo->data->death_s);
	return (1);
}
