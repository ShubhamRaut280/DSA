#include<bits/stdc++.h>
using namespace std;

// telephone implementation using hash table
class data {
    public:
    int client_id;
    string telephone;

    data() {
        client_id = -1;
        telephone = "";
    }

    data(int client_id, string telephone){
        this->client_id = client_id;
        this->telephone = telephone;
    } 
};

class Map {
    public:
    int TableSize;
    data* hashTable;

    Map(int size){
        TableSize = size;
        hashTable = new data[TableSize];
    }

    bool insert(int client_id, string telephone){
        int ind = client_id % TableSize;
        for(int i=0; i<TableSize; i++){
            if(hashTable[ind].telephone == ""){
                hashTable[ind] = data(client_id, telephone);
                return true;
            }
        }
        return false;
    }

    data search(int client_id){
        int ind = client_id % TableSize;
        for(int i=0; i<TableSize; i++){
            if(hashTable[ind].client_id == client_id){
                return hashTable[ind];
            }
        }
        return data();
    }

    bool deleteData(int client_id){
        int ind = client_id % TableSize;
        for(int i=0; i<TableSize; i++){
            if(hashTable[ind].client_id == client_id){
                hashTable[ind] = data();
                return true;
            }
        }
        return false;
    }

};

int main(){

    Map database(10);

    int choice = -1, c = -1;
    string t;
    data d;

    while(choice != 4){
        cout << "************* MENU *************\n";
        cout << "1. Insert Client Details\n";
        cout << "2. Search Client Details\n";
        cout << "3. Delete Client Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter Client id to insert: ";
                cin >> c;
                cout << "Enter telephone no. of Client: ";
                cin >> t;
                if(database.insert(c, t))
                    cout << "Data inserted Successfully.";
                else 
                    cout << "Database full.";
                break;
            case 2:
                cout << "Enter Client id to search: ";
                cin >> c;
                d = database.search(c);
                if(d.client_id == -1){
                    cout << "Data not Found.";
                }
                else {
                    cout << "Client has telephone no.: " << d.telephone;
                }
                break;
            case 3:
                cout << "Enter Client id to delete: ";
                cin >> c;
                d = database.search(c);
                if(d.client_id == -1){
                    cout << "Data not Found.";
                }
                else {
                    database.deleteData(c);
                    cout << "Data with client id " << c << " Successfully deleted.";
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice.";
                break;
        }
        cout << "\n\n";
    }
    
    return 0;
}