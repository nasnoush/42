/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:23:03 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/04 16:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	 size_t dst_len;
     size_t src_len;
     size_t i;

     i = 0;

     dst_len = ft_strlen(dst);
     src_len = ft_strlen(src);
     
     if (size <= dst_len)
     {
        return (src_len + size);
     }
     
     while (src[i] && (dst_len + i + 1) < size)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}