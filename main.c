#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

int main()
{
    struct client *c;
    struct client *nc;
    struct client *nnc;

    char *name_p0 = "Ethan";
    char *name_p1 = "Alice";
    char *name_p2 = "Jeffery";

    unsigned int id_0 = 1000;
    unsigned int id_1 = 2000;
    unsigned int id_2 = 3000;

    c = new_client(id_0, name_p0, NULL);
    nc = new_client(id_1, name_p1, NULL);
    nnc = new_client(id_2, name_p2, NULL);

    // struct client *copy_c = *c;
    nc->next = nnc;
    c->next = nc;

    print_list(c);

    id_0 = 4000;
    id_1 = 5000;
    id_2 = 6000;

    free(c);
    free(nc);
    free(nnc);
    return 0;
}