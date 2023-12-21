/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:57:47 by kburalek          #+#    #+#             */
/*   Updated: 2023/12/15 17:58:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != 10)
		i++;
	if (buf[i] == 10)
		return (1);
	return (0);
}
