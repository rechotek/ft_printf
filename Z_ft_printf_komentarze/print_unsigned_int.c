/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:45:46 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/14 19:05:58 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ft_putchar_fd.c"

static void	printout(unsigned int	nb)
{
	if (nb > 9)
		print_unsigned_int(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	print_unsigned_int(unsigned int	nb)
{
	unsigned int	x;

	printout(nb);
	x = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		x++;
	}
	return (x);
}

int main(void)
{
    unsigned int	nb = 5435;
    printf("; Dlugosc stringu \"%u\": %d\n", nb, print_unsigned_int(nb));
    return (0);
}