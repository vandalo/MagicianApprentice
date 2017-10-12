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
	void GameLoop();

private:
	string Introduction();
private:

	int i = 0;
	list<Entity*> entities;
	Player* player = nullptr;
	clock_t timer;
};

#endif 