#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<cstdio>
#include<iomanip>
#include<stdlib.h>
#include<dos.h>

using namespace std;

class Blueprint
{
    public:
        int nq; //number of question including sub divisions
        float weightage[20];
        int slo[20];
};

class Marks : public Blueprint
{
    public:
        float mark[20];

        double total;
};

class Student
{
    public:
        char name[30],regno[9];
};

class Total
{
    public:
        double x[5][20];
};

int main()
{
    char user[10],pass[10],faculty[20],slot[10],course_name[30],course_code[10];
    int n,i,j,a,x;
    cout<<"Username: ";
    cin>>user;
    cout<<"Password: ";
    cin>>pass;


    if(strcmp(user,"admin")==0 && strcmp(pass,"admin")==0)
        cout<<"Username & Password Verified!!"<<endl;
    else
    {
        cout<<"Wrong Username or Password"<<endl;
        exit(0);
    }

    cout<<"Course Name: ";
    cin>>course_name;
    cout<<"Course Code: ";
    cin>>course_code;
    cout<<"Faculty Name: ";
    cin>>faculty;
    cout<<"Slot: ";
    cin>>slot;



    cout<<"Enter the number of Students: ";
    cin>>n;
    cout<<endl;

    Blueprint b[5]; //Same structure for all the internals

    Marks m[n][5];
    Student s[n];
    Total t;

    int ch;
    cout<<"1. CAT 1\n2. CAT 2\n3. Assignment 1\n4. Assignment 2\n5. Assignment 3\n\nEnter your choice: ";
    cin>>ch;
    i=ch;
    if(i==1)
        cout<<"\nCAT 1:"<<endl;
    if(i==2)
        cout<<"\nCAT 2:"<<endl;
    if(i==3)
         cout<<"\nAsssignment 1 (DA/Quiz):"<<endl;
    if(i==4)
        cout<<"\nAsssignment 2 (DA/Quiz):"<<endl;
    if(i==5)
        cout<<"\nAsssignment 3 (DA/Quiz):"<<endl;
    i--;
    ch--;
    cout<<"No. of Questions (including subdivisions): ";
    cin>>b[i].nq;

    cout<<"\nEnter the weightage of each question\n";
    for(j=0;j<b[i].nq;j++)
    {
        cout<<"Question "<<j+1<<": ";
        cin>>b[i].weightage[j];
    }

    cout<<"\nEnter the SLO of each question\n";
    for(j=0;j<b[i].nq;j++)
    {
        cout<<"Question "<<j+1<<": ";
        cin>>b[i].slo[j];
    }

    cout<<"Updated Blueprint Details!!\n\n";
    cout<<"Enter Student Details!!\n\n";

    for(a=0;a<n;a++)
    {
        cout<<"Name & Reg.No:";
        cin>>s[a].name>>s[a].regno;

        cout<<endl<<s[a].name<<"\t"<<s[a].regno<<endl;

        m[a][ch].total=0.0;

        cout<<"\nEnter the mark of each question\n";
        for(j=0;j<b[ch].nq;j++)
        {
            cout<<"Question "<<j+1<<": ";
            cin>>m[a][ch].mark[j];

            m[a][ch].total+=m[a][ch].mark[j];
        }
        cout<<"\nTotal = "<<m[a][ch].total<<endl<<endl;
    }


    //Calculating Question-wise total

    for(j=0;j<b[ch].nq;j++)
    {
        t.x[ch][j]=0;
        for(a=0;a<n;a++)
        {
            t.x[ch][j]+=m[a][ch].mark[j];
        }

        cout<<"Question "<<j+1<<" Total = "<<t.x[ch][j]<<endl;

    }


    //Output in tabular format
    i=ch+1;
    if(i==1)
        cout<<"\nCAT 1:"<<endl;
    if(i==2)
        cout<<"\nCAT 2:"<<endl;
    if(i==3)
         cout<<"\nAsssignment 1 (DA/Quiz):"<<endl;
    if(i==4)
        cout<<"\nAsssignment 2 (DA/Quiz):"<<endl;
    if(i==5)
        cout<<"\nAsssignment 3 (DA/Quiz):"<<endl;

    cout<<endl<<endl;
    cout<<"Name\tReg.No\t\t";
    for(i=0;i<b[ch].nq;i++)
    {
        cout<<"Q"<<i+1<<"\t";
    }
    cout<<"Total"<<endl;

    cout<<"\t\t\t";
    for(i=0;i<b[ch].nq;i++)
    {
        cout<<"SLO-"<<b[ch].slo[i]<<"\t";
    }
    cout<<endl;

    cout<<"\t\t\t";
    for(i=0;i<b[ch].nq;i++)
    {
        cout<<"["<<b[ch].weightage[i]<<"]\t";
    }
    cout<<endl;

    for(a=0;a<n;a++)
    {
        cout<<s[a].name<<"\t";
        for(x=0;x<9;x++)
        {
            cout<<s[a].regno[x];
        }

        cout<<"\t";
        for(j=0;j<b[ch].nq;j++)
            cout<<m[a][ch].mark[j]<<"\t";
        cout<<m[a][ch].total;
        cout<<endl;
    }
    cout<<endl;
    cout<<"\tTotal\t\t";
    for(i=0;i<b[ch].nq;i++)
    {
        cout<<t.x[ch][i]<<"\t";
    }

    cout<<endl<<endl;
    //Identifying unique SLOs
    int SLO[20];
    a=0;
    SLO[a]=b[ch].slo[0];
    int flag=0;
    for(i=1;i<b[ch].nq;i++)
    {
        for(j=0;j<=a;j++)
        {
            if(SLO[j]==b[ch].slo[i])
            {
                flag=1;
                break;
            }

        }
        if(flag==0)
            SLO[++a]=b[ch].slo[i];
        flag=0;
    }
    //Sorting SLO's
    int temp;
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=a-1;j++)
        {
            if(SLO[j]>SLO[j+1])
            {
                temp=SLO[j];
                SLO[j]=SLO[j+1];
                SLO[j+1]=temp;
            }
        }
    }
    cout<<"\nUnique SLOs: ";
    for(i=0;i<=a;i++)
        cout<<SLO[i]<<" ";


    //SLO Total
    int SLO_sum[a];
    for(i=0;i<=a;i++)
    {
        SLO_sum[i]=0;
        for(j=0;j<b[ch].nq;j++)
        {
            if(SLO[i]==b[ch].slo[j])
            {
                SLO_sum[i]+=t.x[ch][j];
            }
        }
    }

    //Printing SLO Total

    cout<<endl<<endl<<"SLO Total:\n";
    cout<<"SLO\t\t";
    for(i=0;i<=a;i++)
    {
        cout<<SLO[i]<<"\t";
    }
    cout<<endl;
    cout<<"SLO Total\t";
    for(i=0;i<=a;i++)
    {
        cout<<SLO_sum[i]<<"\t";
    }

    cout<<"\nAverage\t\t";
    for(i=0;i<=a;i++)
    {
        cout<<setprecision(2)<<(SLO_sum[i]*1.0/n)<<"\t";
    }

}

