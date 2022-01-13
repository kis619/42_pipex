/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:55:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/13 14:55:27 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include "libft/libft.h"
# include "printf/printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <errno.h>

void	close_desctiptors(int n_fds, ...);
char	**ft_free(char **array);
void	ft_validity_check(int n, char *error_message);
void	check_number_of_arguments(int n);
char	**get_paths(char *env[]);

#endif