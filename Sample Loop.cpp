#include <iostream>
#include <conio.h> //kbhit()
#include <windows.h>  //Sleep()

using namespace std;

int main()
{
	char ans;
	bool t;

    do
	{
//        if (ans == 'q')
//        {
//            break;
//        }
        while (ans != 'p')
        {
            ans = getch();
            if (ans == 'q')
            break;
        }
        if (ans == 'q')
            break;



        int i = 0;
		while (1)
		{
			if (t = kbhit())
			{
			    system ("cls");
				break;
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

		ans = getch();

	}while (ans != 'q');


	return 0;
}


