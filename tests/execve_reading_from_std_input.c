/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_reading_from_std_input.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:59:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/10 19:59:18 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int main (int argc, char *argv[])
{
	// char *elements[4] = {"нещо на български", "-l", "-a", NULL};
	char *cmd;
	char **cmd_flags;

	cmd_flags = ft_split(argv[2], ' ');

	cmd = ft_strjoin("/usr/bin/", cmd_flags[0]);
	execve(cmd, cmd_flags, NULL);
	return (0);
}