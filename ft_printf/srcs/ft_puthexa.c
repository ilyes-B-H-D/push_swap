/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:06:05 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/19 15:06:06 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa(unsigned int i, char *base)
{
	int		count;

	count = 0;
	if (i < 16)
	{
		ft_putchar(base[i]);
		count++;
	}
	else
	{
		count += ft_puthexa(i / 16, base);
		count += ft_puthexa(i % 16, base);
	}
	return (count);
}
