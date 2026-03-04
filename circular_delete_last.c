#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int x)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
        return;

    temp = head;

    if(temp->next == head)
    {
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void display()
{
    struct node *temp;

    if(head == NULL)
        return;

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create(x);
    }

    deleteLast();

    display();

    return 0;
}
