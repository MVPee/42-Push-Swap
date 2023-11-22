/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:11 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/22 15:27:06 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
            split[i] = NULL;
			i++;
		}
		free(split);
        split = NULL;
	}
}
