/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:04:52 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/18 16:24:43 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "/nfs/homes/mrechuli/CommonCore/libft/libft.h"

// typedef struct s_list
// {
// 	void			*content; // wskaznk do zawartosci
// 	struct s_list	*next; // wskaznik do nastepnego elementu
// }	t_list;

int	ft_printf(const char *str, ...);
int print_pointer(unsigned long value, int asc);
int print_string(char *s);
int print_int(int n);
int	print_char(char c);
int	print_hex(unsigned int value, int asc);
int	print_unsigned_int(unsigned int	nb);

#endif