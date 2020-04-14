/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plusflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:06:24 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 09:13:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plusflag(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	++(*sfmt);
	fmt->plus = 1;
	return (NULL);
}
