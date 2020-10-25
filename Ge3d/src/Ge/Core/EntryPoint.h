#pragma once

#include <Ge3d.h>

#ifdef GE_PLATFORM_WINDOWS

extern Ge::Application* Ge::CreateApplication();

int main(int argc, char** argv)
{
	Ge::Log::Init();
	GE_CORE_WARN("Initialized Log!");
	GE_INFO("Hello!");

	auto app = Ge::CreateApplication();

	app->Run();

	delete app;
}

#endif // JF_PLATFORM_WINDOWS
