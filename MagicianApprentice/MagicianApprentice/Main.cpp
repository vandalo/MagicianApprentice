#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Utils.h"
#include "world.h"
using namespace std;


int main() {

	while (1) {
		char key;
		string player_input;
		vector<string> args;
		args.reserve(10);

		cout << "Welcome to Magician Apprentice!\n";
		cout << "----------------\n";
		
		World my_world;
		my_world.Init();

		while (1)
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
				else
					ParseInput(player_input, args);
			}

			if (args.size() > 0 && args[0] == "quit")
				break;

			if (args.size() > 0)
			{
				if (my_world.ReadComand(args) == false)
					cout << "\nSorry, I do not understand your command.\n";

				args.clear();
				player_input = "";
				cout << endl << "> ";
			}
			else {
				my_world.GameLoop();
			}
		}

		cout << "\nThanks for playing, Bye!\n";
		system("pause");
		return 0;
	}
}
