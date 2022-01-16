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

int main ()
{
    // variables
    char ans;
    bool breakLoop;

    // body
    do
    {
        system ("cls");

        // arrays
        int tempArray[MAX_ROW][MAX_COL];
        int currentArray[MAX_ROW][MAX_COL];

        //Initialize random seed
        srand(time(NULL));

        // body
        displayMenu();

        setZeroArray(tempArray);

        setInitialPatternArray(tempArray);

        copyArray(tempArray, currentArray);

        displayArray(currentArray);

        // Next Gen Loop
        while (ans != 'p')
        {
            ans = getch();
            if (ans == 'q')
            break;
        }
        if (ans == 'q')
        {
            break;
        }
		while (1)
		{

			if (breakLoop = kbhit() && ans != 'q')
			{
			    system ("cls");
				break;
			}
			else
			{
				system("cls");
				displayMenu();
                setNextGenArray(currentArray, tempArray);
                copyArray(currentArray, tempArray);
                displayArray(currentArray);
                Sleep(1000);
            }
		}
		ans = getch();
    }
    while (ans != 'q');

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
            // corners, rows, and columns
            if ((row == 0 || row == 29) || (col == 0 || col == 59))
            {
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
                        sourceArray[row][col] = 1;
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // top right corner live cell
                else if (currentArray[row][col] == 1 && (row == 0 && col == 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // top right corner dead cell
                else if (currentArray[row][col] == 0 && (row == 0 && col == 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom right corner live cell
                else if (currentArray[row][col] == 1 && (row == 29 && col == 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom right corner dead cell
                else if (currentArray[row][col] == 0 && (row == 29 && col == 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom left corner live cell
                else if (currentArray[row][col] == 1 && (row == 29 && col == 0))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom left corner dead cell
                else if (currentArray[row][col] == 0 && (row == 29 && col == 0))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // top row live cell
                else if ((currentArray[row][col] == 1 && row == 0) && (col != 0 && col != 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // top row dead cell
                else if ((currentArray[row][col] == 0 && row == 0) && (col != 0 && col != 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // right column live cell
                else if ((currentArray[row][col] == 1 && col == 59) && (row != 0 && row != 29))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // right column dead cell
                else if ((currentArray[row][col] == 0 && col == 59) && (row != 0 && row != 29))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom row live cell
                else if ((currentArray[row][col] == 1 && row == 29) && (col != 0 && col != 59))
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
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // bottom row dead cell
                else if ((currentArray[row][col] == 0 && row == 29) && (col != 0 && col != 59))
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // left column live cell
                else if (currentArray[row][col] == 1 && col == 0)
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // left column dead cell
                else if (currentArray[row][col] == 0 && col == 0)
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
            }
            // inner matrix cells
            else
            {
                // 30/60 > live cell > 0
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
                        sourceArray[row][col] = 1;
                    }
                    else
                    {
                        sourceArray[row][col] = 0;
                    }
                }
                // 30/60 > dead cell > 0
                else if (currentArray[row][col] == 0)
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
                        sourceArray[row][col] = 1;
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
