#include <stdio.h>
#include <stdlib.h>
#define TSIZE 10

void init(int table[])
{
    for (int i = 0; i < TSIZE; i++)
        table[i] = -1;
}

int hash(int value)
{
    return value % 10;
}

void insert(int table[], int value)
{
    int id = hash(value);
    while (table[id] != -1)
        id = hash(id + 1);
    table[id] = value;
}

void printTable(int table[])
{
    for (int i = 0; i < TSIZE; i++)
    {
        if (table[i] == -1)
            printf("%d: empty\n", i);
        else
            printf("%d: %d\n", i, table[i]);
    }
}

int main()
{
    int values[] = {17, 23, 51, 64, 35, 92};

    int table[TSIZE];
    init(table);
    for (int i = 0; i < 6; i++)
        insert(table, values[i]);

    printTable(table);
}