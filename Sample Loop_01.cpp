#include <iostream>
#include <conio.h> //kbhit()
#include <windows.h>  //Sleep()

using namespace std;

int main()
{
	char ans;
	bool t;
	char test;


    do
	{
    do
    {
        test = getch();
//        if (test == 'q')
//        {
//            ans = 'q';
//            break;
//        }
    }
    while (test != 'p');

        int i = 0;
		while (1)
		{
			if (t = kbhit())
			{
				continue;
			}
			else
			{
				system("cls");
				cout << "Hello" << endl;
				cout << i;
				i++;
				Sleep(1000);
			}
		}

	}while (ans != 'q');

	return 0;
}


