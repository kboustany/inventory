#include <stdlib.h>
#include <stdio.h>
#include "../include/arrayList.h"

#define INITIAL_CAPACITY 10

static void terminate(const char *);
static void resize(ArrayList, int);

ArrayList create(void) {
    ArrayList l = malloc(sizeof(struct ArrayList_type));
    if (l == NULL) {
        terminate("Error: could not create list.");
    }

    l->contents = malloc(INITIAL_CAPACITY * sizeof(Item *));
    if (l->contents == NULL) {
        free(l);
        terminate("Error: could not create list.");
    }

    l->length = 0;
    l->capacity = INITIAL_CAPACITY;

    return l;
}

void destroy(ArrayList l) {
    clear(l);
    free(l->contents);
    free(l);
}

void clear(ArrayList l) {
    while (l->length > 0) {
        free(deleteAt(l, l->length - 1));
    }
} 

int length(ArrayList l) {
    return l->length;
}

Item *item(ArrayList l, int i) {
    if (i < 0 || i >= l->length) {
        terminate("Error: index is out of bounds.");
    }

    return l->contents[i];
}

void append(ArrayList l, Item *item) {
    if (l->length == l->capacity) {
        resize(l, 2 * l->capacity);
    }

    l->contents[l->length++] = item;
}

void assignAt(ArrayList l, int i , Item *item) {
    if (i < 0 || i >= l->length) {
        terminate("Error: index is out of bounds.");
    }

    free(l->contents[i]);
    l->contents[i] = item;
}

void insertAt(ArrayList l, int i, Item *item) {
    if (i < 0 || i >= l->length) {
        terminate("Error: index is out of bounds.");
    }

    if (l->length == l->capacity) {
        resize(l, 2 * l->capacity);
    }

    for (int j = l->length; j > i; j--) {
        l->contents[j] = l->contents[j-1];
    }
    l->contents[i] = item;
    l->length++;
}

Item *deleteAt(ArrayList l, int i) {
    if (i < 0 || i >= l->length) {
        terminate("Error: index is out of bounds.");
    }

    Item *deleted = l->contents[i];
    for (int j = i; j < l->length - 1; j++) {
        l->contents[j] = l->contents[j+1];
    }
    l->length--;

    if (l->length > 0 && (l->length < l->capacity / 4)) {
        resize(l, l->capacity / 2);
    }

    return deleted;
}

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static void resize(ArrayList l, int new_capacity) {
    Item **temp = realloc(l->contents, new_capacity * sizeof(Item *));
    if (temp == NULL) {
        terminate("Error: could not resize list.");
    }
    
    l->contents = temp;
    l->capacity = new_capacity;
}