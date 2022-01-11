/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:42:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/11 17:42:59 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	open("asfasf", O_RDONLY);
	perror("Failed");
	return (0);
}