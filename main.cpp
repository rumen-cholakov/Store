#include <iostream>
#include <cctype>
#include "Store.h"


using namespace std;

void ShowMenu()
{
    cout << "\n\t\t*** Store ***";
    cout << "\n\tA \tAdd new product";
    cout << "\n\tK \tDelete product";
    cout << "\n\tC \tChange product";
    cout << "\n\tD \tDisplay products";
    cout << "\n\tS \tSave products";
    cout << "\n\tL \tLoad products";
    cout << "\n\tQ \tQuit";
}

char GetAChar(char* promptString)
{
    char response;

    cout << promptString;
    cin >> response;
    response = toupper(response);
    cin.get();
    return response;
}

char Legal(char c)
{
    return	((c == 'A') || (c == 'K') || (c == 'C') || (c == 'D') ||
            (c == 'S') || (c == 'L') || (c == 'E') || (c == 'Q'));
}

char GetCommand()
{
    int stopLoop = 0;
    char cmd = GetAChar("\n\n>");
    while (!Legal(cmd))
    {
        if(stopLoop > 5)
        {
            cin.clear();
            cin.ignore();
            cout << "An error occurred!";
            return cmd = 'Q';
        }
        ++stopLoop;
        cout << "\nIllegal command, please try again . . .";
        ShowMenu();
        cmd = GetAChar("\n\n>");
    }
    return cmd;
}

int main()
{
    Store s;

    ShowMenu();

    char command;
    do
    {
        command = GetCommand();
        switch (command)
        {
            case 'A': s.Insert(); 				break;
            case 'K': s.Remove();				break;
            case 'C': s.Update();				break;
            case 'D': s.DisplayProducts();		break;
            case 'S': s.Save();         	    break;
            case 'L': s.Load();	                break;
            case 'Q': 					        break;
        }
     } while (command != 'Q');

    return 0;
}

