#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }
    tmp->link = L;
}

void Remove(Elem*& first, Info value)
{
    if (first == NULL)
        return;

    Elem* current = first;
    Elem* previous = NULL;

    do
    {
        if (current->link->info == value)
        {
            if (previous != NULL)
            {
                previous->link = current->link;
                delete current;
                current = previous->link;
            }
            else
            {
                Elem* last = first;
                while (last->link != first)
                    last = last->link;
                first = first->link;
                last->link = first;
                delete current;
                current = first;
            }
        }
        else
        {
            previous = current;
            current = current->link;
        }
    } while (current != first);
}

void Print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << setw(4) << L->info;
    while (L->link != first)
    {
        L = L->link;
        cout << setw(4) << L->info;
    }
    cout << endl;
}

int main()
{
    Elem* L = NULL;
    for (int i = 0; i < 10; i++)
        Insert(L, i);
    Print(L);

    int value;
    cout << "Enter a value: ";
    cin >> value;

    Remove(L, value);
    Print(L);

    return 0;
}