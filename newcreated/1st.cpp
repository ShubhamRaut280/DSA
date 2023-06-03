#include <iostream>
using namespace std;
#define max 20
class data
{
public:
    int id;
    string name;
    string pno;

public:
    data()
    {
        this->id = -1;
        this->name = "";
        this->pno = "";
    }
    data(int id, string name, string no)
    {
        this->id = id;
        this->name = name;
        this->pno = no;
    }
};

class database
{
public:
    data htable[max];
    int tsize = max;
    int osize = 0;

    void insert()
    {
        int idno;
        string nam;
        string phone;
        if (osize < tsize)
        {
            cout << "\nEnter id of the contact: ";
            cin >> idno;
            cout << "\nEnter name of the contact : ";
            cin >> nam;
            cout << "\nEnter phone number of the contact : ";
            cin >> phone;

            int ind = hash(idno);

            while (htable[ind].name != "")
            {
                ind = (ind + 1) % tsize;
            }

            htable[ind].id = idno;
            htable[ind].name = nam;
            htable[ind].pno = phone;
            osize++;
        }
        else
        {
            cout << "\nDatabase is full..";
        }
    }

    int hash(int a)
    {
        return a % tsize;
    }

    void print()
    {
        cout << "\n     \t\t\tDatabase   \t\t\t  \n\n";

        for (int i = 0; i < max; i++)
        {
            if(htable[i].id!=-1)
            {
                cout << "\n\tId\t\tName\t\tPhone no";
            cout << "\n\t" << htable[i].id << "\t\t" << htable[i].name << "\t        " << htable[i].pno << endl;
            }
            
            
        }
    }

    void search()
    {
        int idn, cmp  = 1;
        cout<<"\nEnter id of contact to be searched : ";
        cin>>idn;
        int ind = idn%tsize;
        while(htable[ind].id!=idn)
        {
                cmp++;
                ind = (ind+1)%tsize;

        }

        if(htable[ind].id==idn)
        {
            cout<<"\nNo of comp: "<<cmp;
            cout << "\n\tId\t\tName\t\tPhone no";
            cout << "\n\t" << htable[ind].id << "\t\t" << htable[ind].name << "\t        " << htable[ind].pno << endl;
        
        }
        else
        {
            cout<<"Record not found...";
        }


    }

    void delet()
    {
        int id ;
        cout<<"\nEnter id to be deleted: ";
        cin>>id;
        int ind = hash(id);
        while (htable[ind].id!=id)
        {
            ind = (ind+1)%tsize;
        }
        htable[ind].id = -1;
        htable[ind].name = "";
        htable[ind].pno = "";
    
    }
};

int main()
{
    int t;

    database db;
    cout << "how mant contact you want to store: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        db.insert();
    }
    db.print();
    cout << "size occupied: " << db.osize;
    db.search();

    return 0;
}