/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:13:50 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/22 13:55:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_flags
{
	unsigned char	minus;
	unsigned char	plus;
	unsigned char	space;
	unsigned char	hash;
	unsigned char	zero;
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