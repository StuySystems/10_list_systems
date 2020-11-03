#ifndef STRUCTS_H
#define STRUCTS_H

struct client
{
    unsigned int id;
    char name[256];

    struct client *next;
};

struct client *new_client(unsigned int id, char *name, struct client *next);
void print_struct(struct client *ob);
void change_id(struct client *cl, unsigned int id);
void print_list(struct client *cl);
struct client *insert_front(struct client *cl, char *name, int id);
struct client *free_list(struct client *cl);
struct client *remove_node(struct client *front, int id);

#endif
