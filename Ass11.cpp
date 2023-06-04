#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Student
{
	int no;
	string name;
	string addr;
	long mob;
	public:
	void get();
	void print();
	friend fstream& operator <<(fstream &out ,Student &s);
	friend fstream& operator >>(fstream &in ,Student &s);
	friend class StudentInfo;
};
void Student::get()
	{
		cout<<"Enter roll number."<<endl;
		cin>>no;
		cout<<"Enter name."<<endl;
		cin>>name;
		cout<<"Enter address."<<endl;
		cin.ignore();
		getline(cin,addr);
		cout<<"Enter mobile number."<<endl;
		cin>>mob;
	}
fstream& operator <<(fstream &out ,Student &s)
	{
		out<<s.no<<"\t";
		out<<s.name<<"\n";
		out<<s.addr<<"\n";
		out<<s.mob<<endl;
		return(out);
	}
void Student::print()
	{
		cout<<"Roll no. : "<<no<<"\t";
		cout<<"Name : "<<name<<endl;
		cout<<"Address : "<<addr<<endl;
		cout<<"Mobile no. : "<<mob<<endl;
	}

fstream& operator >>(fstream &in ,Student &s)
{
	in>>s.no;
	in>>s.name;
	in.ignore();
	getline(in,s.addr);
	in>>s.mob;
	return(in);
}
class StudentInfo
{
	fstream f;
	public:
	void add();
	void search();
	void del();
};
void StudentInfo::del()
{
	Student s;
	string s1;
	fstream f1;
	f1.open("Student1.text",  ios::out);
	cout<<"Enter name to be deleted."<<endl;
	cin>>s1;
	f.open("Student.text",  ios::in);
	while(1)
	{
		f>>s;
		if(f.eof())
			break;
		if(s.name!=s1)
			f1<<s;
	}
	f.close();
	f1.close();
	remove("Student.text");
	rename("Student1.text","Student.text");
}
			
			
void StudentInfo::add()
{
	Student s;
	s.get();
	f.open("Student.text",ios::app | ios::out | ios::in );
	f<<s;
	f.close();
}
void StudentInfo::search()
{
	Student s;
	string s1;
	cout<<"Enter the name of student to be searched."<<endl;
	cin>>s1;
	f.open("Student.text",ios::app | ios::out | ios::in );
	while(!f.eof())
	{
		f>>s;
		if(s.name==s1)
		{
			cout<<"Details :"<<endl;
			s.print();
			f.close();
			return;
		}
	}
	cout<<"Record of student not present."<<endl;
	f.close();
}
	
int main()
{
	StudentInfo Si;
	int op;
	do
	{
		cout<<"Select an option.\n1.Add record of new student.\n2.Delete record of a student.\n3.Display record of a student.\n4.Exit."<<endl;
		cin>>op;
		switch(op)
		{
			case 1:Si.add();
				break;
				
			case 2:Si.del();
				break;
				
			case 3:Si.search();
				break;
				
			case 4:break;
			
			default:cout<<"Enter a valid option."<<endl;
		}
	}while(op!=4);
	
	return(0);
}
	
	


/*

#include<bits/stdc++.h>
using namespace std;

// 11

struct Student {
    int roll_number;
    string name;
    string division;
    string address;
};

void add_student(Student student) {
    fstream file;
    file.open("students.txt", ios::out | ios::app);

    file << student.roll_number << " " << student.name << " " << student.division << " " << student.address << endl;

    file.close();
}

void delete_student(int roll_number) {
    fstream file;
    file.open("students.txt", ios::in);
    
    fstream new_file;
    new_file.open("new_students.txt", ios::out);

    Student student;
    while (file >> student.roll_number >> student.name >> student.division >> student.address) {
        if (student.roll_number != roll_number) {
            new_file << student.roll_number << " " << student.name << " " << student.division << " " << student.address << endl;
        }
    }

    new_file.close();

    file.close();

    remove("students.txt");
    rename("new_students.txt", "students.txt");
}

void display_student(int roll_number) {
    fstream file;
    file.open("students.txt", ios::in);

    Student student;

    while (file >> student.roll_number >> student.name >> student.division >> student.address) {
        if (student.roll_number == roll_number) {
            cout << "Roll number: " << student.roll_number << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            file.close();
            return;
        }
    }

    cout << "No student found." << endl;
    file.close();
}

int main() {
    
    int choice;

    while (true) {
        cout << "************* MENU *************\n";
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter student details: " << endl;

                int roll_number;
                string name, division, address;

                cout << "Enter Roll number: ";
                cin >> roll_number;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Division: ";
                cin >> division;
                cout << "Enter Address: ";
                cin >> address;

                Student student = {roll_number, name, division, address};

                add_student(student);
                break;
            }
            case 2: {
                cout << "Enter student roll number to delete: " << endl;

                int roll_number;
                cout << "Enter Roll number to delete: ";
                cin >> roll_number;

                delete_student(roll_number);
                break;
            }
            case 3: {
                int roll_number;
                cout << "Enter student roll number to display: " << endl;
                cin >> roll_number;

                display_student(roll_number);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
        cout << endl << endl;
    }
}

*/