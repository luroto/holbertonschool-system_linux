#include "laps.h"
/**
 *race_state - Adds cars, laps, print results and frees all the cars
 *@id: Array of integers representing cars
 *@size: size of the array
 */
void race_state(int *id, size_t size)
{
	static car_t *head;
	static int clean_first;
	size_t i;

	if (size == 0)
	{
		if (head != NULL)
			free_all_cars(&head);
		clean_first = 1;
	}
	if (head != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (add_laps(head, id[i]) == 0)
				add_car(&head, id[i]);
		}
		printing_cars(head);
	}
	if (head == NULL && clean_first == 0)
	{
		head = NULL;
		for (i = 0; i < size; i++)
		{
			add_car(&head, id[i]);
		}
		clean_first = 1;
		printing_cars(head);
	}
}
/**
 *free_all_cars - Free all allocated memory
 *@head: The entire structure
 *Return: It's a void function
 */
void free_all_cars(car_t **head)
{
	car_t *aux;

	while ((*head) != NULL)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
	head = NULL;
}
/**
 *add_car - Adds a new car
 *@h: Pointer to the entire cars structure
 *@id: ID of the integer to be added
 *Return: The new node or NULL if it fails
 */
car_t *add_car(car_t **h, int id)
{
	car_t *nuevonodo, *aux;

	nuevonodo = malloc(sizeof(car_t));
	if (nuevonodo == NULL)
		return (NULL);
	nuevonodo->car_id = id;
	nuevonodo->laps = 0;
	printf("Car %d joined the race\n", id);
	if (*h == NULL)
	{
		nuevonodo->next = NULL;
		*h = nuevonodo;
		return (nuevonodo);
	}
	if ((*h)->car_id > id)
	{
		nuevonodo->next = *h;
		*h = nuevonodo;
		return (nuevonodo);
	}
	aux = *h;
	while (aux->next != NULL)
	{
		if (aux->next->car_id > nuevonodo->car_id)
		{
			nuevonodo->next = aux->next;
			aux->next = nuevonodo;
			return (nuevonodo);
		}
		aux = aux->next;
	}
	aux->next = nuevonodo;
	nuevonodo->next = NULL;
	return (nuevonodo);
}
/**
 *add_laps - Add a lap for the car in the argument
 *@h: Pointer to the first car in the structure
 *@car_id: Id of the car for adding the lap
 *Return: 1 if sucessful, otherwise 0
 */
int add_laps(car_t *h, int car_id)
{
	while (h != NULL)
	{
		if (h->car_id == car_id)
		{
			h->laps++;
			return (1);
		}
		h = h->next;
	}
	return (0);
}
/**
 *printing_cars - Prints the state of the race
 *@h: Pointer to the first car
 *Return: It's a void function
 */
void printing_cars(car_t *h)
{
	printf("Race state:\n");
	while (h != NULL)
	{
		printf("Car %d [%d laps]\n", h->car_id, h->laps);
		h = h->next;
	}
}
