/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:53:47 by lwang             #+#    #+#             */
/*   Updated: 2017/07/31 10:53:49 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void swap(struct s_art **arts1, struct s_art **arts2){
	struct s_art *tmp;
	tmp = *arts1;
	*arts1 = *arts2;
	*arts2 = tmp;
}

void quicksort(struct s_art **arts, int n)
{
	if (n < 2)
		return;
	int pivot = n - 1;
	int i = -1;
	for (int j = 0; j < n; j++){
		if (strcmp(arts[j]->name, arts[pivot]->name) < 0){
			i++;
			swap(&arts[i], &arts[j]);
		}
	}
	swap(&arts[i + 1], &arts[pivot]);
	quicksort(&arts[0], i + 1);
	quicksort(&arts[i + 2], n - i - 2);
}

void sortArts(struct s_art **arts)
{
	int n = 0;
	while (arts[n])
		n++;
	printf("total arts in array is %d\n", n);
	quicksort(arts, n);
	for (int i = 0; i < n; i++)
        printf("%d: %s \n", i, arts[i]->name);
}