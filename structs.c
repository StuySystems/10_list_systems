#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

struct client *new_client(unsigned int id, char *name, struct client *next)
{
    struct client *nc;
    nc = malloc(sizeof(struct client));
    nc->id = id;
    strncpy(nc->name, name, sizeof(nc->name) - 1);

    nc->next = next;

    return nc;
}

void print_struct(struct client *cl)
{
    printf("Client ID %d assigned to patient %s\n", cl->id, cl->name);
    return;
}

void change_id(struct client *cl, unsigned int id)
{
    cl->id = id;
    return;
}

void print_list(struct client *cl)
{
    while (*cl != NULL)
    {
        print_struct(cl);
        cl = cl->next;
    }
}

struct client *insert_front(struct client *first, char *name, int id)
{
    struct client *new_cl;

    new_cl = new_client(id, name, first);

    return new_cl;
}
struct client *free_list(struct client *cl)
{
    struct client *first;
    struct client *placeholder;

    first = cl;

    while (*cl != NULL)
    {
        placeholder = cl->next;
        free(cl);
        cl = placeholder;
    }

    return first;
}
struct client *remove_node(struct client *front, int id)
{
    struct client *new_front;
    new_front = front;

    while (*front != NULL)
    {
        if (front->id == id)
        {
            new_front = front->next;
            free(front);
            break;
        }
        else
        {
            front = front->next;
        }
    }

    return new_front;
}