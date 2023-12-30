/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:01:54 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 07:25:51 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (0);
}
