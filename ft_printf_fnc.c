/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fnc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:52:35 by nait-ali          #+#    #+#             */
/*   Updated: 2023/01/20 20:27:19 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long	nombre;
	int		count;

	count = 0;
	nombre = n;
	if (nombre < 0)
	{
		count += ft_putchar('-');
		nombre *= -1;
	}
	if (nombre > 9)
	{
		count += ft_putnbr(nombre / 10);
		count += ft_putnbr(nombre % 10);
	}
	else
		count += ft_putchar(nombre + 48);
	return (count);
}

int	ft_putnbrnonsign(unsigned	int nombre)
{
	int	count;

	count = 0;
	if (nombre > 9)
	{
		count += ft_putnbr(nombre / 10);
		count += ft_putnbr(nombre % 10);
	}
	else
		count += ft_putchar(nombre + 48);
	return (count);
}

int	ft_puthexa(unsigned	int nombre, char x)
{
	int		count;
	char	*hexa;

	count = 0;
	if (x == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nombre >= 16)
	{
		count += ft_puthexa(nombre / 16, x);
		count += ft_puthexa(nombre % 16, x);
	}
	else
		count += ft_putchar(hexa[nombre]);
	return (count);
}
