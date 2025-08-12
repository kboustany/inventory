#include <stdlib.h>
#include <stdio.h>
#include "../include/reader.h"

#define INITIAL_LENGTH 10

static int resize(char **, int);

char get_char(const char *prompt) {
    char c;

    printf("%s", prompt);    
    scanf("%c", &c);
    getchar();

    return c;
}

float get_float(const char *prompt) {
    float x;
    
    printf("%s", prompt);
    scanf("%f", &x);
    getchar();

    return x;
}

int get_int(const char *prompt) {
    int n;
    
    printf("%s", prompt);
    scanf("%d", &n);
    getchar();

    return n;
}

char *get_string(const char *prompt) {
    int length = INITIAL_LENGTH, i = 0;
    char *s = malloc((length + 1) * sizeof(char)), ch;

    printf("%s", prompt);

    do {
        while ((ch = getchar()) == ' ');
        if (i > 0 && ch != '\n') {
            if (i == length) {
                length = resize(&s, 2 * length);
            }
            s[i++] = ' ';
        }
        while (ch != ' ' && ch != '\n') {
            if (i == length) {
                length = resize(&s, 2 * length);
            }
            s[i++] = ch;
            ch = getchar();
        }
    } while (ch != '\n');
    s[i] = '\0';

    return s;
}

static int resize(char **s, int new_length) {
    char *temp = realloc(*s, (new_length + 1) * sizeof(char));

    if (temp == NULL) {
        printf("Error: could not store string.");
        exit(EXIT_FAILURE);
    } else {
        *s = temp;
    }

    return new_length;
}