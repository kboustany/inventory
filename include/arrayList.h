#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#ifndef CUSTOM_ITEM

typedef int Item;

#endif

struct ArrayList_type {
    Item **contents;
    int length;
    int capacity;
};

typedef struct ArrayList_type *ArrayList;

ArrayList create(void);
void destroy(ArrayList);
void clear(ArrayList);
int length(ArrayList);
Item *item(ArrayList, int);
void append(ArrayList, Item *);
void assignAt(ArrayList, int, Item *);
void insertAt(ArrayList, int, Item *);
Item *deleteAt(ArrayList, int);

#endif