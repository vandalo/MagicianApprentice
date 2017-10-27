#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Utils.h"
#include "world.h"
#include <windows.h>
#include "Defines.h"

using namespace std;


int main() {
	//Open console with 1024*768
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGTH, TRUE);

	while (1) {
		char key;
		string player_input;
		vector<string> args;
		args.reserve(10);

		cout << "Welcome to Magician Apprentice!\n";
		cout << "-------------------------------\n\n";
		
		World my_world;
		my_world.Init();

		args.push_back("look");

		while (1)
		{
			if (my_world.PlayerIsAlive())
			{
				if (_kbhit() != 0)
				{
					key = _getch();
					if (key == '\b') // backspace
					{
						if (player_input.length() > 0)
						{
							player_input.pop_back();
							cout << '\b';
							cout << " ";
							cout << '\b';
						}
					}
					else if (key != '\r') // return
					{
						player_input += key;
						cout << key;
					}
					else {
						cout << "\n";
						ParseInput(player_input, args);
					}
				}

				if (args.size() > 0 && args[0] == "quit")
					break;

				if (args.size() > 0)
				{
					if (my_world.ReadComand(args) == false)
						cout << "Sorry, I do not understand your command.\n";

					args.clear();
					player_input = "";
					cout << endl << "> ";
				}
				else {
					if (my_world.GameLoop())
					{
						cout << "> " << player_input;
					}
				}
			}
			else
			{
				cout << "\nYou are death!\n";
				break;
			}
		}
		cout << "\nThanks for playing, Bye!\n";
		system("pause");
		return 0;
	}
}
