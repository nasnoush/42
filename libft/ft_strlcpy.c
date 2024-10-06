/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:23:03 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/04 15:07:52 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (src == NULL)
    {
        return (0);
    }
    if (dstsize == 0)
    {
        return(ft_strlen(src));
    
    }
    if (dstsize > 0)
    {
        dst[i] = '\0';
    }
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++; 
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}