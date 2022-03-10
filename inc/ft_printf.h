/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:25:08 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/14 18:25:10 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct conv_spec
{
	va_list	args;
	int		percent;
	int		htag;
	int		sp;
	int		zero;
	int		min;
	int		plus;
	int		wdt;
	int		prec;
	int		s_prec;
	int		exp_zero;
	int		index_f;
	int		negative;
	int		p_b;
	int		error;
}	t_conv_spec;

int		ft_printf(const char *format, ...);
void	ft_initialize(t_conv_spec *set);
int		ft_printf_general(const char *format, t_conv_spec *set);
int		ft_conversion_check(const char *format, t_conv_spec *set);

int		ft_printf_char(t_conv_spec *set);
int		ft_putstr(t_conv_spec *set);
void	ft_put_d(t_conv_spec *set);
void	ft_put_u(t_conv_spec *set);
void	ft_put_hx(t_conv_spec *set, char a);
void	ft_put_ad(t_conv_spec *set);

void	ft_printf_sd(t_conv_spec *set, long int nb);
void	ft_printf_hx(t_conv_spec *set, unsigned long nb, char a);

int		ft_printf_spaces(t_conv_spec *set, int q);
int		ft_printf_zeros(t_conv_spec *set, int q);
int		ft_printf_sign(t_conv_spec *set);

int		ft_len_d(int nb);
int		ft_len_ud(unsigned int nb);
int		ft_len_hx(unsigned long nb);

int		ft_max(int a, int b);

#endif
