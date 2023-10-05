#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;
    string nameb, roll_nob, courseb, addressb, email_idb, contact_nob;
    

public:
    void menu();
    void menu_a();
    void menu_b();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void insert_b();
    void display_b();
    void modify_b();
    void search_b();
    void deleted_b();
};

void student::menu()
{
   menu: 	
	int choice2;
    system("cls");
	cout<<right<<setw(40)<<setfill(' ')<<"\nMAIN MENU"<<endl<<endl<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	cout<<"			"<<" Select Division "<<endl;
	cout<<"			"<<"1.Division A"<<endl;
	cout<<"			"<<"2.Division B"<<endl;
	cout<<"			"<<"3.Exit"<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	
	cout<<"\nEnter the number corresponding to your choice:"<<endl;
	cin>>choice2;
    switch(choice2)
    {
        case 1 :
                  {
                     system("cls");
                    menu_a();
                  }break;
        case 2:
              {
                 system("cls");
                menu_b();
              }break;
        case 3:
              {
                exit(0);
              }
        default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";


    
    }



}   
void student::menu_a()
{
    int choice;
    char x;
    system("cls");
    cout<<"------------------------------------------------------------------"<<endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM-DIV A |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Main Menu" << endl;
    cout << "\t\t\t 7. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6/7]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;
    system("cls");

    switch (choice)
    {
  menustart:
    case 1:   
        { 
        system("cls");
            insert();    
        } 
        break;
    case 2:
     system("cls");
        display();
        break;
    case 3:
     system("cls");
        modify();
        break;

    case 4:
     system("cls");
        search();
        break;
    case 5:
     system("cls");
        deleted();
        break;
    case 6:
     system("cls");
        menu();
        break;
    case 7:
     //system("cls");
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void student::menu_b()
{  
    int chi;
    char x;
    system("cls");
    cout<<"------------------------------------------------------------------"<<endl;
     cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM-Div B|" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Main Menu" << endl;
    cout << "\t\t\t 7. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6/7]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> chi;
    system("cls");
    


    switch (chi)
    {
  menustart:
    case 1:
        
        {
             system("cls");
            insert_b();
        }
        break;
    case 2:
     system("cls");
        display_b();
        
        break;
    case 3:
     system("cls");
        modify_b();
        break;
    case 4:
     system("cls");
        search_b();
        break;
    case 5:
     system("cls");
        deleted_b();
        break;
    case 6:
     system("cls");
        menu();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void student::insert() // add student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
         system("cls");
         menu_a();
                break;
        case 2: exit(0);

    }
}

void student::display() // display students details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No. : " << total++ << endl;
            cout << "\t\t\t Student Name    : " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t Student course  : " << course << endl;
            cout << "\t\t\t Student Email Id.: " << email_id << endl;
            cout << "\t\t\t Student Contact No.: " << contact_no << endl;
            cout << "\t\t\t Student Address : " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present..."<<endl;;
        }
    }
    file.close();
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    if (m==1)
    {
         
               system("cls");
               menu_a();
                
        

    }
    else{
         exit(0);
    }
    

}
void student::modify() // Modify Students Details
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name  : ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course  : ";
                cin >> course;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address : ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
    cout<<"Data Modified Successfully!!!"<<endl;
    cout<<" "<<endl;
    
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: system("cls");
               menu_a();
                break;
        case 2: exit(0);

    }

}
void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Student Name   : " << name << endl;
                cout << "\t\t\t Student Roll No. : " << roll_no << endl;
                cout << "\t\t\t Student course   : " << course << endl;
                cout << "\t\t\t Student Email Id.: " << email_id << endl;
                cout << "\t\t\t Student Address  : " << address << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
    cout<<" "<<endl;
    
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
                system("cls");
                menu_a();
                break;
        case 2: exit(0);

    }

}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
             system("cls");
             menu_a();
                break;
        case 2: exit(0);

    }

}
void student::insert_b() // add student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Name    : ";
    cin >> nameb;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_nob;
    cout << "\t\t\tEnter Course  : ";
    cin >> courseb;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_idb;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_nob;
    cout << "\t\t\tEnter Address: ";
    cin >> addressb;
    file.open("divisionb.txt", ios::app | ios::out);
    file << " " << nameb << " " << roll_nob << " " << courseb << " " << email_idb << " " << contact_nob << " " << addressb << "\n";
    file.close();
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1:
         system("cls");
          menu_b();
                break;
        case 2: exit(0);

    }

}

void student::display_b() // display students details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("divisionb.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No. : " << total++ << endl;
            cout << "\t\t\t Student Name    : " << nameb << endl;
            cout << "\t\t\t Student Roll No.: " << roll_nob << endl;
            cout << "\t\t\t Student course  : " << courseb << endl;
            cout << "\t\t\t Student Email Id.: " << email_idb << endl;
            cout << "\t\t\t Student Contact No.: " << contact_nob << endl;
            cout << "\t\t\t Student Address : " << addressb << endl;
            file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
    cout<<" "<<endl;
   
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
         system("cls");
         menu_b();
                break;
        case 2: exit(0);

    }

}
void student::modify_b() // Modify Students Details
{
    system("cls");
    fstream file, file1;
    string rolln;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("divisionb.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rolln;
        file1.open("record2.txt", ios::app | ios::out);
        file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        while (!file.eof())
        {
            if (rolln != roll_nob)

                file1 << " " << nameb << " " << roll_nob << " " << courseb << " " << email_idb << " " << contact_nob << " " << addressb << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name  : ";
                cin >> nameb;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_nob;
                cout << "\t\t\tEnter Course  : ";
                cin >> courseb;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_idb;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_nob;
                cout << "\t\t\tEnter Address : ";
                cin >> addressb;
                file1 << " " << nameb << " " << roll_nob << " " << courseb << " " << email_idb << " " << contact_nob << " " << addressb << "\n";
                found++;
            }
         file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
            
        }
        if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        file1.close();
        file.close();
        remove("divisionb.txt");
        rename("record2.txt", "divisionb.txt");
    }
    cout<<"Data Modified Successfully!!!"<<endl;
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
         system("cls");
         menu_b();
                break;
        case 2: exit(0);

    }

}
void student::search_b() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("divisionb.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollo;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollo;
        file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        while (!file.eof())
        {
            if (rollo == roll_nob)
            {
                cout << "\n\t\t\t Student Name  : " << nameb << endl;
                cout << "\t\t\t Student Roll No.: " << roll_nob << endl;
                cout << "\t\t\t Student course  : " << courseb << endl;
                cout << "\t\t\t Student Email Id.: " << email_idb << endl;
                cout << "\t\t\t Student Address : " << addressb << endl;
                found++;
            }
            file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1:  system("cls");
                  menu_b();
                break;
        case 2: exit(0);

    }

}
void student::deleted_b()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("divisionb.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        while (!file.eof())
        {
            if (roll != roll_nob)
            {
                file1 << " " << nameb << " " << roll_nob << " " << courseb << " " << email_idb << " " << contact_nob << " " << addressb << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> nameb >> roll_nob >> courseb >> email_idb >> contact_nob >> addressb;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("divisionb.txt");
        rename("record.txt", "divisionb.txt");
    }
    cout<<" "<<endl;
    int m;
    cout<<"Enter 1. To Return to Menu OR 2.exit"<<endl;
    cin>>m;
    system("cls");
    switch (m)
    {
        case 1: 
                 system("cls");
                 menu_b();
                break;
        case 2: exit(0);

    }

}
int main()
{
    student project;
    
	

    project.menu();
    return 0;
}