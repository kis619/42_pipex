/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:07:26 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/26 22:07:26 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:07:24 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/26 22:07:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start_idx;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start_idx = 0;
	while (s1[start_idx] && ft_strchr(set, s1[start_idx]))
		start_idx++;
	len = ft_strlen(s1);
	while (len > start_idx && ft_strchr(set, s1[len - 1]))
		len--;
	str = (char *)malloc(sizeof(*s1) * (len - start_idx + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (start_idx < len)
		str[i++] = s1[start_idx++];
	str[i] = 0;
	return (str);
}
