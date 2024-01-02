/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:32:33 by svydrina          #+#    #+#             */
/*   Updated: 2024/01/02 01:04:22 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_itoa(int num)
{
	int		len;
	int		dup;
	char	*toa;

	len = 0;
	dup = num;
	while (dup > 0)
	{
		len++;
		dup /= 10;
	}
	toa = malloc(len + 1);
	toa[len--] = '\0';
	while (num > 0)
	{
		toa[len--] = num % 10 + 48;
		num /= 10;
	}
	return (toa);
}

int	ft_atoi(char *num)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (num[++i])
		res = res * 10 + num[i] - 48;
	return (res);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
