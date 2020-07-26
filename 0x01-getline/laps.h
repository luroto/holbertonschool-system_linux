#ifndef _LAPS_H
#define _LAPS_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 *struct car_s - single linked list for cars info
 *@car_id: name of the entry
 *@laps: type and mode for the entry (permissions)
 *@next: Pointer to the next node
 */
typedef struct car_s
{
	int car_id;
	int laps;
	struct car_s *next;
} car_t;
void race_state(int *id, size_t size);
int add_laps(car_t *h, int car_id);
car_t *add_car(car_t **h, int id);
void free_all_cars(car_t **head);
void printing_cars(car_t *h);
#endif
