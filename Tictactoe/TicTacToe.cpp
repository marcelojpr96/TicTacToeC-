// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void printtable(vector<char>);
bool checkGame(vector<char>, bool);
bool gameloop(bool, bool, vector<char>);

bool isFinished(bool finishedd){
    
    cout << finishedd << "inside is Finished" ;
    return false ;
}

void printtable(vector<char> newVector){
  vector<char>board =newVector;
  int j =0;
  //row
  for (int i = 0 ; i<=4 ; i++){
    //column
      for (int k = 0 ; k<7; k++){
        //este desenha os traços verticais linha sim linha não
        if(i==1 && k==0 || i==1 && k==2 || i==1 && k==4 || i==1 && k==6 
        ||i==2 && k==0 || i==2 && k==2 || i==2 && k==4 || i==2 && k==6
        || i==3 && k==0 || i==3 && k==2 || i==3 && k==4 || i==3 && k==6){
          cout << "|" ;
        }else if(i==0 || i==4){
          //este desenha um traço em cima e um em baixo
          cout << "-" ;
        

        }else{
          
          cout << board[j];
          j++;
          }
      }
      cout << "\n";
  }
    return ;
}

bool checkGame(vector<char> board, bool whoisit){
    bool player = whoisit;
    bool finished;
    if (board[0] == 'x' && board[4] == 'x' && board[8] == 'x' || board[2] == 'x' && board[4] == 'x' && board[6] == 'x' || 
        board[0] == 'x' && board[1] == 'x' && board[2] == 'x' || board[3] == 'x' && board[4] == 'x' && board[5] == 'x'|| board[6] == 'x' && board[7] == 'x' && board[8] == 'x' ||
        board[0] == 'x' && board[3] == 'x' && board[6] == 'x'|| board[1] == 'x' && board[4] == 'x' && board[7] == 'x' || board[2] == 'x' && board[5] == 'x' && board[8] == 'x' ){

        finished = true;
        gameloop(finished, player, board);
        cout << "O jogador X Ganhou";


    }else if (board[0] == 'o' && board[4] == 'o' && board[8] == 'o' || board[2] == 'o' && board[4] == 'o' && board[6] == 'o' || 
        board[0] == 'o' && board[1] == 'o' && board[2] == 'o' || board[3] == 'o' && board[4] == 'o' && board[5] == 'o'|| board[6] == 'o' && board[7] == 'o' && board[8] == 'o' ||
        board[0] == 'o' && board[3] == 'o' && board[6] == 'o'|| board[1] == 'o' && board[4] == 'o' && board[7] == 'o' || board[2] == 'o' && board[5] == 'o' && board[8] == 'o'){

        finished = true;
        gameloop(finished, player, board);
        cout << "O jogador O Ganhou";

    }else{
        finished = false ; 
        gameloop(finished,player,board);
    }
    
    return finished;
}

bool gameloop(bool acabou, bool player, vector<char> board){
  
  int played;
  cout << acabou;
  if(acabou ==false){
    if(player == false){
      do{
        do{
          cout << "onde quer jogar o X " ;
          cin >> played;
          played--;
        }while(played <1 && played > 9);
      }while(board[played] == 'x' || board[played] == 'o');
      board[played] = 'x';
      player = true;
      system("CLS");
      printtable(board); 
      checkGame(board,player);
    }else {
      do{
        do{
          played = 0;
          cout << "onde quer jogar o O " ;
          cin >> played;
          played--;
        }while(played <1 && played > 9);
      }while(board[played] == 'x' || board[played] == 'o');
      board[played] = 'o';
      player = false ;
      system("CLS");
      printtable(board); 
      checkGame(board, player);
    }
    

  }else{
    system("CLS");
    cout << "Acabou \n";
  }

  return acabou;
}

int main() {
  vector<char> board {'1','2','3','4','5','6','7','8','9'};
  
  printtable(board);
  checkGame(board, false);
  /*int number;
  board[1] = 'o';
  board[4] = 'o';
  board[7] = 'o';
  for(int i ; i < board.size(); i++){
  cout << board[i];}*/
  /* This works :
  cout << "choose a number: ";
  cin >> number ; 
  board[number] = 'x';
  for(int i ; i < board.size(); i++){
  cout << board[i];}
  printtable(board); 
  bool F = false;
  bool V = true;
  cout << F; = 0
  cout << V; = 1*/
  
}