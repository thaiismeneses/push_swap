/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:12:04 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/07 11:21:36 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printstr(const char *str);
int		ft_printchar(char c);
int		ft_printnbr(int n);
int		ft_checker(va_list args, int i, const char specifier);
char	*ft_strchr(const char *s, int c);
int		ft_printud(unsigned int n);
int		ft_printhexa(unsigned int n, const char specifier);
int		ft_printpointer(unsigned long long pointer);
#endif
