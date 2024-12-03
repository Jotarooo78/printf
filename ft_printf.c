/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:34:48 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/03 18:25:13 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_percent(const char *str, va_list(list), size_t i)
{
	if (str[i] == 'd')
		return (ft_putnbr_base(va_arg(list, int), "0123456789", 10));
	else if (str[i] == 'u')
		return (ft_unsigned_putnbr(va_arg(list, unsigned int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(list, const char *)));
	else if (str[i] == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (str[i] == 'i')
		return (ft_putnbr_base(va_arg(list, int), "0123456789", 10));
	else if (str[i] == 'p')
		return (check_argument(va_arg(list, unsigned long)));
	else if (str[i] == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef", 16));
	else if (str[i] == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF", 16));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%') + ft_putchar(str[i])); 
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	i;
	size_t	len;

	va_start(list, str);
	i = 0;
	len = 0;
	if (str == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += which_percent(str, list, i);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}

// int	main(void)
// {
// 	printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	printf("\n");
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// }

// int	main(void)
// {
// int	test;

// test = 42;
// printf("Printf a imprime %d caracteres\n\n", printf("Test adress: %p\n", &test));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Test adress: %p\n", &test));
// printf("Printf a imprime %d caracteres\n\n", printf("C : %c\n", 'A'));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("C : %c\n",'A'));
// printf("Printf a imprime %d caracteres\n\n", printf("String: %s\n", "test"));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("String: %s\n", NULL));
// printf("Printf a imprime %d caracteres\n\n", printf("Decimal: %d\n", -21474836));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Decimal: %d\n", -21474836));
// printf("Printf a imprime %d caracteres\n\n", printf("%i\n", -2365));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("%i\n", -2365));
// printf("Printf a imprime %d caracteres\n\n", printf("Unsigned: %u\n", 4294967295));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Unsigned: %u\n", 4294967295));
// printf("Printf a imprime %d caracteres\n\n", printf("Percent: %%\n"));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Percent: %%\n"));
// printf("Printf a imprime %d caracteres\n\n", printf("Hexalow: %x\n", -215487854));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Hexalow: %x\n", -215487854));
// printf("Printf a imprime %d caracteres\n\n", printf("Hexaup: %X\n", -215487854));
// printf("Ft_printf a imprime %d caracteres\n\n", ft_printf("Hexaup: %X\n", -215487854));
// printf(0);
// ft_printf(0);
// printf("%cpercent %%\nc %c\ns %s\nd %d\ni %i\nu %u\np %p\nX %X\nx %x\n (printf)\n\n\n", '\n', 'c', "test", 20, 25, 235648, "test2", 123456, 123456);
// ft_printf("%cpercent %%\nc %c\ns %s\nd %d\ni %i\nu %u\np %p\nX %X\nx %x\n (ft_printf)\n\n\n", '\n', 'c', "test", 20, 25, 235648, "test2", 123456, 123456);
// return (0);
// }