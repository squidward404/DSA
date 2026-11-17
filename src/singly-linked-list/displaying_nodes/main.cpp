//this is a code for the display function only
#include<iostream>
using namespace std;
struct Student{
    char name[30];
    int age;
    float gpa;
    Student*next;
};
Student *start=NULL;
//other function declarations
void display();

int main(){
Student *p=new Student;
cout<<"Enter name of the student: ";
cin>>ws;
cin.get(p->name,30);
cout<<"Enter the age of the student: ";
cin>>p->age;
cout<<"Enter the GPA of the student: ";
cin>>p->gpa;
start=p;
p->next=NULL;
display();
}
void display(){
    //Student *temp=start; (no need for a temp pointer since I only have a single node/use start pointer)
if(start==NULL){
    cout<<"List is empty.Try inserting nodes!";
    return ;
}
   cout<<"----------------------\n";
   cout<<"Name: "<<start->name<<"\n"; //print the node using the start pointer
   cout<<"AGE: "<<start->age<<"\n";
   cout<<"GPA: "<<start->gpa<<"\n";
   cout<<"----------------------\n";  
   /*while(temp->next!=NULL){
    temp=temp->next;
    cout<<"----------------------\n";
    cout<<"Name: "<<temp->name<<"\n";  print the remining nodes at each iteration(for multiple nodes).
    cout<<"AGE: "<<temp->age<<"\n";
    cout<<"GPA: "<<temp->gpa<<"\n";
    cout<<"----------------------\n";
   }*/
}