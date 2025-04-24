/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:01:09 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/23 13:09:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"
# define HEX_LEN	16
# define DEC_LEN	10
# define INT_MIN_VAL	-2147483648

typedef struct s_flags
{
	unsigned char	minus;
	unsigned char	plus;
	unsigned char	space;
	unsigned char	hash;
	unsigned char	zero;
	unsigned char	dot;
	unsigned char	star;
	size_t			width;
}	t_flags;

int	ft_printf(const char *s, ...);
int	ft_putchar_cnt(char c);
int	ft_putstr_cnt(char *s);
int	ft_putptr_cnt(void *s);
int	ft_putnbr_cnt(int n);
int	ft_putunbr_cnt(unsigned int n);
int	ft_puthex_cnt(unsigned int nbr, char c);
int	ft_putnbr_base(unsigned long long nbr, char *base, size_t len);

#endif
