#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string title;
    int childs;
    node *child[10];

    node()
    {
        this->title = "";
        this->childs = 0;
    }
};

class Book
{
public:
    node *name;
    Book()
    {
        name = new node();
    }
    void create()
    {
        cout << "\nEnter the title of the book: ";
        cin >> name->title;
        cout << "\nHow many chapter does this book have:  ";
        cin >> name->childs;
        for (int i = 1; i <= name->childs; i++)
        {
            name->child[i] = new node();
            cout << "\nEnter the name of chapeter " << i << " : ";
            cin >> name->child[i]->title;
            cout << "\nHow many sections does" << name->child[i]->title << " have: ";
            cin >> name->child[i]->childs;
            for (int j = 1; j <= name->child[i]->childs; j++)
            {
                name->child[i]->child[j] = new node();
                cout << "\nEnter name of the section " << j << " : ";
                cin >> name->child[i]->child[j]->title;
            }
        }
    }

    void print()
    {
        cout << "\nBook name : " << name->title;
        for (int i = 1; i <= name->childs; i++)
        {
            cout << "\n\t" << name->child[i]->title;
            for (int j = 1; j <=name->child[i]->childs; j++)
            {
                cout << "\n\t\t" << name->child[i]->child[j]->title;
            }
        }
        cout << endl;
    }
};

int main()
{
    Book b;
    b.create();
    b.print();
    return 0;
}