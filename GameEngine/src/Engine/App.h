#pragma once
#include "Events/Event.h"
namespace GameEngine{

	class App
	{
	public:
		App();
		virtual ~App();

		void run();
	};

	App* createApp();

}

