/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:26:37 by lwang             #+#    #+#             */
/*   Updated: 2017/07/31 09:26:38 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

 int searchPrice(struct s_art **arts, char *name){
 	int i = 0;
 	while (arts[i])
 	{
 		if (strcmp(arts[i]->name, name) == 0)
 			return (arts[i]->price);
 		i++;
 	}
 	return (0);
 }