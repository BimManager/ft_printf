# ft_printf Makefile

CC := gcc
AR := ar
CFLAGS := -Wall -Werror -Wextra -c -I./include
ARFLAGS := -q -c

SRCDIR := src
SRCS := $(addprefix $(SRCDIR)/, \
		ft_alignflag.c ft_asterisk.c ft_atoi.c \
		ft_bstr.c ft_bzero.c ft_cestr.c ft_cgstr.c \
		ft_cllength.c ft_cstr.c ft_custr.c ft_cvtarg.c \
		ft_cxstr.c ft_decrad.c ft_decstr.c ft_dprintf.c \
		ft_dstr.c ft_estr.c ft_expstr.c ft_feg.c ft_fixhash_boxp.c \
		ft_fixprec_dioux.c ft_fixsign.c ft_fixwidth.c ft_fmtnb.c \
		ft_formatnew.c ft_fstr.c ft_genstr.c ft_getldb.c ft_gstr.c \
		ft_hashflag.c ft_hexstr.c ft_hlength.c ft_infnan.c ft_isdigit.c \
		ft_isprint.c ft_istr.c ft_jlength.c ft_kstr.c ft_ldbstr.c \
		ft_llength.c ft_lstdel.c ft_lstnew.c ft_lstsize.c ft_memcpy.c \
		ft_memdel.c ft_memset.c ft_mvshash.c ft_nbitstr.c ft_nullguard.c \
		ft_octstr.c ft_ostr.c ft_percent.c ft_plusflag.c ft_powl.c \
		ft_prec.c ft_printf.c ft_printsf.c ft_pstr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_radstr.c ft_round.c ft_rstr.c ft_spaceflag.c \
		ft_sstr.c ft_stackdel.c ft_stacknew.c ft_stackpeek.c ft_stackpop.c \
		ft_stackpush.c ft_stacksize.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
		ft_strdup.c ft_strlcpy.c ft_strlen.c ft_strncpy.c ft_strrev.c \
		ft_strstr.c ft_strupcase.c ft_swap.c ft_tlength.c ft_ustr.c \
		ft_width.c ft_xprintf.c ft_xstr.c ft_zeroflag.c ft_zlength.c)

OBJS := $(patsubst $(SRCDIR)/%.c, %.o, $(SRCS))

NAME := libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) 
	$(AR) $(ARFLAGS) $@ $^	

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $^

.PNOHY : all clean fclean re

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all