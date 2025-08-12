#ifndef DATABASE_H
#define DATABASE_H

#define CUSTOM_ITEM

typedef struct {
    int id;
    char *name;
    int quantity;
} Item;

#include "./arrayList.h"

typedef ArrayList Database;

// Functions inherited from ArrayList.
/******************************************************************************
 * Database create(void);                                                     *
 * void destroy(Database);                                                    *
 ******************************************************************************/

void destroyDatabase(Database);
void clearDatabase(Database);
void addItem(Database);
void searchItem(const Database);
void updateItem(Database);
void deleteItem(Database);
void display(const Database);

#endif