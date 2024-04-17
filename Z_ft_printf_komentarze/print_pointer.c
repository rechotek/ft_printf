/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:12 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/18 16:22:35 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
// #include "print_string.c"
// #include "ft_putstr_fd.c"
// #include "ft_strlen.c"
// #include "ft_calloc.c"
// #include "print_char.c"

static char	*create_hex(unsigned long value, int *strlen)
{
	int				x;
	unsigned long	tempvalue;
	char			*str;

	x = 0;
	tempvalue = value;
	while (tempvalue != 0)
	{
		tempvalue = tempvalue / 16;
		x++;
	}
	str = ft_calloc(x + 1, sizeof(char));
	*strlen = x - 1;
	return (str);
}

int	print_pointer(unsigned long value, int asc)
{
	unsigned long	tempvalue;
	char			*printout;
	int				x;
	int				*xptr;

	xptr = &x;
	tempvalue = value;
	printout = create_hex(value, xptr);
	if (printout == NULL)
		return (0);
	while (tempvalue != 0 && x-- >= 0)
	{
		if ((tempvalue % 16 < 10))
			printout[x + 1] = (tempvalue % 16) + 48;
		else
			printout[x + 1] = (tempvalue % 16) + asc;
		tempvalue = tempvalue / 16;
	}
	x = ft_strlen(printout);
	x = x + print_string("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		x += print_char('0');
	return (x);
}

// int main() {
//     unsigned long value = 12;
//     int asc = 87;

//     //int result = print_pointer(value, asc);
// 	printf("; Dlugosc \"%lu\": %d\n", value, print_pointer(value, asc));
//     return 0;
// }