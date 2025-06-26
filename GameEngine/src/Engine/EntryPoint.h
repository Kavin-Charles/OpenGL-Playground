#pragma 
#include "Events/Event.h"
extern GameEngine::App* GameEngine::createApp();
int main(int argc, char** argv) {
	GameEngine::Log::Init();
	CORE_ERROR("MY LITTLE ERROR");
	auto app = GameEngine::createApp();
	app->run();
	delete app;
}