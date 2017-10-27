#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <list>
#include <time.h>

using namespace std;

class Entity;
class Player;

class World
{
public:

	World();
	~World();

	bool Init();
	bool ReadComand(vector<string>& args);
	bool ParseCommand(vector<string>& args);
	bool GameLoop();
	bool PlayerIsAlive();
	void CreateBookpage3();
	void CreateKey1();
	void CreateSecretExit();
	bool Win();

private:
	string Introduction();
private:

	int i = 0;
	list<Entity*> entities;
	Player* player = nullptr;
	clock_t timer;
};

#endif 