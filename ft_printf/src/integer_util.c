/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:43:27 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/12 20:12:36 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*g_dec_base = "0123456789";
char	*g_hex_base = "0123456789abcdef";
char	*g_hex_base_up = "0123456789ABCDEF";
char	*g_oct_base = "01234567";
char	*g_bin_base = "01";

char	*s_base_conv(const t_conv *conv,
			intmax_t n, const char *base, size_t min_dig)
{
	ssize_t		base_size;
	size_t		index;
	char		digit;
	char		*string;

	base_size = ft_strlen(base);
	string = ft_strnew(0);
	index = 0;
	while (string && (index < min_dig || ABS(n) > 0 || ABS(n / base_size) > 0))
	{
		if (base_size == 10 && conv->flags.thousand_grouping
			&& index > 0 && !(index % 3)
			&& !(string = string_add_char(',', string)))
			return (NULL);
		digit = base[ABS(n - (n / base_size) * base_size)];
		string = string_add_char(digit, string);
		n = n / base_size;
		index++;
	}
	return (string);
}

char	*u_base_conv(const t_conv *conv,
			uintmax_t n, const char *base, size_t min_dig)
{
	size_t		base_size;
	size_t		index;
	char		digit;
	char		*string;

	base_size = ft_strlen(base);
	string = ft_strnew(0);
	index = 0;
	while (string && (index < min_dig || n > 0 || n / base_size > 0))
	{
		if (base_size == 10 && conv->flags.thousand_grouping
			&& index > 0 && !(index % 3)
			&& !(string = string_add_char(',', string)))
			return (NULL);
		digit = base[n - (n / base_size) * base_size];
		string = string_add_char(digit, string);
		n = n / base_size;
		index++;
	}
	return (string);
}
