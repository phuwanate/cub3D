/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:43:27 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 13:44:02 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset(void *str, int val, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (num > 0)
	{
		*ptr = (unsigned char)val;
		num--;
		ptr++;
	}
	return (str);
}

void	ft_bzero(void *str, size_t num)
{
	ft_memset(str, 0, num);
}
// fill zero to (str), (num) byte