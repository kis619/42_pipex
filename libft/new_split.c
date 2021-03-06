/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:16:45 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/26 22:16:45 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	ft_find_word(char **next_str, int *s_len, char c);

char	**new_split(char const *s, char c)
{
	char	**strings;
	char	*next_str;
	int		s_len;
	int		nbr_strings;
	int		i;

	if (!s)
		return (NULL);
	nbr_strings = 2;
	strings = (char **)ft_calloc(nbr_strings + 1, sizeof(char *));
	if (!(strings))
	{
		return (NULL);
	}
	i = -1;
	s_len = 0;
	next_str = (char *)s;
	while (++i < nbr_strings)
	{
		ft_find_word(&next_str, &s_len, c);
		strings[i] = (char *)ft_calloc(s_len + 1, sizeof(char));
		ft_strlcpy(strings[i], next_str, s_len + 1);
	}
	strings[i] = NULL;
	return (strings);
}

static void	ft_find_word(char **next_str, int *s_len, char c)
{
	int	i;
	static int count = 0;

	*next_str += *s_len;
	*s_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	count += 1;
	while ((*next_str)[i])
	{
		if (count > 1)
		{
			if ((*next_str)[i] == '\0')
			return ;
		}
		else
		{
			if ((*next_str)[i] == c)
			return ;
		}
		(*s_len)++;
		i++;
	}
}

// static char	**ft_free(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (NULL);
// }

// #include <unistd.h>
// void	ft_print_result(char const *s)
// {
// 	int		len;
// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }
// int main()
// {
// 	char	**tabstr;
// 	int		i;
// 	i = 0;
// 	if (!(tabstr = ft_split("wc -l -l", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
				
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	ft_free(tabstr);
// }
