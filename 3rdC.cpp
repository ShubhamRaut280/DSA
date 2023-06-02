#include <iostream>
using namespace std;

struct node
{
    char title[20];
    int node_count;
    struct node *child[10];
} * base;

class book
{
public:
    book()
    {
        base = NULL;
    }

    void creat()
    {
        int chapter, section, subsection, i, j, k;
        base = new node();

        cout << "The name of book is => ";
        // cin >> base->title;
        cin.getline(base->title,20);

        cout << "Enter the number of chapter => ";
        cin >> chapter;
        base->node_count = chapter;

        for (i = 0; i < chapter; i++)
        {
            base->child[i] = new node;

            cout << "Enter the name of chapter " << i + 1 << " => ";
            cin >> base->child[i]->title;

            cout << "Enter the number of section => ";
            cin >> section;
            base->child[i]->node_count = section;

            for (j = 0; j < section; j++)
            {
                base->child[i]->child[j] = new node;

                cout << "Enter the name of section " << j + 1 << "=> ";
                cin >> base->child[i]->child[j]->title;

                cout << "Enter the number of sub-section => ";
                cin >> subsection;
                base->child[i]->child[j]->node_count = subsection;

                for (k = 0; k < subsection; k++)
                {
                    base->child[i]->child[j]->child[k] = new node;

                    cout << "Enter the name of sub-section " << k + 1 << "=> ";
                    cin >> base->child[i]->child[j]->child[k]->title;
                }
            }
        }
    }

    void print(node *r)
    {
        int i, j, k, chapter;
        if (r != NULL)
        {
            cout << "\nThe book name is " << r->title << endl;

            chapter = r->node_count;

            for (i = 0; i < chapter; i++)
            {
                cout << "\nChapter " << i + 1 << endl;
                cout << "  " << r->child[i]->title;
                cout << "\n\tSection";
                for (j = 0; j < r->child[i]->node_count; j++)
                {
                    cout << "\n\t  " << r->child[i]->child[j]->title;
                    cout << "\n\t\tsubsection";
                    for (k = 0; k < r->child[i]->child[j]->node_count; k++)
                    {
                        cout << "\n\t\t   " << r->child[i]->child[j]->child[k]->title;
                    }
                }
            }
        }
    }
};

int main()
{
    book obj;
    obj.creat();

    cout << "---------------------" << endl;
    obj.print(base);
}