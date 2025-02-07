#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

char arr[4][4];

void initialize()
{
    int x = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = x++;
        }
    }
}

void print(void)
{
    cout << endl;
    int x = 1;
    cout << "At inital stage the game board looks like this: \n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i)
            cout << "\t---|---|---" << endl;
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j];
            if (j != 2)
            {
                cout << " |";
            }
        }
        cout << endl;
    }
    // cout<<"\t-------------"<<endl;
    cout << endl;
    cout << "Now according to the place you will have to choose the number....\n"
         << endl;
    cout << "Player 1 will be indicated by   . " << endl;
    cout << "Player 2 will be indicated by   # " << endl;
    cout << "\nLet's play the game...\n"
         << endl;
}

int print(int x)
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i)
            cout << "\t---|---|---" << endl;
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j];
            if (j != 2)
            {
                cout << " |";
            }
        }
        cout << endl;
    }
    cout << endl;
    int flag = 0;

    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
        {
            flag = 1;
        }
        if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
        {
            flag = 1;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
    {
        flag = 1;
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
    {
        flag = 1;
    }
    return flag;
}

int player1(int x)
{
    int vagfol = x / 3;
    int vagsesh = x % 3;
    int y = 10;
    if (arr[vagfol][vagsesh] == '.' || arr[vagfol][vagsesh] == '#' || x < 0 || x > 8)
    {
        cout << endl;
        cout << "Pressed wrong number...Try again...\n"
             << endl;
        int num;
        cout << "Player 1 (.): ";
        cin >> num;
        player1(num - 1);

        //y = 1;
        //return y;
    }
    else
    {
        arr[vagfol][vagsesh] = '.';

        int flag;
        flag = print(1);
        if (flag == 1)
        {
            cout << endl;
            cout << "Congratulations......!    Player 1 wins the game....\n"
                 << endl;
            return y;
        }
    }
    return y + 1;
}
int player2(int x)
{
    int vagfol = x / 3;
    int vagsesh = x % 3;
    int y = 10;
    if (arr[vagfol][vagsesh] == '.' || arr[vagfol][vagsesh] == '#' || x < 0 || x > 8)
    {
        cout << endl;
        cout << "Pressed wrong number...Try again...\n"
             << endl;
        int num;
        cout << "Player 2 (#): ";
        cin >> num;
        player2(num - 1);

        //y = 1;
        //return y;
    }
    else
    {
        arr[vagfol][vagsesh] = '#';
        int flag;
        flag = print(2);
        if (flag == 1)
        {
            cout << endl;
            cout << "Congratulations......!    Player 2 wins the game....\n"
                 << endl;
            return y;
        }
    }
    return y + 1;
}
int N = 9;
void play()
{
    int n = 1;
    char num;
    int check = 1;
    while (n < 10)
    {
        if (n % 2 == 1)
        {
            //while(check==1)
            {
                cout << "player 1 (.): ";
                cin >> num;
                // check = player1(num-1);
                check = player1(num - 1 - '0');
                if (check == 10)
                {
                    return;
                }
            }
        }
        else
        {
            //while(check==1)
            {
                cout << "Player 2 (#): ";
                cin >> num;
                // check = player2(num-1);
                check = player2(num - 1 - '0');
                if (check == 10)
                {
                    return;
                }
            }
        }
        n++;
    }
    if (n == 10)
    {
        cout << endl;
        cout << "The match is draw.....\n"
             << endl;
    }
}
int main()
{
    cout << endl
         << "     ------ WELCOME TO MY KATAKUTI GAME -------" << endl;
    cout << endl;
    cout << "*********************************************************" << endl;
    int i = 1;
    while (i)
    {
        initialize();
        print();
        play();
        cout << "*********************************************************" << endl;
        cout << "Do you want to play again?\nPress   1 (YES)   or    0 (NO)" << endl;
        cin >> i;
        cout << "*********************************************************" << endl;
        cout << endl
             << endl;
    }

    cout << "     ------ THANKS FOR PLAYING THE GAME -------" << endl
         << endl;
    cout << "                     Selfish29" << endl
         << endl;
    getchar();
    getchar();
    return 0;
}