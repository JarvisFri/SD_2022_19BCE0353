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
