/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:53:42 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/08 10:26:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_istr(va_list pa, t_format *fmt, const char **sfmt)
{
	return (ft_dstr(pa, fmt, sfmt));
}
