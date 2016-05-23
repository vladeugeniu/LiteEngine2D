#include "Game.h"
#include "GameEngine.h"
#include "CollisionSystem.h"
CollisionSystem* CollisionSystem:: _system(new CollisionSystem) ;

int main (int argc, char** argv)
{
	GameEngine::Init ();

	Game::Instance ()->Start ();

	GameEngine::Quit ();
}
