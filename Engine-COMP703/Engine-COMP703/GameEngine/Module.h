/*
 *  File: Module.h
 *  Author: Alex Emeny
 *  Date: December 6th, 2024 (Last Edited)
 *  Description: This file contains the Module struct,
 *               It defines functions for adding and calling on Entites.
 *               This struct handles storing and managing it's Entities.
 * 
 *               MODULE can be seen as a modified version on Unity's "Scene" system.
 *               This allows mass loading or unloading of areas of entities. 
 *               It can allow multiple loaded Modules at once with relative positions.
 */

#pragma once
#include "Entity.h"

namespace GameEngine
{
	struct Core;

	struct Module
	{
		/* Basic constructor that passes a pointer to the engines core */
		Module();

		/* Creates a new Entity, adds them to the modules vector and returns for user use */
		std::shared_ptr<Entity> addEntity();

		/* Loops through all Entities and calls tick on them */
		void tick();

		/* Loops through all Entities and calls render on them */
		void render();

		/* Loops through all Entities and calls GUI on them to render */
		void GUIRender();

		/* Loads and Unloads the entities within this module */
		void load(); /// Currently not in use
		void unload(); /// Currently not in use

		void setRelativePosition(glm::vec3 _newPos) { m_relativePosition = _newPos; }
		glm::vec3 getRelativePosition() { return m_relativePosition; }

	private:
		friend Core;

		/* Relative position of the module of entities so they can be loaded ahead of time within the same world at different locations */
		glm::vec3 m_relativePosition;

		/* Vector of game entities which handle all their relevant components */
		std::vector<std::shared_ptr<Entity>> m_entities;

		/* Weak reference to core to call for any required functions e.g. deltatime */
		std::weak_ptr<Core> m_corePtr;

		/* Weak reference to its self to pass to its entities */
		std::weak_ptr<Module> m_self;
	};
}