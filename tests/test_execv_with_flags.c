/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execv_with_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:21:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/10 10:21:57 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*list[8] = {"/usr/bin/grep", "гърмя", "random_test_file", NULL};

	execve("/usr/bin/grep", list, NULL);
}
