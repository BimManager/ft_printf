/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:02:44 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 14:14:27 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <time.h>

# include "libft.h"

# define PSEUDO_NULL	-1
# define NSIN			8

# define SIGN_SIZE		1
# define EXP_SIZE		15
# define SIG_SIZE		63
# define EXP_BIAS		16383
# define EXP_ALL_ONES	32767
# define EXP_MAX		16383
# define EXP_MIN		-16382

typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;

typedef struct	s_format
{
	char		align : 1;
	char		plus : 1;
	char		space : 1;
	char		zero : 1;
	char		hash : 1;
	char		done : 1;
	char		neg : 1;
	char		null : 1;
	int			width;
	int			prec;
	int			length;
}				t_format;

typedef char	*(*t_pfmtfn)(va_list pa, t_format *data, const char **sfmt);

typedef struct	s_ext80bits
{
	t_uint64	man : 64;
	t_uint32	exp : 15;
	t_uint32	sign : 1;
}				t_ext80bits;

typedef union	u_ext80
{
	long double	value;
	t_ext80bits	bits;
}				t_ext80;

int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_printf(const char *fmt, ...);

int				ft_xprintf(int fd, const char *fmt, va_list pa);

int				ft_printsf(int fd, const char **sfmt, va_list pa);

char			*ft_strrev(char *str);
t_format		*ft_formatnew(void);

long double		ft_getldb(va_list pa, t_format *fmt);
long double		ft_powl(long double x, long double y);
long double		ft_round(long double x, int prc);
char			*ft_feg(va_list pa, t_format *fmt, const char **sfmt,
						char *(*pfn)(const void *pnb, size_t prec));

t_stack			*ft_decrad(const void *pnb, size_t size,
							const char *digits, size_t rad);

char			*ft_radstr(const void *pnb, size_t size,
							const char *digits, size_t rad);

char			*ft_nbitstr(const void *pv, size_t nbits);
char			*ft_decstr(const void *pnb, size_t size);
char			*ft_octstr(const void *pnb, size_t size);
char			*ft_hexstr(const void *pnb, size_t size);
char			*ft_ldbstr(const void *pnb, size_t prc);
char			*ft_expstr(const void *pnb, size_t prc);

char			*ft_genstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_bstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_cstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_dstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_fstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_istr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_xstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_cxstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_sstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_ustr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_custr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_pstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_ostr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_estr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_cestr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_gstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_cgstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_rstr(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_kstr(va_list pa, t_format *fmt, const char **sfmt);

char			*ft_percent(va_list pa, t_format *fmt, const char **sfmt);

char			*ft_alignflag(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_plusflag(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_spaceflag(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_zeroflag(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_hashflag(va_list pa, t_format *fmt, const char **sfmt);

char			*ft_asterisk(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_width(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_prec(va_list pa, t_format *fmt, const char **sfmt);

char			*ft_hhlength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_hlength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_llength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_lllength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_cllength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_tlength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_jlength(va_list pa, t_format *fmt, const char **sfmt);
char			*ft_zlength(va_list pa, t_format *fmt, const char **sfmt);

size_t			ft_cvtarg(va_list pa, t_format *fmt);
char			*ft_fixprec_dioux(char *snb, t_format *fmt);

char			*ft_fixsign(char *s, t_format *fmt);
char			*ft_fixhash_boxp(char *snb, t_format *fmt, char *hash);
char			*ft_fixwidth(char *s, t_format *fmt);
char			*ft_mvsign(char	*snb, t_format *fmt);
char			*ft_mvhash(char *snb, t_format *fmt, char hash);

int				ft_nullguard(const void *pv, char **msg);
char			*ft_infnan(long double ldb);
int				ft_fmtnb(const char **sfmt);

#endif
