/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:09:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 09:19:55 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zeroflag(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	++(*sfmt);
	fmt->zero = 1;
	return (NULL);
}
