/***************************************************************************************************
* Main.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* main function
*
* Placeholder.
***************************************************************************************************/
int main( void )
{
	Global::resourceManager = new ResourceManager();
	Global::resourceManager->loadConfig( "Config.txt" );
	
	/* Create and initialize the window */
	Global::window = new Window();
	if ( Global::window->initialize( 1024, 768, "FOUNDRY" ) )
	{
		std::cerr << "Failed to initialize the window." << std::endl;
		return -1;
	}

	Global::renderer = new Renderer();
	Global::resourceManager->loadMesh( "C:\\Users\\Ryan\\Game Tests\\Cube.obj" );
	Global::resourceManager->loadMesh( "C:\\Users\\Ryan\\Game Tests\\RoundedCube.obj" );
	Global::resourceManager->loadMesh( "C:\\Users\\Ryan\\Game Tests\\Tile.obj" );
	Global::resourceManager->loadMesh( "C:\\Users\\Ryan\\Game Tests\\SphereSmall.obj" );
	Global::sceneGraph = new SceneGraph();
	Global::renderer->initialize();

    /* Loop until the user closes the window */
    while ( Global::window->active() )
    {		
		Global::sceneGraph->actors[0]->controller->update();

		glm::vec3 ray = cameraToCursorRay(Global::sceneGraph->camera);

		Global::sceneGraph->actors[0]->obbCollider->center = Global::sceneGraph->actors[0]->transform->getPosition();
		Global::sceneGraph->actors[0]->obbCollider->orientation = glm::mat3(Global::sceneGraph->actors[0]->transform->model);
		if (rayOBBIntersection(Global::sceneGraph->camera->camPos, ray, Global::sceneGraph->actors[0]->obbCollider)) {
			// Assign the value for the diffuse color of the model
			Global::sceneGraph->actors[0]->material->diffuseColor = glm::vec3(1.0f, 0.0f, 0.5f);
		}
		else {
			// Assign the value for the diffuse color of the model
			Global::sceneGraph->actors[0]->material->diffuseColor = glm::vec3(0.0f, 0.5f, 1.0f);
		}

		for (unsigned int i = 1; i < Global::sceneGraph->actors.size(); i++) {
			Global::sceneGraph->actors[i]->obbCollider->center = Global::sceneGraph->actors[i]->transform->getPosition() + glm::vec3(0, 0.45f, 0);
			if (rayOBBIntersection(Global::sceneGraph->actors[0]->obbCollider->center, glm::vec3(0, -1, 0), Global::sceneGraph->actors[i]->obbCollider)) {
				// Assign the value for the diffuse color of the model
				Global::sceneGraph->actors[i]->material->diffuseColor = glm::vec3(1.0f, 0.5f, 0.0f);
			}
		}
		
		Global::renderer->draw();
    }

	delete Global::sceneGraph;
	delete Global::renderer;
	delete Global::window;
	delete Global::resourceManager;
	return 0;
}