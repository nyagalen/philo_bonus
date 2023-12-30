/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:29:02 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 11:44:45 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = pointer;
	sem_wait(philos[0].data->death_s);
	stop(philos, params);
	return (NULL);
}
