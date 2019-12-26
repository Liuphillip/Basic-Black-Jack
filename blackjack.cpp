/* Basic black jack. No doubledowns, splits, or insurance.
Total time: 4 hours
By: Phillip Liu*/
#include <iostream>
#include <time.h>
#include "deck.hpp"
  using namespace std;

void playgame(){
  int playercash = 100;
  int turn=2;
  int dealersum;
  int playersum;
  char playchoice;
  int randcard;
  int round=1;
  int turnswitch;
  int playerhand[10]={};
  int dealerhand[10]={};
  bool playerwon;
  int bet=0;
  deck theDeck;


  while(playercash > 0){

      if(turn==1){
        round=1;
        dealersum=0;
        //srand(time(0));
        while(dealersum<22){
          if(dealersum==21){
            cout<<"Dealer wins\n";
            playercash-=bet;
            turnswitch=2;
          }

          randcard = theDeck.getCard();
          while(randcard==0){
            randcard = theDeck.getCard();
          }
          dealersum+=randcard;
          dealerhand[round-1]=randcard;
          cout<<"Dealer hand: ";
          for(int i=0;i<round;i++){
            cout<<dealerhand[i]<<" ";
          }
          cout<<"\n";
          if(dealersum>playersum && dealersum<22){
            cout<<"Dealer wins.\n";
            playercash-=bet;
            break;
          }
          if(dealersum>21){
            cout<<"Dealer busts.\n";
            playercash+=bet;
          }
          round+=1;
        }
        turn=2;
      }
      else if (turn==2){
        round=1;
        playersum=0;
        cout<<"Cash: "<<playercash<<endl;
        cout<<"Place bet: ";
        cin>>bet;
        cout<<"\n";
        do{
          if(playersum==21){
            cout<<"Player wins.";
            playerwon=true;
            break;
          }
          cout<<"Hit or stay? (h/s): ";
          cin >> playchoice;
          cout<<"\n";
          if(playchoice=='h'){
            //srand(time(0));
            randcard = theDeck.getCard();
            while(randcard==0){
              randcard = theDeck.getCard();
            }
            playersum+=randcard;
            cout<<"Player sum: "<<playersum<<endl;

            playerhand[round-1]=randcard;
            cout<<"Your hand: ";
            for(int i=0;i<round;i++){
              cout<<playerhand[i]<<" ";
            }
            cout<<"\n";
          }
          else{
            turn=1;
            break;
          }
          round+=1;
        }while(playersum<22);
        if(playerwon){
          turnswitch=2;
          playercash+=bet;
        }
        else if(playersum>21){
          cout<<"Bust.\n";
          turnswitch=2;
          playercash-=bet;
        }
        else if(playchoice=='s'){
          turnswitch=1;
        }
        else{
          turnswitch=1;
        }
        turn=turnswitch;
      }


  }
  cout<<"Game over.";
}

int main(){
  playgame();
  return 0;
}
