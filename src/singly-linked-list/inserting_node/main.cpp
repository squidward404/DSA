#include<iostream>
using namespace std;
struct Student{
char name[30];
int age;
float gpa;
Student *next; //address portion of the node
};
Student *start=NULL; //initially the list is empty
void insert_beg(Student *p);
void insert_end(Student *p);
void insert_mid(int n,Student *p);
void print_nodes();
int main(){
int choice;
do{
cout<<"\n1.Insert a node at the beginning.\n";
cout<<"2.Insert a node at the end.\n";
cout<<"3.Insert at the middle. \n";
cout<<"4.Print nodes.\n";
cout<<"5.Exit.\n";
cout<<"@ What to do: ";
cin>>choice;
switch(choice){
    case 1:{
    Student *p=new Student; //create the first node but nothing points to it yet
    cout<<"Enter name of the student: ";
    cin>>ws;
    cin.get(p->name,30);
    cout<<"Enter the age of the student: ";
    cin>>p->age;
    cout<<"Enter the GPA of the student";
    cin>>p->gpa;
    insert_beg(p);
    }
    break;
    case 2:{
    Student *p=new Student;
    cout<<"Enter name of the student: ";
    cin>>ws;
    cin.get(p->name,30);
    cout<<"Enter the age of the student: ";
    cin>>p->age;
    cout<<"Enter the GPA of the student";
    cin>>p->gpa;
    insert_end(p);
    }
    break;
    case 3:{
    Student *p=new Student;
    cout<<"Enter name of the student: ";
    cin>>ws;
    cin.get(p->name,30);
    cout<<"Enter the age of the student: ";
    cin>>p->age;
    cout<<"Enter the GPA of the student";
    cin>>p->gpa;
    cout<<"Which node do you want to insert after: ";
    int n;
    cin>>n;
    insert_mid(n,p);
    }
    break;
    case 4:
    print_nodes();
    break;
    case 5:
    break;
    default:
    cout<<"Wrong choice.Try again!";
    break;
}
}while(choice!=5);
cout<<"BYE.";
}
void insert_beg(Student *p){
Student *temp; //temporary pointer to hold the address of the start pointer
if(start==NULL){ //check if the list is empty(it is for the first round)
start=p;
p->next=NULL;
cout<<"Node inserted at the beginning";
}else{
  temp=start;
  start=p; //the start pointer points to the new node
  p->next=temp; //the new node points to the previous first node  
  cout<<"Node inserted at the beginning";
}
cout<<endl;
}
void insert_end(Student *p){
Student *temp;
if(start==NULL){
  start=p;
  p->next=NULL;
  cout<<"Node inserted at the end";
}else{
temp=start; //temp starts from head so temp->next is the same as the data part of the first node p->next
while(temp->next!=NULL){
temp=temp->next; //go until temp->next=NULL
}
temp->next=p; //the next pointer of the last node points at p instead of NULL
p->next=NULL; //the next pointer of the new node points at NULL
}
cout<<endl;
}
void insert_mid(int n,Student *p){
Student *temp=start;
for(int i=0;i<n-1;++i){
  if(temp==NULL){
    cout<<"Less than "<<n<<" nodes.Insert more nodes.";
    return;
  }
  temp=temp->next; //adjust temp->next to the NULL position when the loop ends
}
p->next=temp->next;
temp->next=p;
cout<<"Node inserted";
cout<<endl;
}
void print_nodes(){
  Student *temp=start;
  if(start==NULL){
    cout<<"List is empty.Try inserting nodes!";
    return;
  }
   cout<<"Name: "<<temp->name<<"\n"; //print the first node before temp starts moving
   cout<<"AGE: "<<temp->age<<"\n";
   cout<<"GPA: "<<temp->gpa<<"\n";
   cout<<"----------------------\n";
  while(temp->next!=NULL){
   temp=temp->next;
   cout<<"Name: "<<temp->name<<"\n";
   cout<<"AGE: "<<temp->age<<"\n";
   cout<<"GPA: "<<temp->gpa<<"\n";
   cout<<"----------------------\n";
  }
  cout<<endl;
}