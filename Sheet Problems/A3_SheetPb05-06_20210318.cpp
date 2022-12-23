#include<bits/stdc++.h>
using namespace std;
#define HUMAN 1
#define COMPUTER 0
class Player{
    
        string name;
        int score=0;
    public:
        Player(string name){
            this->name=name;
        }
        int getscore(){return this->score;}
       void incscore(){++score;}
       string getname(){return this->name;}



};
class Board{
        int size;
        char** arr;
    public:
    Board(int size){
        this->size=size;
        arr=new char*[size];
        for (int i = 0; i < size; i++)
        {
            arr[i]=new char[size];
        }
        for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            arr[i][j]='.';
        }
    
        arr[0][0] = '#';
        arr[0][size-1] = '#';
        arr[size-1][0] = '#';
        arr[size-1][size-1] = '#';
        for (size_t i = 1; i < size-1; i++)
    {
        arr[0][i] = 'v';
    }
    for (size_t i = 1; i < size-1; i++)
    {
        arr[i][0]= '>';
    }
        
    }
    }
    char** getarr(){return this->arr;}
    int getsize(){return this->size;}
    void print(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool update_board(int a,int b){
            if(arr[a][b] == 'v'){ // check lw hya mn ale fo2
                if(arr[a+1][b] == '.'){ // check lw ale t7tha fady
                    arr[a+1][b] = 'v';
                    arr[a][b] = '.';
                    print();
                    return true;
                }
                else{
                    if(arr[a+2][b] == '.'){ // check lw i+1 msh fady bs i+2 fady
                        arr[a+2][b] = 'v';
                        arr[a][b] = '.';
                        print();
                        return true;
                    }
                    else{
                        cout << "Invalid move.";
                        return false;
                    }
                }
            }
            else if(arr[a][b] == '>'){ // check lw hya mn ale t7t
                if(arr[a][b+1] == '.'){ // check lw ale gmbha fady
                    arr[a][b+1] = '>';
                    arr[a][b] = '.';
                    print();
                    return true;

                    
                }
                else{
                    if(arr[a][b+2] == '.'){ // check lw j+1 msh fady bs j+2 fady
                        arr[a][b+2] = '>';
                        arr[a][b] = '.';
                        print();
                        return true;
                    }
                    else{
                        cout << "Invalid move.";
                        return false;  
                    }
                }
            }
            else{
                return false;
            }
    }

bool iswinner(){
    int counter1=0;
    int counter2=0;
        for (size_t i = 1; i < size-1; i++)
    {
        if(arr[size-1][i] == 'v' ){
            
            counter1++;
        }
        
    }
        for (size_t i = 1; i < size-1; i++)
    {
        if(arr[i][size-1] == '>' ){
            
            counter2++;
        }
        
    }
    if(counter1==size-2){
        return true;
    }
    else if(counter2==size-2){
        return true;
    }
    else{
        return false;
    }
    
}

};
struct Move{
    int row;
    int col;
};
int evaluatefunction(Board board){
   int counter1=0;
    int counter2=0;
        for (size_t i = 1; i < board.getsize()-1; i++)
    {
        if(board.getarr()[board.getsize()-1][i] == 'v' ){
            
            counter1++;
        }
        
    }
        for (size_t i = 1; i < board.getsize()-1; i++)
    {
        if(board.getarr()[i][board.getsize()-1] == '>' ){
            
            counter2++;
        }
        
    }
    if(counter1==board.getsize()-2){
        return -10;
    }
    if(counter2==board.getsize()-2){
        return +10;
    }
    
        return 0;
    
}
int minimax(Board board,int depth,bool isMax){
    int score = evaluatefunction(board);
    if(score==10){
        return score;
    }
    if(score ==-10){
        return score;
    }
    if(isMax){
        int best =-1000;
        for(int i=0;i<board.getsize();i++){
            for(int j=0;j<board.getsize();j++){
                if(board.getarr()[i][j]=='.'){
                    board.getarr()[i][j]=='>';
                    best =max(best,minimax(board,depth+1,!isMax));
                    board.getarr()[i][j]=='.';
                }
            }
        }
        return best;
    }
    else{
                int best =1000;
        for(int i=0;i<board.getsize();i++){
            for(int j=0;j<board.getsize();j++){
                if(board.getarr()[i][j]=='.'){
                    board.getarr()[i][j]=='>';
                    best =min(best,minimax(board,depth+1,!isMax));
                    board.getarr()[i][j]=='.';
                }
            }
        }
        return best;
    }
}
Move findbestmove(Board b){
    int bestVal=-1000;
    Move bestMove;
    bestMove.row=-1;
    bestMove.col=-1;
    for(int i=0;i<b.getsize();i++){
        for(int j=0;j<b.getsize();j++){
            if(b.getarr()[i][j]=='.'){
                b.getarr()[i][j]=='>';
                int moveVal=minimax(b,0,false);
                b.getarr()[i][j]=='.';

                if(moveVal>bestVal){
                    bestMove.row=i;
                    bestMove.col=j;
                    bestVal=moveVal;
                }

            }
        }
    }
    return bestMove;
}

class AImanager{
      public:
        void run(){
    cout << "Welcome to Rockets game.\n";
    cout << "Player 1, please enter your name: ";
    string name1;
    int size;
    int a,b;
    cin >> name1;
   
      cout << "enter size of board: ";
    cin >> size;
            Player p1(name1),p2("computer");
            
            Board board(size);
             Move bestMove;
            int turn=HUMAN;
            while (true)
            {
                board.print();
            retake:
                switch (turn) {
                case HUMAN:
             cout<<p1.getname()<<"Please enter the current index of the rocket you want to move: ";
             cin>>a>>b;
                    if(a>=size || b>=size || a<0 || b<0){goto retake;}
                 break;
                 case COMPUTER:
                     bestMove=findbestmove(board);
                     a=bestMove.row;
                     b=bestMove.col;
				cout << "Computer has played."<<endl;
                break;
                }
                    
                    
                    if(!board.update_board(a,b)){
                            goto retake;
                        }
              if(board.iswinner()){
                if(turn==1){
                    cout<<p1.getname()<<" wins!!!";
                }
                else{
                    cout<<p2.getname()<<" wins!!";
                }
                board.print();
                break;
              }
                 turn = turn==1 ? 0 : 1;   
                    
            }
            
        }
};
class Gamemanager{
    public:
        void run(){
    cout << "Welcome to Rockets game.\n";
    cout << "Player 1, please enter your name: ";
    string name1,name2;
    int size;
    int a,b;
    cin >> name1;
   
    cout << "Player 2, please enter your name: ";
    cin >> name2;
      cout << "enter size of board: ";
    cin >> size;
            Player p1(name1),p2(name2);
            
            Board board(size);
            int turn=1;
            while (true)
            {
                board.print();
                retake:
                    if(turn==1){
                        cout<<p1.getname()<<"Please enter the current index of the rocket you want to move: ";
                    }
                    else{
                        cout<<p2.getname()<<"Please enter the current index of the rocket you want to move: ";
                    }
                    cin>>a>>b;
                    if(a>=size || b>=size || a<0 || b<0){goto retake;}
                    
                    if(!board.update_board(a,b)){
                            goto retake;
                        }
              if(board.iswinner()){
                if(turn==1){
                    cout<<p1.getname()<<" wins!!!";
                }
                else{
                    cout<<p2.getname()<<" wins!!";
                }
                board.print();
                break;
              }
                 turn = turn==1 ? 2 : 1;   
                    
            }
            
        }
};
int main(){
    // Gamemanager g1;
    AImanager g1;
    g1.run();
    return 0;



}