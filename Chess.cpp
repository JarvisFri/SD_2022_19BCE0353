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


vector<int> findPiece(vector<vector<string>> &Board, char piece, char P){
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (Board[i][j][0] == P and Board[i][j][3] == piece)
        return {i, j};

    return {-1, -1};
}

bool inBounds(int x, int y){
    return (x < 5 and y < 5 and x >= 0 and y >= 0);
}

bool checkValidity(vector<vector<string>> &Board, char piece, char direction,
                    char P, int &nextX, int &nextY, int &i, int &j){

    vector<int> pos = findPiece(Board, piece, P);
    i = pos[0], j = pos[1];

    // Piece not present
    if(i==-1 or j==-1){
        cout<<"Piece not present in the board : "<<endl;
        return false;
    }

    nextX = i, nextY = j;

    if(P == 'B'){
        if(direction == 'R') direction = 'L';
        else if(direction == 'L') direction = 'R';
        else if(direction == 'F') direction = 'B';
        else if(direction == 'B') direction = 'F';
     }

    switch(direction){
        case 'R' : nextY++;
                    break;
        case 'L' : nextY--;
                    break;
        case 'F' : nextX--;
                    break;
        case 'B' : nextX++;
                    break;
        default : cout<<"Please input valid direction "<<endl;
                  return false;
    }

    return inBounds(nextX, nextY);

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
