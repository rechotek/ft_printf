/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:22:50 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:40 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_type(const har *in, void *arg)
{
	int	x;

	x = 0;
	if (*in == 'c')
		x += print_char((int)arg); // tu jest int poniewaz takie sa wymagania funkcji printf
	else if (*in == 's')
		x += print_string((char *)arg);
	else if (*in == 'p')
		x += print_pointer((unsigned long)arg, 87) // 87 bo wyswietlenie wartosci 16-tkowej malymi literami
	else if (*in == 'd')
		x += print_int((int)arg);
	else if (*in == 'i')
		x += print_int((int)arg);
	else if (*in == 'u')
		x += print_unsigned_int((unsigned int)arg);
	else if (*in == 'x')
		x += print_hex((unsigned int)arg, 87); // 87 bo wyswietlenie wartosci 16-tkowej malymi literami
	else if (*in == 'X')
		x += print_hex((unsigned int)arg, 55); // 55 bo wyswietlenie wartosci 16-tkowej duzymi literami
	return (x);
}

nt	ft_printf(const char *input, ...)
{
	va_list			args; // to jest deklaracja ze bedzie to lista argumentow
	unsigned int	x;

	x = 0;
	va_start(args, input); // inicjalizujemy ta liste przyjmujac args i input, czyli wprowadzony ciag znakow
	while (*input != '\0') // wykonujemy ta petle az do konca wprowadzoneo input, np. "Essa mordo ma %d znakow"
	{
		if (*input == '%') // sprawdzamy czy dany znak to %, bo po nim nastepuje deklaracja typu ("cspdiuxX")
		{
			input++;
			if (ft_strchr("cspdiuxX", *input)) // sprawdzam czy dana pozycja w input to jeden ze znakow "cspdiuxX"
				x += check_type(input, va_arg(args, void *)); // jesli tak to za pomoca funkcji check_type sprawdzam jaki to typ i wypisuje go; va_args to lista argumentow, ktora umozliwia mi dostep do kolejnych argumentow zapisanych w check_type
			else if (*input == '%')
				x += print_char('%');
		}
		else
			x = x + print_char(*input); // jesli mamy zwykle znaki w ciagu (nie te po %) to wypisujemy je za pomoca print_char
		input++;
	}
	va_end(args); // tak jak zainicjowalismy poczatek listy, tak powinnismy ja skonczyc
	return (x);
}

// int main() {
//     ft_printf("Hello, world!\n");
// 	ft_printf("The character %c is a char.\n", 'A');
// 	ft_printf("The string \"%s\" is a string.\n", "Hello");
// 	ft_printf("The address of x is %p.\n", (void *)&x);
//     ft_printf("The number %d is an integer.\n", 42);
//     ft_printf("The number %i is also an integer.\n", 42);
// 	ft_printf("The unsigned number %u is an unsigned integer.\n", 42);
//     ft_printf("The hexadecimal value of 255 is %x.\n", 255);
//     ft_printf("The uppercase hexadecimal value of 255 is %X.\n", 255);

//     return (0);
// }