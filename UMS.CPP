#include<iostream>
#include <vector>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<algorithm>

//std::vector<vector>targVector;//vtarg
using namespace std;

//1.
class student
{  
    public:  
        long int reg;  
        char name[80],branch[50];  
        void input()
        {
            cout << "\n Enter name: ";
            cin.ignore();
            cin.getline(name, 80);
            cout << "\n Enter roll no: ";
            cin >> reg;
            cin.ignore();
            cout << "\n Enter Branch: ";
            cin.getline(branch, 50);
        }

        /*void input()  
        {  
            cout<<"\n Enter name: ";  
            gets(name);  
            cout<<"\n Enter roll no: ";  
            cin>>reg;  
          //  fflush(stdin);  
            cout<<"\n Enter Branch: ";  
            gets(branch);  
        } */ 
        void display()  
        {  
            system("CLS");  
            cout<<"\t\tDisplay Records";  
            cout<<"\n";  
            cout<<"\n Name - "<<name;  
            cout<<"\n Reg no. - "<<reg;  
            cout<<"\n Branch - "<<branch;  
            cout<<"\n";  
            system("PAUSE");  
            system("CLS");  
        }  
	bool operator==(student a)
        {  
            if(reg==a.reg)  
	       { return true; }
	    else
	       { return false; }
	}
};  
vector <student>v;

//0.
void insert_new()
{
    student newStudent;
    newStudent.input(); // Get input for the new student
    v.push_back(newStudent); // Add the new student to the vector
   //  bubblesort(); // Sort the vector after inserting a new student
}


//0.
void write_file()
{
    fstream f;
    f.open("College.txt", ios::out);
    if (f)
    {
        for (int i = 0; i < v.size(); i++)
        {
            f.write((char *)&v[i], sizeof(class student));
        }
        cout << "\nData written to file successfully!" << endl;
    }
    else
    {
        cout << "\nError opening file for writing!" << endl;
    }
    f.close();
}


//2. 

int search_reg(long int reg, int &i);  
  
void get_file()  
{  
    student x;  
    int i=0;  
    fstream f;  
    f.open("College.txt",ios::in);  
    if(f)  
    {  
        f.read((char *) &x,sizeof(class student));  
        while(!f.eof())  
        {  
            v.push_back(x);  
            f.read((char *) &x,sizeof(class student));  
        }  
    }  
    else  
    {

    }  
    f.close();  
}  

//3. use to sort the students record in a bubble sort fashion which will have a complexity of O(n^2).

void bubblesort()  
{  
    int i,j;  
    student x;  
    for(i=0;i<v.size();i++)  
        for(j=0;j<v.size()-i-1;j++)  
            if(v[j].reg>v[j+1].reg)  
            {  
                x=v[j];  
                v[j]=v[j+1];  
                v[j+1]=x;  
            }     
}  

//4.  use to insert new data into the college students record
/*
void bubblesort()  
{  
    int i,j;  
    student x;  
    for(i=0;i<v.size();i++)  
        for(j=0;j<v.size()-i-1;j++)  
            if(v[j].reg>v[j+1].reg)  
            {  
                x=v[j];  
                v[j]=v[j+1];  
                v[j+1]=x;  
            }     
}  

//5. use to write the result of the bubble sort function performed on the data of the college students into the college txt file.

void bubblesort()  
{  
    int i,j;  
    student x;  
    for(i=0;i<v.size();i++)  
        for(j=0;j<v.size()-i-1;j++)  
            if(v[j].reg>v[j+1].reg)  
            {  
                x=v[j];  
                v[j]=v[j+1];  
                v[j+1]=x;  
            }     
}   */

//6. use to search registration of a student in the college int the data file created for the student.

int search_reg(long int reg, int &i)  
{  
    int ta=0;  
    for(i=0;i<v.size();i++)  
        if(v[i].reg==reg)  
        {  
            ta=1;  
            break;  
        }  
    return ta;  
}  

//7. use to search the name of a student in the record file created for the student.

int search_name(char name[], vector<int> &vi)  
{  
    int i,ta=0;  
    for(i=0;i<v.size();i++)  
        if(strcmp(v[i].name,name)==0)  
        {  
            ta=1;  
            vi.push_back(i);  
        }  
    return ta;  
}  

//8. use to search the branch.

int search_branch(char branch[], vector<int> &vj)  
{  
    int i,ta=0;  
    for(i=0;i<v.size();i++)  
        if(strcmp(v[i].branch,branch)==0)  
        {  
            ta=1;  
            vj.push_back(i);  
        }  
    return ta;  
}  

//9. use to show the result.

void search_and_show()  
{  
    int ch,i,ta=0;  
    char name[80],branch[50];  
    vector <int>vi;   
    vector <int>vj;  
    long int reg;  
    poi:  
    cout<<"\n1.Press to search reg no."  
    <<"\n2.Press to search name"  
    <<"\n3.Press to search branch";  
    cin>>ch;  
    switch(ch)  
    {  
        case 1:  
            cout<<"\nEnter reg no.: ";  
            cin>>reg;  
            if(search_reg(reg,i)==1)  
                v[i].display();  
            else  
                cout<<"\nRecord NOT FOUND!!!";  
            break;  
        case 2:  
            cout<<"\nEnter name: ";  
            fflush(stdin);  
            gets(name);  
            if(search_name(name,vi)==1)  
            {  
                for(int j=0;j<vi.size();j++)  
                    v[vi[j]].display();  
            }  
            else  
                cout<<"\nRecord NOT FOUND!!!";  
            break;  
        case 3:  
            cout<<"\nEnter branch: ";  
            fflush(stdin);  
            gets(branch);  
            if(search_branch(branch,vj)==1)  
            {  
                for(int j=0;j<vj.size();j++)  
                    v[vj[j]].display();  
            }  
            else  
                cout<<"\nRecord NOT FOUND!!!";  
            break;  
        default:  
            cout<<"\nWrong CHOICE!!!";  
            goto poi;  
    }  
}  
void show()  
{  
    int i;  
    for(i=0;i<v.size();i++)  
        v[i].display();  
}  

//10. use to delete the stored data.

void delete_data()  
{  
    int i,j;  
    long int reg;  
    vector <student>::iterator p=v.begin();  
    cout<<"\nEnter Reg. no.: ";  
    cin>>reg;  
    if(search_reg(reg,i)==1)  
    {  
        student x=v[i];  
        cout<<"\nThe following data is being deleted";  
        x.display();  
        p+=i;  
        v.erase(p,p+1);  
    }  
}  

//11.  use to edit the data.

void edit_data()  
{  
    int i,j;  
    long int reg;  
    vector <student>vi;  
    cout<<"\nEnter Reg. no.: ";  
    cin>>reg;  
    if(search_reg(reg,i)==1)  
    {  
        cout<<"\nEnter new data:";  
        fflush(stdin);  
        v[i].input();  
    }  
}  

//12. the switch cases for the system.

int main()  
{  
    int i=1;  
    get_file();  
    while(i)  
    {  
        system("CLS");  
        cout<<"\t\t\t-----------------------------------------\n";  
        cout<<"\t\t\t   LJ University Management System\n";  
        cout<<"\t\t\t-----------------------------------------\n";  
        cout<<"\n\t\t\tEnter <1> to Add new student"  
            <<"\n\t\t\tEnter <2> to Display all student"  
            <<"\n\t\t\tEnter <3> to Remove student"  
            <<"\n\t\t\tEnter <4> to Edit student"  
            <<"\n\t\t\tEnter <5> to Search student"  
            <<"\n\t\t\tEnter <0> to Exit\n";  
        cout<<"\n\n\t\t\tEnter Your Choice:";     
        cin>>i;  
        switch(i)  
        {  
            case 1 :  
                insert_new();  
                break;  
            case 2 :  
                show();  
                break;  
            case 3 :  
                delete_data();  
                break;  
            case 4 :  
                edit_data();  
                break;  
            case 5 :  
                search_and_show();  
                break;  
            case 0 :  
                write_file();  
                break;  
            default :  
                cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";  
        }  
    }  
    return 0;  
}  