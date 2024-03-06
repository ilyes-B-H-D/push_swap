/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:06:08 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/19 15:09:33 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	long	k;
	char	c;
	int		count;

	k = n;
	count = 0;
	if (k < 0)
	{
		write (1, "-", 1);
		k *= -1;
		count++;
	}
	if (k >= 0 && k <= 9)
	{
		c = k + 48;
		write (1, &c, 1);
		count++;
	}
	if (k > 9)
	{
		count += ft_putnbr(k / 10);
		count += ft_putnbr(k % 10);
	}
	return (count);
}
