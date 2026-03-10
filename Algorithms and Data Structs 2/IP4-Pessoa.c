#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TSIZE 100

typedef struct
{
    char name[20];
    int cpf;
} Person;

void init(Person table[])
{
    for (int i = 0; i < TSIZE; i++)
    {
        table[i].name[0] = '\0';
        table[i].cpf = -1;
    };
}

int hash(int cpf)
{
    return cpf % TSIZE;
}

void insert(Person table[], Person person)
{
    int id = hash(person.cpf);
    int counter = 0;

    while (table[id].cpf != -1)
    {
        id = hash(id + 1);
        counter++;
    }

    if (counter == TSIZE)
        printf("Table is fulled\n");
    else
        table[id] = person;
}

Person search(Person table[], int cpf)
{
    int id = hash(cpf);
    while (table[id].cpf != cpf)
        id = hash(id + 1);
    return table[id];
}

void showTable(Person table[], bool emptySlots)
{
    for (int i = 0; i < TSIZE; i++)
    {
        Person person = table[i];
        if (!emptySlots && person.cpf == -1) continue;

        if(person.cpf == -1) printf("#%d: empty\n", i);
        else printf("#%d: %s (CPF: %d)\n", i, person.name, person.cpf);
    }
}

void getPerson(Person people[])
{
    Person person;
    printf("Enter person name: ");
    scanf(" %19[^\n]s", person.name);
    printf("Enter person cpf: ");
    scanf("%d", &person.cpf);
    insert(people, person);
}

int main()
{
    Person people[TSIZE];
    init(people);
    for (int i = 0; i < 3; i++)
        getPerson(people);

    while (1)
    {
        printf("\n1 - Enter new person\n");
        printf("2 - Search by person cpf\n");
        printf("3 - Show people\n");
        printf("4 - Show people (includes empty slots)\n");
        printf("5 - Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getPerson(people);
            break;

        case 2:
            printf("\nEnter person cpf: ");
            int cpf;
            scanf("%d", &cpf);
            Person person = search(people, cpf);
            printf("%s (CPF: %d)\n", person.name, person.cpf);
            break;

        case 3:
            showTable(people, false);
            break;

        case 4:
            showTable(people, true);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nInvalid option!");
            break;
        }
    }
}