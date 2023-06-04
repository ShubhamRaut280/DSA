#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

struct Record {
    int id;
    string name;
    int age;
};
vector<Record> retrieveRecords(const string& filename) {
    ifstream inFile(filename, ios::binary);
    vector<Record> records;
    Record record;

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        records.push_back(record);
    }

    inFile.close();
    return records;
}
// Function to insert a record into the direct access file
void insertRecord(const Record& record, const string& filename) {
    ofstream outFile(filename, ios::binary | ios::app);
    outFile.write(reinterpret_cast<const char*>(&record), sizeof(record));
    outFile.close();
}

// Function to delete a record from the direct access file
void deleteRecord(int recordId, const string& filename) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    Record record;

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        if (record.id != recordId) {
            outFile.write(reinterpret_cast<const char*>(&record), sizeof(record));
        }
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

int main() {
    Record record1 = {1, "John", 25};
    Record record2 = {2, "Alice", 30};
    Record record3 = {3, "Bob", 35};

    insertRecord(record1, "records.dat");
    insertRecord(record2, "records.dat");
    insertRecord(record3, "records.dat");

    // Deleting record with id 2
    // deleteRecord(2, "records.dat");
    vector<Record> records = retrieveRecords("records.dat");

    for (const auto& record : records) {
        cout << "Record ID: " << record.id << endl;
        cout << "Name: " << record.name << endl;
        cout << "Age: " << record.age << endl;
        cout << endl;
    }

    return 0;
}
