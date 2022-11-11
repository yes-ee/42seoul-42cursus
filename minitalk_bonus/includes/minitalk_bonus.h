/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:55:08 by yeselee           #+#    #+#             */
/*   Updated: 2022/10/10 18:21:14 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>

void		ft_putstr_fd(char *s, int fd);
// static void	ft_nb(int n, int fd);
void		ft_putnbr_fd(int n, int fd);
// static int	change_num_minus(int minus, int num);
int			ft_atoi(const char *str);

#endif