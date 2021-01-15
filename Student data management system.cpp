#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
using namespace std;
bool check = true;
struct node    //structure of node //
{
 char name[20];
 char fathername[20];
 int sap;
 char cs;
 char section;
 node *next;
}*head,*lastptr;

void add()    //Adds record of student//
{
 node *p;
 p=new node;
 cout<<"Enter  name of student:"<<endl;
 gets(p->name);
 fflush(stdin);
 cout<<"Enter Father name of student:"<<endl;
 gets(p->fathername);
 fflush(stdin);
 cout<<"Enter sap id of student:"<<endl;
 cin>>p->sap;
 fflush(stdin);
 cout<<"Enter course of student:"<<endl;
 cin>>p->cs;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>p->section;
 fflush(stdin);
 p->next=NULL;

 if(check)
 {
  head = p;
  lastptr = p;
  check = false;
 }
 else
 {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Recored Entered";
 getch();
}
void modify()   //modifies record of student//
{
 node *ptr;
 node *prev=NULL;
 node *current=NULL;
 int sap;
 cout<<"Enter sap id to search:"<<endl;
 cin>>sap;
 prev=head;
 current=head;
 while(current->sap!=sap)
 {
  prev=current;
  current=current->next;
 }
 ptr=new node;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 gets(ptr->name);
 fflush(stdin);
 cout<<"Enter father name of student:"<<endl;
 gets(ptr->fathername);
 fflush(stdin);
 cout<<"Enter sap id of student:"<<endl;
 cin>>ptr->sap;
 fflush(stdin);
 cout<<"Enter course of student:"<<endl;
 cin>>ptr->cs;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>ptr->section;
 fflush(stdin);
 prev->next=ptr;
 ptr->next=current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Recored Modified";
 getch();
}
void search()   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 int sap;
 cout<<"Enter sap id to search:"<<endl;
 cin>>sap;
 prev=head;
 current=head;
 while(current->sap!=sap)
 {
  prev=current;
  current=current->next;
 }
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nfathername:";
 puts(current->fathername);
  cout<<"\nsap id:";
 cout<<current->sap;
  cout<<"\ncourse:";
 cout<<current->cs;
 cout<<"\nSection:";
 cout<<current->section;
 getch();
}
void del()    //deletes record of a student//
{
 node *ptr=NULL;
 node *prev=NULL;
 node *current=NULL;
 int sap;
 cout<<"Enter sap id to Delete:"<<endl;
 cin>>sap;
 prev=head;
 current=head;
 while(current->sap!=sap)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Recored Deleted";
 getch();
}

int main()
{
 char x;
 cout<<"\t**             ** ****** *         *****      **    ***     *** ********       "<<endl;
 cout<<"\t**             ** *      *        **   **   **  **  ** *   * ** *              "<<endl;
 cout<<"\t**     ***     ** *      *       **        **    ** **  * *  ** *              "<<endl;
 cout<<"\t**   *** ***   ** ****   *        **       **    ** **   *   ** ******         "<<endl;
 cout<<"\t** ***     *** ** *      *         **  **   **  **  **       ** *              "<<endl;
 cout<<"\t***           *** ****** *******    ****      **    **       ** ********       "<<endl;
 cout<<""<<endl;
 cout<<""<<endl;
 cout<<""<<endl;
 cout<<"\t\t\t\t -------------------------------------- \t\t\t"<<endl;
 cout<<"\t\t\t\t [************************************] \t\t\t"<<endl;
 cout<<"\t\t\t\t [** STUDENT DATA MANAGEMENT SYSTEM **] \t\t\t"<<endl;
 cout<<"\t\t\t\t [************************************] \t\t\t"<<endl;
 cout<<"\t\t\t\t -------------------------------------- \t\t\t"<<endl;
 cout<<"\n\nPress Any Key To Continue . . . ."<<endl;

 getch();
 do
 {
  system("cls");
  cout<<"1--->Press '1' to add New record:"<<endl;
  cout<<"2--->Press '2' to search a record:"<<endl;
  cout<<"3--->Press '3' to modify a record:"<<endl;
  cout<<"4--->Press '4' to delete a record:"<<endl;
  cout<<"5--->Press '5' to exit:"<<endl;
  x=getch();
  if(x=='1')
  {
   system("cls");
   add();
  }
  else if(x=='2')
  {
   system("cls");
   search();
  }
  else if(x=='3')
  {
   system("cls");
   modify();
  }
  else if(x=='4')
  {
   system("cls");
   del();
  }
  else if(x=='5')
  {
   exit(0);
  }
  else
  {
  }
 }while(x != 27);
 getch();
}

