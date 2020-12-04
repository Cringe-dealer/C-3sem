#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"

song_t *song_create(char *group, char *title)
{
    song_t *song = malloc(sizeof(song_t));

    if (song)
    {
        song->group = strdup(group);
        if (song->group)
        {
            song->title = strdup(title);
            if (!song->title)
            {
                free(song->group);
                free(song);
                song = NULL;
            }
        }
        else
        {
            free(song);
            song = NULL;
        }
    }

    return song;
}

node_t *node_create(void *value)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
    {
        return NULL;
    }

    node->data = value;
    node->next = NULL;
    return node;
}

node_t *list_add_end(node_t *head, node_t *node)
{
    if (!head)
        return node;

    node_t *cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = node;
    return head;
}
