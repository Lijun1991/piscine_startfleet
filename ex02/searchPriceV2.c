/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:35:18 by lwang             #+#    #+#             */
/*   Updated: 2017/07/31 20:35:20 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
	int low = 1;
	int up = n;
	int mid = 0;
	while (strcmp(arts[mid]->name, name) != 0)
	{
		mid = low + (up - low) / 2;
		if (strcmp(arts[mid]->name, name) < 0){
			low = mid + 1;
		}
		if (strcmp(arts[mid]->name, name) > 0){
			up = mid - 1;
		}
	}
	return(arts[mid]->price);
}