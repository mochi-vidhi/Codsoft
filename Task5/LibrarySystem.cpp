#include<iostream>
#include<stdlib.h>
using namespace std;
class Books{
    public:
    string *title; 
    string *author; 
    int *ISBN;
    bool *checkout;
    void bookDataBase(int noOfBooks){
        title = new string[noOfBooks];
        author = new string[noOfBooks];
        checkout = new bool[noOfBooks];
        cin.ignore();
        ISBN = new int[noOfBooks];
        for(int i = 0;i<noOfBooks;i++){     
        cout<<"\t\tEnter the title of book"<<i+1<<":"<<endl;
        getline(cin,title[i]);
        cout<<"\t\tEnter the Author name of book"<<i+1<<":"<<endl;
        getline(cin,author[i]);
        cout<<"\t\tEnter ISBN of the book"<<i+1<<":";
        cin>>ISBN[i];
        checkout[i] = false;
        cin.ignore();
        cout<<"\t\t---------------------------\n";
        }
}
void bookSearch(int noOfBooks){
    char opt = 'y';
    int  srh,s_isbn;
    string Query;
     bool found = false;
    while(opt =='y'){
            cout<<"\t\t\n-----------------------------\n";
            cout<<"\t\t1.Search by Title..\n2.Search by Author\n3.Search by ISBN\n";
            cout<<"\t\t\n---------------------------\n";
            cout<<"\t\tHow would you like to search?";
            cin>>srh;
            cin.ignore();
            switch (srh)
            {
            case 1:
                   cout<<"\t\t\nYou Select First Search (Using Title)...";
                   cout<<"\t\t\nEnter the Title of the Book to search:";
                   getline(cin,Query);
                   for(int i = 0;i<noOfBooks;i++){
                   if(title[i]==Query){
                    cout<<"\t\t\nBook found\n";
                    cout<<"\t\t+==========================+\n";
                    cout<<"\t\tTitle:"<<title[i]<<endl;
                    cout<<"\t\tAuthor:"<<author[i]<<endl;
                    cout<<"\t\tISBN:"<<ISBN[i]<<endl;
                    found = true;
                    cout<<"\t\t+==========================+\n";
                   }
                   }
                break;
            case 2:
                   cout<<"\t\t\nYou Select Second Search (Using Author)...";
                   cout<<"\t\t\nEnter the Name of Author for the search Book :";
                   getline(cin,Query);
                   for(int i = 0;i<noOfBooks;i++){
                   if(author[i]==Query){
                    cout<<"\t\t\nBook found\n";
                    cout<<"\t\t+==========================+\n";
                    cout<<"\t\tTitle:"<<title[i]<<endl;
                    cout<<"\t\tAuthor:"<<author[i]<<endl;
                    cout<<"\t\tISBN:"<<ISBN[i]<<endl;
                    found = true;
                    cout<<"\t\t+==========================+\n";
                   }
                } 
                break;
            case 3:
                   cout<<"\t\t\nYou Select Third Search (Using ISBN)...";
                   cout<<"\t\t\nEnter the ISBN for the search Book :";
                   cin>>s_isbn;
                   for(int i = 0;i<noOfBooks;i++){
                   if(ISBN[i]==s_isbn){
                    cout<<"\t\t\nBook found\n";
                    cout<<"\t\t+==========================+\n";
                    cout<<"\t\tTitle:"<<title[i]<<endl;
                    cout<<"\t\tAuthor:"<<author[i]<<endl;
                    cout<<"\t\tISBN:"<<ISBN[i]<<endl;
                    found = true;
                    cout<<"\t\t+==========================+\n";
                   }
                }
                break;
            default:
                 cout<<"\t\t\nYou select Invalid search...\n "<<endl;
                break;
            }
        if(!found){
                cout<<"\t\t\nYour Book is Not found\n";
        }
        cout<<"\t\t\nDo you want to Search any other Books??\n";
        cout<<"\t\tSelect Option y or n:";
        cin>>opt;
        }
}
void fineCalculation(int noOfBooks){
    int days;
    cout<<"\t\tplease Enter Number of days You return books:";
    cin>>days;
    if(days>2){
        cout<<"\t\t\n+ =========================================== +\n";
        cout<<"\t\tYou miss time limit of return of the books!!\n";
        cout<<"\t\tPer day fine is Rs.5"<<endl;
        int fine = (noOfBooks*5)*(days);
        cout<<"\t\t\nYou pay Total fine "<<fine<<" Rs."<<endl;
        cout<<"\t\t\n+ =========================================== +\n";
    }
    else{
        cout<<"\t\t\n+ =========================================== +\n";
        cout<<"\t\t\nCongratulations!! You returned the book within the time limit";
        cout<<"\t\t\n+ =========================================== +\n";
    }

}
void bookReturn(int noOfBooks){
    char opt = 'y';
    int return_Isbn;
    bool found = false;
   
    while(opt=='y'){
        cout<<"\t\tEnter ISBN  of the book for Return Book:";
        cin>>return_Isbn;
        for(int i =0;i<noOfBooks;i++){
            if(ISBN[i]==return_Isbn){
               if(checkout[i]==true){
                 fineCalculation(noOfBooks);
                 cout<<"\t\t\nBook with isbn : "<<return_Isbn<<" has been return succesfully\n";
                 checkout[i] = false;
               }
               else{
                  
                  cout<<"\t\t\nBook with isbn : "<<return_Isbn<<" is already in the library \n";
               }
               found = true;
               break;
            }
        }
        if(!found){
            cout<<"\t\tBook with isbn : "<<return_Isbn<<" Is not in library!!\n";
        }
        cout<<"\t\t\nDo You want to return other book??\n";
        cout<<"\t\tPress y... otherwise n...: ";
        cin>>opt;
    }

}
    
void checkOutBook(int noOfBooks){
    char opt = 'y';
    int check_Isbn;
    bool found = false;
    while(opt=='y'){
        cout<<"\t\tEnter ISBN  of the book for checkOut:";
        cin>>check_Isbn;
        for(int i =0;i<noOfBooks;i++){
            if(ISBN[i]==check_Isbn){
               if(checkout[i]==false){
                 cout<<"\t\t-----------------------------------------------------------"<<endl;
                 cout<<"\t\t\nBook with isbn : "<<check_Isbn<<" has been Checked out succesfully\n";
                 cout<<"\t\t-----------------------------------------------------------"<<endl;
                 checkout[i]= true;
               }
               else{
                  cout<<"\t\t--------------------------------------------------------------"<<endl;
                  cout<<"\t\t\nBook with isbn : "<<check_Isbn<<" is already Checked out \n";
                  cout<<"\t\t--------------------------------------------------------------"<<endl;
               }
               found = true;
               break;
            }
        }
        if(!found){
            cout<<"\t\tBook with isbn : "<<check_Isbn<<" Is not checked out!!\n";
            cout<<"\t\tBook is not Available in library!!!\n";
            cout<<"\t\t--------------------------------------------------"<<endl;
        }
        cout<<"\t\t\nPlease Books Must be Returned within 2 days....\n";
        cout<<"\t\t\nDo You want to checked out other book??\n";
        cout<<"\t\tPress y... otherwise n...: ";
        cin>>opt;
        cout<<"\t\t--------------------------------------------------"<<endl;
        
    }
}

 void display(int noOfBooks){
     for(int i = 0;i<noOfBooks;i++){
        cout<<"\t\t\n==================================="<<endl;
        cout<<"\t\tTitle of book"<<i+1<<":"<<title[i]<<endl; 
        cout<<"\t\tAuthor name of book"<<i+1<<":"<<author[i]<<endl;
        cout<<"\t\tISBN of the book"<<i+1<<":"<<ISBN[i]<<endl;
        if(checkout[i]==true){
            cout<<"\t\t(checked Out)"<<endl;
        }
        else{
            cout<<"\t\t(Unchecked Out)"<<endl;
        }
        cout<<"\t\t================================="<<endl;
        }

 }
 };
class Library:public Books{
    public:
    string profile;
    int ch,noOfBooks;
    Library(){
        cout<<"\t\t================================================"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+   Let's Read & Store                     ^    +"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+                            ----------------   +"<<endl;
        cout<<"\t\t+                           |Create a Profile|  +"<<endl;
        cout<<"\t\t+                            ----------------   +"<<endl;
        cout<<"\t\t+    ----------------                           +"<<endl;
        cout<<"\t\t+    |Search        |                           +"<<endl;
        cout<<"\t\t+    ----------------                           +"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+    Categories                                 +"<<endl;
        cout<<"\t\t+                                               +"<<endl;
        cout<<"\t\t+    [Science]         [Arts and Music]         +"<<endl;
        cout<<"\t\t+    [Health]          [Critical Thinking]      +"<<endl;
        cout<<"\t\t+    [Problem Solving] [subject Releted]        +"<<endl;
        cout<<"\t\t================================================"<<endl;
        cout<<"\t\tplease Create Your profile:";
        cin>>profile;
        cout<<endl;
        cout<<"\t\t***************************************"<<endl;
        cout<<"\t\t*                                     *"<<endl;
        cout<<"\t\t* "<<profile<<"                   \t      *"<<endl;
        cout<<"\t\t*                                     *"<<endl;
        cout<<"\t\t*  ----------------                   *"<<endl;
        cout<<"\t\t*  |[Keep Reading]|                   *"<<endl;
        cout<<"\t\t*  ----------------                   *"<<endl;
        cout<<"\t\t*                                     *"<<endl;
        cout<<"\t\t***************************************"<<endl;
        
    }
    void libraryDisplay(){
    do{
        cout<<"\t\t1.Add Book in database:\n\t\t2.displayBook\n\t\t3.Search Books\n";
        cout<<"\t\t4.Checked out\n\t\t5.Return Book\n\t\t6.exit\n";
        cout<<"\t\t===============================\n";
        cout<<"\t\tEnter the choice:";
        cin>>ch;
        cout<<"\t\t===============================\n";
        switch(ch){
            case 1 : 
                    cout<<"\t\tHow many books are you store in database??";
                    cin>>noOfBooks;  
                     bookDataBase(noOfBooks);
                     break;
            case 2:
                     display(noOfBooks);
                     break;
            case 3:
                     bookSearch(noOfBooks);
                     break;
            case 4:
                    checkOutBook(noOfBooks);
                    break;
            case 5:
                    bookReturn(noOfBooks);
                    break;
            case 6:
                     exit(0);
                   
            default:
                   cout<<"\n\t\tInvalid choice:"<<endl;
                   
        }

    }while(ch!=6);

    }

};
int main(){
    Library l;
    l.libraryDisplay();
}