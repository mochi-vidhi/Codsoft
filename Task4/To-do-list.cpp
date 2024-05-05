#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
    string Task;
    bool isCompleted;
    struct node *next;
}node;

class TaskManager{
    public:
    int i;
    node *head,*newTask,*temp,*tail;
    TaskManager(){
        head = nullptr;
    }
    void inputTask(int taskNumber){
         i = 1;
        while(i <=taskNumber){
           newTask = new(node);
           cout<<"Enter Task "<<i<< " for your To-do list:";
           cin>>newTask->Task;
           newTask->isCompleted = false;
           newTask->next = nullptr;
           if(head==nullptr){
             head = newTask;
             temp = newTask;
             tail = newTask;
           } 
           else{
            temp->next = newTask;
            temp = newTask;
            tail = newTask;
           }
           i++;  
        }
    }
    void viewTask(){
        i =1;
        temp = head;
        if(head==nullptr){
            cout<<"List is Empty:";
        }
        else{
            cout<<"Latest  Tasks:\n"; 
            while(temp!=nullptr){
                cout<<"[] Task "<<i<<":"<<temp->Task;
                if(temp->isCompleted == true){
                    cout<<" (Completed) ";
                }
                else{
                    cout<<" (Pending)";
                }
                cout<<"\n-----------------------------------";
                temp = temp->next;
                cout<<endl;
                i++;
            }
        }
    }
    void  addTask(int &noTask){
         i=1;
         char ch='y';
         while(ch=='y'){
            newTask = new(node);
            cout<<"Add Your Latest Task:"<<i<<" : ";
            cin>>newTask->Task;
            newTask->isCompleted = false;
            newTask ->next = head;
            head = newTask;
            i++;
            noTask++;
            cout<<"Do you want to Add any other Tasks??\npress y... Otherwise press..n :";
            cin>>ch;
         }
         
         
    }
    void removeTask(int &noTask){
        int taskNo,i;
        char ch = 'y';
        while(ch =='y'){
        cout<<"-----------------------------------------------\n";
        cout<<"\nThe Number of task Available is:  "<<noTask<<endl;
        cout<<"\nYou want to delete any task between (1 to "<<noTask+1<<" )\n";
        cout<<"\nSpecify the task number to remove the task from your list:";
        cin>>taskNo;
        if(head==nullptr ){
            cout<<"\nList is empty...Nothing to remove...\n";
        }
        else{
        temp = head;
        if(taskNo==1){
                head = head->next;
                cout<<"============================================\n";
                cout << "Deleted task " << taskNo << ": " << temp->Task;
                cout<<"\n============================================\n";
                delete(temp);
            }
         else if(taskNo==noTask){
            if(head==tail){
                 temp = tail;
                 cout<<"==========================================\n";
                 cout<<"Deleted task "<<taskNo<<": "<<temp->Task;
                 cout<<"\n==========================================\n";
                 head = nullptr;
                 delete(temp);
            }
            else{
                node *prev=nullptr;
                while(temp->next!=tail){
                    prev = temp;
                    temp = temp->next;
                }
                if(prev!=nullptr){
                prev->next = nullptr;
                tail = prev;
                }
                cout<<"==========================================\n";
                cout<<"\nDeleted task "<<taskNo<<": "<<temp->Task;
                cout<<"==========================================\n";
                delete(temp);     
            }      
         }
         else if(taskNo>1){
            i=1;
            node *nexttask;
               while(i<taskNo-1 && temp!=nullptr){
                 temp = temp->next;
                 i++;
               }
               if (temp != nullptr && temp->next != nullptr) {
                    nexttask = temp->next;
                    temp->next = nexttask->next;
                    cout<<"==========================================\n";
                    cout << "Deleted task " << taskNo << ": " << nexttask->Task;
                    cout<<"\n===========================================\n";
                    delete(nexttask);
                }
                else {
                    cout << "Task number " << taskNo << " does not exist.\n";
                }

         }
          noTask--;
        }
        cout<<"\nDo You want to delete any other Task??\npress y... Otherwise press ...n:";
        cin>>ch;
        }
    }
    void markTaskAsCompeleted(int &noTask){
        int taskNo;
        char ch ='y';
        while(ch=='y'){
        cout<<"-----------------------------------------------\n";
        cout<<"\nThe Number of task Available is:  "<<noTask<<endl;
        cout<<"\nYou want to Compelete any task between (1 to "<<noTask+1<<" )\n";
        cout<<"\nSpecify the task number to compelete the task from your list:";
        cin>>taskNo;
        temp = head;
        if(temp == nullptr){
            cout<<"The list is Empty...";
        }
        else{
        i=1;
        while(i<taskNo && temp!=nullptr){
            temp = temp->next;
            i++;
        }
        if(temp!=nullptr){
            temp->isCompleted = true;
            cout<<"==============================================\n";
            cout<<"[]Task "<<taskNo<<" "<<"Mark as completed:"<<temp->Task<<endl;
            cout<<"==============================================\n";
        }
        else{
             cout << "Task number " << taskNo << " does not exist.\n";        
        }
    
     }
        cout<<"Do want to compelete any other Task??\npress y otherwise n:";
        cin>>ch;
    }

}
};
class ToDoList : public TaskManager{
    public:
    string name;
    ToDoList(){
        cout<<"----------------------------------------------------\n";
        cout<<"|                                                   |\n";
        cout<<"|      How do you plan to use Todolist ???          |\n";
        cout<<"|      (Available for all)                          |\n";
        cout<<"|                                                   |\n";
        cout<<"|                                                   |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|       |  Personal   []  |                         |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|                                                   |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|       |    Work     []  |                         |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|                                                   |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|       |   Education []  |                         |\n";
        cout<<"|        -----------------                          |\n";
        cout<<"|                                                   |\n";
        cout<<"|                                                   |\n";
        cout<<"----------------------------------------------------\n";
        cout<<"please Enter your name for create Account..:";
        cin>>name;
        cout<<"Congratulations!!.....Your account is created Succesfully\n";
        cout<<"***************************************************\n";
        cout<<"*                                                 *\n";
        cout<<"*   "<< name<<"                                  \t  *\n";
        cout<<"*                                                 *\n";
        cout<<"*   [::]  Upcoming                                *\n";
        cout<<"*   oo   Filter & Labels                          *\n";
        cout<<"*                                                 *\n";
        cout<<"*    My Tasks                          +   ^      *\n";
        cout<<"*                                                 *\n";
        cout<<"*                                                 *\n";
        cout<<"*                                                 *\n";
        cout<<"***************************************************\n";
    }
    void viewYourList(){
        int ch,noTasks=0;
        do{
            cout<<"\n1.Create your New Tasks\n2.Add other Tasks\n";
            cout<<"3.Remove Your Tasks\n4.Mark As Compelete your Task\n";
            cout<<"5.Show All Tasks\n6.Exit"<<endl;
            cout<<"===============================\n";
            cout<<"Choose Your Action:";
            cin>>ch;
            cout<<"===============================\n";
            switch(ch){
                case 1:
                       cout<<"Enter the Number of tasks you want Add:";
                       cin>>noTasks;
                       inputTask(noTasks);
                       break;
                case 2:
                       addTask(noTasks);
                       break;
                case 3:
                       removeTask(noTasks);
                       break;
                case 4:
                       markTaskAsCompeleted(noTasks);
                       break;
                case 5:
                       viewTask();
                       break;
                case 6:
                       exit(0);
                default:
                       cout<<"Invalid Choice:"<<endl;
            }

        }
        while(ch!=6);
    }

};

int main(){
    ToDoList t;
    t.viewYourList();
    
}