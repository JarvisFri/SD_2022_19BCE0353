#include <iostream>
#include <vector>

using namespace std;


void initializeBoard(vector<vector<string>> &Board){
    // initialize player A
    cout<<"Enter players of A in order (left to right) : \n";
    int i = 0;
    string temp = "";
    while(i < 5){
        cin>>temp;
        Board[4][i] = "A-"+temp;
        i++;
    }

    // initialize player B
    cout<<"Enter players of B in order (left to right) : \n";
    i = 0;
    while(i < 5){
        cin>> temp;
        Board[0][i] = "B-"+temp;
        i++;
    }

}










void makeMove(vector<vector<string>> &Board, char P, int &cA, int &cB){

    bool flag = true;
    int nextX=0, nextY=0;
    int i, j;
    char piece, direction;

    while(flag){
        // take input of piece and direction
        cout<<"Enter piece name and move name : ";
        string temp = "";
        cin>>temp;

        piece = temp[1];
        direction = temp[3];

        // check validity of move
        bool isValid = checkValidity(Board, piece, direction, P, nextX, nextY, i, j);
        if(!isValid){
            cout<<"Please make a valid move : "<<endl;
        }else flag = false;
    }


    // make move
    Board[i][j] = "-";
    if(Board[i][j] != "-"){
        P == 'A' ? cB-- : cA--;
    }
    cout<<"\n"<<nextX<<" "<<nextY<<"\n";

    string newValue = "";
    newValue += P;
    newValue += "-P";
    newValue += piece;

    Board[nextX][nextY] = newValue;
    cout<<Board[nextX][nextY]<<"\n\n";
    return;
}

void displayBoard(vector<vector<string>> &Board){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout<<Board[i][j]<<"  ";
        }
        cout<<endl;
    }
    return;
}


int main(){
    // declaration of board
    vector<vector<string>> Board(5, vector<string>(5, "-"));

    // initialization of chess
    initializeBoard(Board);
    displayBoard(Board);
    int cA = 5, cB = 5;

    char chance = 'A';
    bool gameFinished = false;

    while(cA and cB){

        if(chance == 'A'){
            cout<<"\n\nA player chance : ";
            makeMove(Board, 'A', cA, cB);
            chance = 'B';
        }else{
            cout<<"\n\nB player chance : ";
            makeMove(Board, 'B', cA, cB);
            chance = 'A';
        }

        displayBoard(Board);
    }

    cA == 0 ?
        cout<<"Player B wins !!! " :
        cout<<"Player A wins !!! " ;

    return 0;
}
