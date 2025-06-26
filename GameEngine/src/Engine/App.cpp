#include "App.h"
#include "Events/AppEvent.h"
#include "Log.h"
GameEngine::App::App() {
	CORE_INFO("This is LOGGER");
}
GameEngine::App::~App() {
	
}

void GameEngine::App::run() {


	CLIENT_INFO("ENtered Run!");
	WindowResizeEvent e(1280, 720);
	if (e.IsInCategory(EventCategoryApplication))
	{
		CLIENT_TRACE(e.ToString());
	}
	if (e.IsInCategory(EventCategoryInput))
	{
		CLIENT_TRACE(e.ToString());
	}

	while (true);
}


