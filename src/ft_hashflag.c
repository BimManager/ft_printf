/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:03:35 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 12:58:56 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hashflag(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	++(*sfmt);
	fmt->hash = 1;
	return (NULL);
}
