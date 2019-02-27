/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:57:50 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/17 14:38:06 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static t_string	*handle_arg(const char **format, va_list *ap)
{
	t_conv		conversion;
	t_string	*ret;

	ft_bzero(&conversion, sizeof(t_conv));
	parse_flags(format, &conversion);
	parse_width(format, ap, &conversion);
	parse_precision(format, ap, &conversion);
	parse_length(format, &conversion);
	ret = NULL;
	if (!parse_specifier(format, &conversion))
		ret = conversion.handler(&conversion, ap);
	return (ret);
}

static int		ft_printf_list(t_target_info *info,
		const char **format, va_list *ap)
{
	const char	*spec;
	t_string	*string;

	if (!format || !(*format))
		return (-1);
	spec = *format;
	while ((spec = ft_strchr(*format, '%')))
	{
		print_to_target(info, *format, (size_t)(spec - *format));
		(*format) = spec + 1;
		if (!(string = handle_arg(format, ap)))
			return (-1);
		print_to_target(info, string->buff, string->size);
		string_destroy(string);
	}
	print_to_target(info, *format, -1);
	return (info->index);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				ret;
	t_target_info	info;

	ft_bzero(&info, sizeof(info));
	va_start(ap, format);
	ret = ft_printf_list(&info, &format, &ap);
	va_end(ap);
	return (ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list			ap;
	int				ret;
	t_target_info	info;

	ft_bzero(&info, sizeof(info));
	info.type = TYPE_FILE;
	info.target.fd = fd;
	va_start(ap, format);
	ret = ft_printf_list(&info, &format, &ap);
	va_end(ap);
	return (ret);
}

int				ft_snprintf(char *const buff, size_t size,
					const char *format, ...)
{
	va_list			ap;
	int				ret;
	t_target_info	info;

	ft_bzero(&info, sizeof(info));
	info.type = TYPE_BUFFER;
	info.target.buff = buff;
	info.max_size = size - 1;
	va_start(ap, format);
	ret = ft_printf_list(&info, &format, &ap);
	if (buff && info.index < size)
		buff[info.index] = '\0';
	va_end(ap);
	return (ret);
}
