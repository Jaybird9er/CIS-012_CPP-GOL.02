#include <iostream>
#include <conio.h> //kbhit()
#include <windows.h>  //Sleep()

using namespace std;

int main()
{
	char ans;
	bool t;
	char test;
	cout << "Enter 'P'" << endl;
	cin >> test;

	test = static_cast<char>(toupper(ans));
    while (test != 'P' )
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

	while (test != 'p')
    {
        cin >> test;
    }
	do
	{
		int i = 0;
		while (1)
		{
			if (t = kbhit())
			{
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


