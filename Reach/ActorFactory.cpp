/***************************************************************************************************
* ActorFactory.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* makeCube function
*
* Placeholder.
***************************************************************************************************/
Actor* ActorFactory::makeCube( void )
{	
	Actor* actor = new Actor();
	//actor->mesh = Global::resourceManager->meshes["C:\\Users\\Ryan\\Game Tests\\DragonSmall.obj"];
	actor->mesh = Global::resourceManager->meshes[ "C:\\Users\\Ryan\\Game Tests\\RoundedCube.obj" ];
	actor->material = new Material();
	actor->transform = new Transform();
	actor->controller = new Controller();
	actor->controller->transform = actor->transform;
	actor->obbCollider =  new OBBCollider();
	return actor;
}

/***************************************************************************************************
* makeTile function
*
* Placeholder.
***************************************************************************************************/
Actor* ActorFactory::makeTile(void)
{
	Actor* actor = new Actor();
	actor->mesh = Global::resourceManager->meshes["C:\\Users\\Ryan\\Game Tests\\Tile.obj"];
	actor->material = new Material();
	actor->transform = new Transform();
	actor->obbCollider = new OBBCollider();
	actor->obbCollider->center = glm::vec3(0, 0.45f, 0);
	actor->obbCollider->halfWidths = glm::vec3(0.45f, 0.05f, 0.45f);
	return actor;
}

/***************************************************************************************************
* makeSphere function
*
* Placeholder.
***************************************************************************************************/
Actor* ActorFactory::makeSphere( void )
{	
	Actor* actor = new Actor();
	actor->mesh = Global::resourceManager->meshes[ "C:\\Users\\Ryan\\Game Tests\\SphereSmall.obj" ];
	actor->material = new Material();
	actor->transform = new Transform();
	actor->sphereCollider = new SphereCollider();
	return actor;
}

/***************************************************************************************************
* makePlane function
*
* Placeholder.
***************************************************************************************************/
Actor* ActorFactory::makePlane( void )
{	
	Actor* actor = new Actor();
	actor->mesh = Global::resourceManager->meshes[ "C:\\Users\\Ryan\\Game Tests\\Plane.obj" ];
	actor->material = new Material();
	actor->material->diffuseColor = glm::vec3( 1.0f, 1.0f, 1.0f );
	actor->transform = new Transform();
	return actor;
}

/***************************************************************************************************
* makeDragon function
*
* Placeholder.
***************************************************************************************************/
Actor* ActorFactory::makeDragon( void )
{	
	Actor* actor = new Actor();
	actor->mesh = Global::resourceManager->meshes[ "C:\\Users\\Ryan\\Game Tests\\Dragon.obj" ];
	actor->material = new Material();
	actor->transform = new Transform();
	return actor;
}