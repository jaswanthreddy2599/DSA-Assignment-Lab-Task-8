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

void insertAtPosition(int x, int pos)
{
    struct node *newnode, *temp;
    int i;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if(pos == 1)
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
        return;
    }

    temp = head;
    for(i = 1; i < pos-1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
}

void display(int n)
{
    struct node *temp = head;
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, i, x, value, pos;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create(x);
    }

    scanf("%d", &value);
    scanf("%d", &pos);

    insertAtPosition(value, pos);

    display(n + 1);

    return 0;
}
