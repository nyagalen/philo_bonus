/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:30:04 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/02 05:10:26 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philo *philos, t_data *data)
{
	int		i;
	char	*sem_name;
	char	*id_str;

	i = -1;
	while (++i < data->nb_ph)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].last_meal = get_time();
		id_str = ft_itoa(philos[i].id);
		if (!id_str)
			return (0);
		sem_name = ft_strjoin("/meal_s", id_str);
		if (!id_str || !sem_name)
			return (0);
		sem_unlink(sem_name);
		philos[i].meal_s = sem_open(sem_name, O_CREAT, 0644, 1);
		sem_unlink(sem_name);
		free(id_str);
		free(sem_name);
		philos[i].data = data;
	}
	return (1);
}

void	init_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/death_s");
	sem_unlink("/print_s");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->nb_ph);
	data->death_s = sem_open("/death_s", O_CREAT, 0644, 1);
	data->print_s = sem_open("/print_s", O_CREAT, 0644, 1);
	sem_unlink("/print_s");
	sem_unlink("/forks");
	sem_unlink("/death_s");
	sem_wait(data->death_s);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_ph = ft_atoi(argv[1]);
	data->died = 0;
	data->all_eaten = 0;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	if (data->nb_ph == 0 || data->time_to_die == 0
		|| data->time_to_eat == 0 || data->time_to_sleep == 0
		|| data->nb_ph > 200)
		return (0);
	if (data->max_meals == 0)
		exit(0);
	data->start_time = get_time();
	init_sem(data);
	return (1);
}
