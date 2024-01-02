/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:40 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/01 22:25:01 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_wait(t_philo *philos, t_data *data)
{
	int	i;
	int	return_code;

	i = -1;
	return_code = 1;
	while (++i < data->nb_ph)
	{
		if (waitpid(philos[i].pid, NULL, 0) == -1)
			return_code = 0;
	}
	return (return_code);
}
