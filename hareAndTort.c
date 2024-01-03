#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void moveHare(int hr, int *hPos);
void moveTortoise(int tr, int *tPos);
void printCurrentPositions(const int harePos, const int tortPos);

int main(void) {
  int harePos = 1;    //initialize all variables
  int tortPos = 1;
  int hareRand, tortRand;
  int turns = 1;
  puts("BANG !!!!!");
  puts("AND THEY'RE OFF !!!!!");
  srand(time(NULL));
  while(harePos<70&&tortPos<70&&turns<=100){   //Execute the race  // Modify
    hareRand = (rand()%10)+1;   //Get number for random actions
    tortRand = (rand()%10)+1;

    moveTortoise(tortRand, &tortPos);
    moveHare(hareRand, &harePos);
    printCurrentPositions(harePos,tortPos);

    turns++;
  }
  if(tortPos>=70&&harePos>=70){   //Display final message based on result
    puts("IT WAS A TIE!!");
  }
  else if(tortPos>=70){
    puts("TORTIOSE WINS!!! YAY!!!");
  }
  else if(harePos>=70){
    puts("Hare wins. Yuch.");
  }
  else{
    puts("Turns maximum reached.");
  }
}

void moveTortoise( int tr, int *tPos){
  switch(tr){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: // Fat Plod
      *tPos+=3;
      break;
    case 6:
    case 7:
      if(*tPos<=6){ //Slip
        *tPos=1;     // modified
      }
      else{
        *tPos-=6;
      }
      break;
    case 8:
    case 9:
    case 10: // Slow Plod
      *tPos+=1;
      break;
  }
}
void moveHare( int hr, int *hPos){
  switch(hr){
    case 1:
    case 2:  //Sleep
      break;
    case 3:
    case 4: // Big Hop
      *hPos+=9;
      break;
    case 5:
      if(*hPos<=12){  // Big Slip
        *hPos=1;        // modified
      }
      else{
        *hPos-=12;
      }
      break;
    case 6:
    case 7:
    case 8:  // Small Hop
      *hPos+=1;
      break;
    case 9:
    case 10: // Small
      if(*hPos<=2){
        *hPos=1;
      }
      else{
        *hPos-=2;
      }
      break;
  }
}
void printCurrentPositions( const int harePos, const int tortPos){ // modified
  //Consider all cases for formatting - neither finished(check order), both finished, one finished
  if(harePos>=70&&tortPos>=70){//Both finished
    for(int i=0;i<70;i++){
      printf(" ");
    }
    printf("|OUCH!!!\n");
  }
  else if(harePos<70&&tortPos<70){ //Neither finished
    if(harePos>tortPos){  //Hare is ahead
      for(int i=0;i<tortPos;i++){
        printf(" ");
      }
      printf("T");
      for(int j=tortPos+1;j<harePos;j++){
        printf(" ");
      }
      printf("H");
      for(int k=harePos+1;k<70;k++){
        printf(" ");
      }
      printf("|\n");
    }
    else if(tortPos>harePos){   //Tortiose is ahead
      for(int i=0;i<harePos;i++){
        printf(" ");
      }
      printf("H");
      for(int j=harePos+1;j<tortPos;j++){
        printf(" ");
      }
      printf("T");
      for(int k=tortPos+1;k<70;k++){
        printf(" ");
      }
      printf("|\n");
    }
    else{ //Tied
      for(int i=0;i<tortPos;i++){
        printf(" ");
      }
      printf("OUCH!!!");
      for(int j=tortPos+7;j<70;j++){
        printf(" ");
      }
      printf("|\n");
    }
  }
  else if(harePos>=70&&tortPos<70){ //Hare is finished
    for(int i=0;i<tortPos;i++){
      printf(" ");
    }
    printf("T");
    for(int j=tortPos+1;j<70;j++){
      printf(" ");
    }
    printf("|H\n");
  }
  else if(tortPos>=70&&harePos<70){ //Tortoise is finished
    for(int i=0;i<harePos;i++){
      printf(" ");
    }
    printf("H");
    for(int j=harePos+1;j<70;j++){
      printf(" ");
    }
    printf("|T\n");
  }
}
