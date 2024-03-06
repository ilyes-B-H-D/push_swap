/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:49:21 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 20:19:31 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	return (ft_isalpha(i) || ft_isdigit(i));
}
/*=====================testing=======
#include <stdio.h>

int main()
{
	if (ft_isalnum('a') == 1)
		printf("a is alpha numerique\n");
	if (ft_isalnum(5) == 1)
		printf("5 is alpha numerique\n");
	if (ft_isalnum('#') == 0)
		printf("# is not an alpha numerique\n");
}
====================================*/