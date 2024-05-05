#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class RandomNumber{
   public:
   string player;
   RandomNumber(){
    cout<<"\t\t------------------------------------------------"<<endl;
    cout<<"\t\t^                                               ^"<<endl;
    cout<<"\t\t^                                               ^"<<endl;
    cout<<"\t\t<<<<--WELCOME TO OUR NUMBER GUESSING GAME-->>>>"<<endl;
    cout<<"\t\t^                                               ^"<<endl;
    cout<<"\t\t^                                               ^"<<endl;
    cout<<"\t\tEnter Your name:";
    getline(cin,player);
    cout<<"\t\t------------------------------------------------"<<endl;
    cout<<"\t\tLet's play..."<<player<<endl;
   } 
   void guessingGame(){
      char Quit = 'n';
      int Guess_num;
      srand(time(0));
      while(Quit == 'n'){
      int rand_num = rand()%10 + 1;
      cout<<"\n\t\tPlease Guess any number between (1 to 10):";
      cin>>Guess_num;
      if(Guess_num == rand_num){
         cout<<"\n\t\t<<<<------------------------------------------->>>>"<<endl;
         cout<<"\t\tCongratulations!!! You guess the correct number..."<<Guess_num<<endl;
         cout<<"\t\t"<<player<<" ,You win the game...."<<endl;
         cout<<"\n\t\t<<<<------------------------------------------->>>>"<<endl;
      }
      else if(Guess_num<rand_num){
         cout<<"\n\t\tThe Guess number is too low,try again!! "<<Guess_num<<endl;
      }
      else if(Guess_num>rand_num){
         cout<<"\n\t\tThe Guess number is too high,try again!! "<<Guess_num<<endl;
      }
      else{
         cout<<"\n\t\tplease Enter number between (1 to 10): "<<Guess_num<<endl;
      }
      cout<<"\n\t\tDo You want to Quit this Game??"<<endl;
      cout<<"\t\tPress.. y otherwise for continue press..n:";
      cin>>Quit;
      }
      cout<<"\n\t\t---------------------------"<<endl;
      cout<<"\t\tGame End Successfully!!"<<endl;
      cout<<"\n\t\t---------------------------"<<endl;
   }
};
int main(){
   RandomNumber r;
   r.guessingGame();
}