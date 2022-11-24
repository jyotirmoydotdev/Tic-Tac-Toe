#include<iostream>
using namespace std;
void display(auto space[3][3]){
    system("clear");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<space[i][j];
            if (j!=2){
                cout<<"|";
            }
        }
        cout<<endl;
        if (i!=2){
            cout<<"-+-+-"<<endl;
        }
    }
}
bool Tcheck(char space[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if ((space[i][j]!='x')&&(space[i][j]!='o')){
                return true;
            }
        }
    }
    return false;
}
void input(int input,int p,auto* space){
    char tokenx='X';
    char tokeno='O';
    if (p==0){
        switch(input)
        {
        case 1:
            space[0][0]=tokenx;
            break;
        case 2:
            space[0][1]=tokenx;
            break;
        case 3:
            space[0][2]=tokenx;
            break;
        case 4:
            space[1][0]=tokenx;
            break;
        case 5:
            space[1][1]=tokenx;
            break;
        case 6:
            space[1][2]=tokenx;
            break;
        case 7:
            space[2][0]=tokenx;
            break;
        case 8:
            space[2][1]=tokenx;
            break;
        case 9:
            space[2][2]=tokenx;
            break;

        default:
            break;
        }
    }
    else if(p==1){
        switch(input)
        {
        case 1:
            space[0][0]=tokeno;
            break;
        case 2:
            space[0][1]=tokeno;
            break;
        case 3:
            space[0][2]=tokeno;
            break;
        case 4:
            space[1][0]=tokeno;
            break;
        case 5:
            space[1][1]=tokeno;
            break;
        case 6:
            space[1][2]=tokeno;
            break;
        case 7:
            space[2][0]=tokeno;
            break;
        case 8:
            space[2][1]=tokeno;
            break;
        case 9:
            space[2][2]=tokeno;
            break;

        default:
            break;
        }
    }
}
bool valid(int input,int fill[9]){
    for (int i=0;i<9;i++){
        if(fill[i]==input){
            return false;
        }
    }
    for (int i=1;i<10;i++){
        if (input==i){
            return true;
        }
    }
    return false;
}
// only for debugging
void printarr(auto arr[9]){
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool Hcheck(auto space[3][3],char p){
    for (int i=0;i<3;i++){
        int ans=0;
        for (int j=0;j<3;j++){
            if (space[i][j]==p){
                ans++;
            }
        }
        if (ans==3){
            return true;
        }
        else{
            ans=0;
        }
    }
    return false;
}
bool Vcheck(auto space[3][3],char p){
    for (int i=0;i<3;i++){
        int ans=0;
        for (int j=0;j<3;j++){
            if (space[j][i]==p){
                ans++;
            }
        }
        if (ans==3){
            return true;
        }
        else{
            ans=0;
        }
    }
    return false;
}
bool Dcheck(auto space[3][3],char p){
    int ans=0;
    for (int i=0;i<3;i++){
        if (space[i][i]==p){
            ans++;
        }
    }
    if (ans==3){
        return true;
    }
    else{ans=0;}
    for (int i=0,j=2;i<3,j>-1;i++,j--){
        if (space[i][j]==p){
            ans++;
        }
    }
    if (ans==3){
        return true;
    }
    else{
        return false;
    }
}
int checkwin(auto space[3][3]){
    char player1='X';
    bool h=Hcheck(space,player1);
    bool v=Vcheck(space,player1);
    bool d=Dcheck(space,player1);
    if (h||v||d){
        return 0;
    }
    char player2='O';
    bool h2=Hcheck(space,player2);
    bool v2=Vcheck(space,player2);
    bool d2=Dcheck(space,player2);
    if (h2||v2||d2){
        return 1;
    }

    return -1;
}
// Main Function
int main(){
    char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    cout<<"----- --- ---"<<endl;
    cout<<"  |    |  |"<<endl;
    display(space);
    cout<<"[Note: Enter the number where you want to put X/O]"<<endl;
    // Input of the players name
    string player[2];
    cout<<" Enter player 1 first name: ";
    cin>>player[0];
    cout<<" Enter Player 2 first name: ";
    cin>>player[1];

    // To check if the input is duplicate
    int fill[9]={0,0,0,0,0,0,0,0,0};
    int ih=0;

    //Loop will only run for 9 times if their is any 
    //invalid input it will increase the the turn by i+1
    for (int i=2;i<=10;i++){
        int p=i%2;
        int Input;
        cout<<"-> "<<player[p]<<" enter ";
        if (p==0){
            cout<<"X = ";
        }
        else{
            cout<<"O = ";
        }
        cin>>Input;
        if (valid(Input,fill)){
            // Every succesfull input enter in the fill array
            fill[ih]=Input;ih++;
            //input function changes the char in the 3 dim array
            input(Input,p,space);
        }
        else{
            cout<<"Enter a Valid number!!"<<endl;
            i--;
        }
        display(space);
        int win=-1;
        win=checkwin(space);
        if (win==0){
            cout<<"+---------------------------->"<<endl;
            cout<<"| :-D "<<player[0]<<"(X) win the match"<<endl;
            cout<<"+---------------------------->"<<endl;
            return 0;
        }
        else if(win==1){
            cout<<"+---------------------------->"<<endl;
            cout<<"| :-D "<<player[1]<<"(O) win the match"<<endl;
            cout<<"+---------------------------->"<<endl;
            return 0;
        }
    }
    cout<<"+---------------------------->"<<endl;
    cout<<"| The game is Tie!!"<<endl;
    cout<<"+---------------------------->"<<endl;
}