/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:08:57 by nait-ali          #+#    #+#             */
/*   Updated: 2023/01/20 20:58:35 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long nombre)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (nombre >= 16)
	{
		count += ft_putpointer(nombre / 16);
		count += ft_putpointer(nombre % 16);
	}
	else
		count += ft_putchar(hexa[nombre]);
	return (count);
}

int	ft_write(va_list vlist, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar(c);
	else if (c == 'c')
		count += ft_putchar((int)va_arg(vlist, int));
	else if (c == 's')
		count += ft_putstr((char *)va_arg(vlist, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr((int)va_arg(vlist, int));
	else if (c == 'X' || c == 'x')
		count += ft_puthexa((unsigned int)va_arg(vlist, unsigned int), c);//3lach unsigned int
	else if (c == 'u')
		count += ft_putnbrnonsign((unsigned int) va_arg(vlist, unsigned int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putpointer((unsigned long) va_arg(vlist, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	vlist;

	va_start(vlist, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				count += ft_write(vlist, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(vlist);
	return (count);
}
int main()
{
	int *p;

	

	int a;
	
	ft_printf("%%%");





	
}