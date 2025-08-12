#include <stdlib.h>
#include <stdio.h>
#include "../include/database.h"
#include "../include/reader.h"

static int getID(Database d, int id);

void destroyDatabase(Database d) {
    clearDatabase(d);
    destroy(d);
}

void clearDatabase(Database d) {
    while (d->length > 0) {
        Item *current = deleteAt(d, d->length - 1);
        free(current->name);
        free(current);
    }
} 

void addItem(Database d) {
    int id = get_int("Enter item ID: ");
    if (getID(d, id) != -1) {
        printf("Item already exists.\n");
        return;
    }

    Item *new = malloc(sizeof(Item));
    if (new == NULL) {
        printf("Error: could not add item.\n");
        return;
    }

    new->id = id;
    new->name = get_string("Enter item name: ");
    new->quantity = get_int("Enter item quantity: ");

    int i = -1;
    for (; i < length(d) - 1 && item(d, i + 1)->id < id; i++);
    if (i == length(d) - 1) {
        append(d, new);
    } else {
        insertAt(d, i + 1, new);
    }
}

void searchItem(const Database d) {    
    int id = get_int("Enter item ID: ");
    int i = getID(d, id);

    if (i != -1) {
        Item *found = item(d, i);
        printf("Item name: %s\n", found->name);
        printf("Item quantity: %d\n", found->quantity);
    } else {
        printf("Item not found.\n");
    }
}

void updateItem(Database d) {
    int id = get_int("Enter item ID: ");
    int i = getID(d, id);

    if (i != -1) {
        item(d, i)->quantity += get_int("Enter change in item quantity: ");
    } else {
        printf("Item not found.\n");
    }
}

void deleteItem(Database d) {
    int id = get_int("Enter item ID: ");
    int i = getID(d, id);

    if (i != -1) {
        Item *current = deleteAt(d, i);
        free(current->name);
        free(current);
    } else {
        printf("Item not found.\n");
    }
}

void display(const Database d) {
    printf("   ID            Name   Quantity\n");
    for (int i = 0; i < length(d); i++) {
        Item *current = item(d, i);
        printf("%5d%16s%11d\n", current->id, current->name, current->quantity);
    }
}

static int getID(Database d, int id) {
    int low = 0, high = length(d) - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int current = item(d, mid)->id;

        if (current == id) {
            return mid;
        } else if (current < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
