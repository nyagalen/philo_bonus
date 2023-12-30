/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:38:29 by svydrina          #+#    #+#             */
/*   Updated: 2023/12/30 05:46:33 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int		id;
	int		meals;
	long		last_meal;
	sem_t		*meal_s;
	struct s_data	*data;
}	t_philo;

typedef struct	s_data
{
	int		nb_ph;
	int		max_meals;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	sem_t	*forks;
	sem_t	*death_s;
	sem_t	*print_s;
}	t_data;

int		init_philos(t_philo *philos, t_data *data);
int		init_data(t_data *data, int argc, char **argv);
void	init_sem(t_data *data);
char	*ft_itoa(int num);
int		ft_atoi(char *num);
int		check_args(int argc, char *argv);
long	get_time(void);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
