/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:15:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 10:43:59 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

char	*ft_itoa(int n)
{
    int len;
    int negative;
    int tmp;
    
    len = 0;
    negative = 0;
    tmp = n;
    if (n == 0)
    {
        return("0");
    }
    if (n < 0)
    {
        negative = 1;
        tmp = -n;
        len++;
    }
    while(tmp != 0)
    {
        tmp = tmp / 10;
        len++;
    }
    char *str = (char *)malloc(len + 1);
    
    if (str == NULL)
    {
        return (NULL);
    }
    str[len] = '\0';
    if (n < 0)
    {
        n = -n;
    }
    while(len--)
    {
        str[len] = (n % 10) + '0';
        n = n / 10;
    }
    if (negative)
    {
        str[0] = '-';
    }
    return (str);
}

