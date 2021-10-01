#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack
{
public:
    node *head;
    node *tail;

    stack()
    {
        head = NULL;
        tail = NULL;
    }
};

void push(int data, stack *ms)
{
    node *temp = new node();
    temp->data = data;
    temp->next = ms->head;

    // when pushing first element in the stack the tail
    // must be pointed by that first element
    if (ms->head == NULL)
        ms->tail = temp;

    ms->head = temp;
}

int pop(stack *ms)
{
    if (ms->head == NULL)
    {
        cout << "stack underflow" << endl;
        return 0;
    }
    else
    {
        node *temp = ms->head;
        ms->head = ms->head->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }
}

int Top(stack *ms)
{
    node *top = ms->head;
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        return top->data;
    }
}

// making the next pointer of tail of
// one stack point to other stack
void merge(stack *ms1, stack *ms2)
{
    if (ms1->head == NULL)
    {
        ms1->head = ms2->head;
        ms1->tail = ms2->tail;
        return;
    }

    ms1->tail->next = ms2->head;
    ms1->tail = ms2->tail;
}

void display(stack *ms)
{
    node *temp = ms->head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void reverse(stack *ms)
{
    node *current = ms->head;
    node *prev = NULL;
    node *next;
    ms->tail = ms->head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ms->head = prev;
}

void splitStack(stack *ms1, stack *s1, stack *s2, int p, int q)
{
    int n = 0;
    node *temp;
    temp = ms1->head;
    while (temp != NULL)
    {
        n += 1;
        temp = temp->next;
    }

    if (p + q != n)
    {
        cout << "Stack can't be split" << endl;
    }

    else
    {
        // pushing the first p elements from head in s1
        node *ptr = ms1->head;
        do
        {
            push(ptr->data, s1);
            ptr = ptr->next;
            p--;
        } while (p != 0);

        // pushing the last q elements in s2
        while (ptr != NULL)
        {
            push(ptr->data, s2);
            ptr = ptr->next;
        }

        reverse(s1);
        reverse(s2);
    }
}

int main()
{
    stack *ms1 = new stack();
    stack *ms2 = new stack();

    push(6, ms1);
    push(5, ms1);
    push(4, ms1);
    int top;
    top = Top(ms1);
    cout << "Top element of stack 1: " << top << endl;
    display(ms1);
    cout << endl;
    push(9, ms2);
    push(8, ms2);
    push(7, ms2);
    cout << "Before popping  the element: " << endl;
    display(ms2);
    cout << endl;
    cout << "Elememnt popped"
         << " " << pop(ms2) << endl;
    top = Top(ms2);
    cout << "Top element of stack 2: " << top << endl;
    display(ms2);
    cout << endl;
    cout << "Merge Stack called: ";
    merge(ms1, ms2);
    display(ms1);
    cout << endl;
    cout << endl;
    stack *subSt1 = new stack();
    stack *subSt2 = new stack();
    cout << "Split Stack called: " << endl;
    splitStack(ms1, subSt1, subSt2, 3, 2);
    display(subSt1);
    cout << endl;
    display(subSt2);
    return 0;
}



