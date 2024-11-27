/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/27 11:25:19 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
