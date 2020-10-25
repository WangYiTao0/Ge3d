#pragma once

#include <entt.hpp>

namespace Ge
{
	class Entity;
	
	class Scene
	{
		Scene();
		~Scene();

	private:
		entt::registry m_Registry;
	};
}