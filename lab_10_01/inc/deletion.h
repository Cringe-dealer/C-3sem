#ifndef DELETION_H
#define DELETION_H

#include "errors.h"

void list_free(node_t *head);

void *pop_front(node_t **head);

void *pop_back(node_t **head);

#endif // DELETION_H
