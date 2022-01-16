#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

// global variables
const int MAX_ROW = 30;
const int MAX_COL = 60;

// function prototypes
void displayMenu(void);
void setZeroArray(int setZero[MAX_ROW][MAX_COL]);
void setInitialPatternArray(int setPattern[MAX_ROW][MAX_COL]);
void displayArray(int displayArray[MAX_ROW][MAX_COL]);
void copyArray(int sourceArray[MAX_ROW][MAX_COL], int copyArray[MAX_ROW][MAX_COL]);
void setNextGenArray(int sourceArray[MAX_ROW][MAX_COL], int currentArray[MAX_ROW][MAX_COL]);
void restartInput(char & ans, bool & restart);

int main ()
{
// restart beginning
    bool restart = true;
    while (restart == true)
    {
        system ("cls");

        // variables
        bool breakLoop;
        char ans;
        int tempArray[MAX_ROW][MAX_COL];
        int currentArray[MAX_ROW][MAX_COL];
        int testArray[MAX_ROW][MAX_COL];

        //Initialize random seed
        srand(time(NULL));

        // body
        displayMenu();

        setZeroArray(tempArray);

        setInitialPatternArray(tempArray);

        copyArray(tempArray, currentArray);

        // 1
        displayArray(currentArray);

        // 2
        setNextGenArray(tempArray, currentArray);
        copyArray(tempArray, currentArray);
        cout << endl;
        displayArray(currentArray);


        // restart program
        restartInput(ans, restart);

    }
    return 0;
}

// functions
// display menu function
void displayMenu(void)
{
    cout << '[' << "P" << ']' << "lay " << static_cast<char>(150) << " Press 'P' to play." << endl;
    cout << '[' << "Q" << ']' << "uit " << static_cast<char>(150) << " Press 'Q' to exit." << endl;
}

// initialize and set array to 0
void setZeroArray(int setZero[MAX_ROW][MAX_COL])
{
    // body
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            setZero[row][col] = 0;
        }
    }
}

// set array pattern
void setInitialPatternArray(int setPattern[MAX_ROW][MAX_COL])
{
    // variables
    int rowRand = (rand() % 25);
    int colRand = (rand() % 54);

    // body
    for (int row = rowRand; row < 6 + rowRand; row++)
    {
        // body
        for (int col = colRand; col < 7 + colRand; col++)
        {
            if (row < 5 + rowRand && col == colRand)
            {
                setPattern[row][col] = 1;
            }
            else if (row < 5 + rowRand && col == 6 + colRand)
            {
                setPattern[row][col] = 1;
            }
            else if (row == 5 + rowRand)
            {
                setPattern[row][col] = 1;
            }
            else
            {
                setPattern[row][col] = 0;
            }
        }
    }
}

// print function
void displayArray(int displayArray[MAX_ROW][MAX_COL])
{
    // body
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            cout << displayArray[row][col];
            if ((col + 1) % MAX_COL == 0)
            {
                cout << endl;
            }
        }
    }
}

// copy array function
void copyArray(int sourceArray[MAX_ROW][MAX_COL], int copyArray[MAX_ROW][MAX_COL])
{
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            copyArray[row][col] = sourceArray[row][col];
        }
    }
}

// set next generation array function
void setNextGenArray(int sourceArray[MAX_ROW][MAX_COL], int currentArray[MAX_ROW][MAX_COL])
{
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            int sum = 0;
            // top left corner live cell
            if (currentArray[row][col] == 1 && (row == 0 && col == 0))
            {
                for (int nRow = row; nRow < row + 1; nRow++)
                {
                    for (int nCol = col; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                sum--;
                if (sum == 2 || sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // top left corner dead cell
            else if (currentArray[row][col] == 0 && (row == 0 && col == 0))
            {
                for (int nRow = row; nRow < row + 1; nRow++)
                {
                    for (int nCol = col; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                if (sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // top right corner live cell
            else if (currentArray[row][col] == 1 && (row == 0 && col == 60))
            {
                for (int nRow = row; nRow < row + 1; nRow++)
                {
                    for (int nCol = col - 1; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                sum--;
                if (sum == 2 || sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // top right corner dead cell
            else if (currentArray[row][col] == 0 && (row == 0 && col == 60))
            {
                for (int nRow = row; nRow < row + 1; nRow++)
                {
                    for (int nCol = col - 1; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                if (sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // bottom right corner live cell
            else if (currentArray[row][col] == 1 && (row == 30 && col == 60))
            {
                for (int nRow = row - 1; nRow < row + 1; nRow++)
                {
                    for (int nCol = col - 1; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                sum--;
                if (sum == 2 || sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // bottom right corner dead cell
            else if (currentArray[row][col] == 0 && (row == 30 && col == 60))
            {
                for (int nRow = row - 1; nRow < row + 1; nRow++)
                {
                    for (int nCol = col - 1; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                if (sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // bottom left corner live cell
            else if (currentArray[row][col] == 1 && (row == 30 && col == 0))
            {
                for (int nRow = row - 1; nRow < row + 1; nRow++)
                {
                    for (int nCol = col; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                sum--;
                if (sum == 2 || sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // bottom left corner dead cell
            else if (currentArray[row][col] == 0 && (row == 30 && col == 0))
            {
                for (int nRow = row - 1; nRow < row + 1; nRow++)
                {
                    for (int nCol = col; nCol < col + 1; nCol++)
                    {
                        if (currentArray[nRow][nCol] == 1)
                        {
                            sum++;
                        }
                    }
                }
                if (sum == 3)
                {
                    sourceArray[row][col] = 7;
                }
                else
                {
                    sourceArray[row][col] = 0;
                }
            }
            // top and bottom row live cell
            else if (currentArray[row][col] == 1 && (row == 0 || row == 30))
            {
                // top row live cell
                if (row == 0)
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                else
                {
                    // bottom row live cell
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
            }
            // top and bottom row dead cell
            else if (currentArray[row][col] == 0 && (row == 0 || row == 30))
            {
                // top row dead cell
                if (row == 0)
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom row dead cell
                else
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }

                }
            }
            // left and right column live cell
            else if (currentArray[row][col] == 1 && (col == 0 || col == 60))
            {
                // left column live cell
                if (col == 0)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // right column live cell
                else
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
            }
            // left and right column dead cell
            else if (currentArray[row][col] == 0 && (col == 0 || col == 60))
            {
                // left column
                if (col == 0)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // right column
                else
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
            }
            // 30 > cells > 0
            else if ((row != 0 && row != 30) && (col != 0 && col != 60))
            {
                // 30 > live cells > 0
                if (currentArray[row][col] == 1)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // 30 > dead cell > 0
                else
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 7;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
            }
        }
    }
}

// restart function
void restartInput(char & ans, bool & restart)
{
    // body
    cout << ">>";
    cin >> ans;
    ans = static_cast<char>(toupper(ans));
    while (ans != 'P' && ans != 'Q')
    {
        cout << "Invalid input. Please try again." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> ans;
        ans = static_cast<char>(toupper(ans));
    }
    if (ans == 'P')
    {
        restart = true;
    }
    else
    {
        restart = false;
    }
}
