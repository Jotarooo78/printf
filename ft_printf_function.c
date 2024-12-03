/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:13:22 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/03 18:23:36 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr_base(long n, char *base, int baselen)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base, baselen);
	count += ft_putchar(base[n % baselen]);
	return (count);
}

int	ft_unsigned_putnbr_base(unsigned long n, char *base, int baselen)
{
	size_t	count;

	count = 0;
	if (n >= baselen)
		count += ft_unsigned_putnbr_base(n / baselen, base, baselen);
	count += ft_putchar(base[n % baselen]);
	return (count);
}
int	ft_unsigned_putnbr(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr(n / 10);
	count += ft_putchar(n % 10 + 48);
	return (count);
}

int	check_argument(unsigned long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_unsigned_putnbr_base(n, "0123456789abcdef", 16);
	return (count);
}
