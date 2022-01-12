/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:40:28 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 12:40:28 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

int		ft_print_according_to_type(char letter, va_list args);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_test(int expected, int actual, int index);
int		ft_printf(const char *str, ...);
int		ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		ft_put_hexa_x_fd(long long unsigned n, int fd, char up_or_low);

#endif