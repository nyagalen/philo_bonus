/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:01:54 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 08:25:27 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philos, t_data *data)
{
	int	i;
	
	i = -1;
	while (++i < data->nb_ph)
		sem_close(philos[i].meal_s);
	sem_close(data->forks);
	sem_close(data->death_s);
	sem_close(data->print_s);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philos[200];

	if (argc > 6 || argc < 5 || !check_args(argc, argv)
		|| !init_data(&data, argc, argv))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (!init_philos(philos, &data))
	{
		printf("Malloc error\n");
		return (1);
	}
	free_all(philos, &data);
	return (0);
}
