/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */ ssh-add -l -E sha256
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:57:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/08 20:57:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <process.h>

int main (void)
{
	// execve("a.out", [[], [NULL]], [NULL]);
	execlp("echo", "echo", NULL);
	return (0);
}