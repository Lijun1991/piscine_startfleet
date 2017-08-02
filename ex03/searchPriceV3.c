/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 22:24:14 by lwang             #+#    #+#             */
/*   Updated: 2017/07/31 22:24:16 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t hash(char *input)
{
	size_t index;
	index = (size_t)((int)strlen(input) % SIZE);////////////////////////big bug 2!!!
	// printf("hash %zu\n", index);
	return (index);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->items = (struct s_item **)malloc(sizeof(struct s_item *) * (capacity + 1));
	int i = 0;
	while (i < capacity)
	{
		dict->items[i] = (struct s_item *)malloc(sizeof(struct s_item));
		dict->items[i]->key = NULL;
		dict->items[i]->value = NULL;
		dict->items[i]->next = NULL;
		i++;
	}
	dict->capacity = capacity;
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) //add one element in the dictionnary, if FAIL return 0, otherwise 1
{
	size_t index = hash(key);

	struct s_item *new = (struct s_item *)malloc(sizeof(struct s_item));
	new->next = NULL;

	if (!dict->items[index]->value)
	{
		dict->items[index]->key = key;
		dict->items[index]->value = value;
	}
	else
	{
		struct s_item *tmp = dict->items[index];
		while (tmp->next)
			 tmp = tmp->next;
		new->key = key;
		new->value = value;
		tmp->next = new;///////////////////////////////big problem!!!!
	}
	if (!new)
		return (0);
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) //find one element in the dictionnary, if not found, return NULL
{
	size_t index = hash(key);

	struct s_item *tmp = dict->items[index];
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *result = dictSearch(dict, name);
	if (result)
		return (result->price);
	else
		return (0);
}

