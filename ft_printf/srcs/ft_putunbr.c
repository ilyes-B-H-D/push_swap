/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:06:15 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/19 15:06:16 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunbr(unsigned int k)
{
	char		c;
	int			count;

	count = 0;
	if (k <= 9)
	{
		c = k + 48;
		write (1, &c, 1);
		count++;
	}
	if (k > 9)
	{
		count += ft_putunbr(k / 10);
		count += ft_putunbr(k % 10);
	}
	return (count);
}
