/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:49:25 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/14 18:43:58 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "ft_putchar_fd.c"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// int main(void)
// {
//     char c = '*';
//     printf("; Dlugosc stringu \"%c\": %d\n", c, print_char(c));
//     return (0);
// }