/***************************************************************************************************
* SceneGraph.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* SceneGraph function
*
* Placeholder.
***************************************************************************************************/
SceneGraph::SceneGraph( void )
{
	this->camera =  new Camera();
	this->light = new Light();
	this->actors.push_back( ActorFactory::makeCube() );
	//this->actors.push_back( ActorFactory::makePlane() );
	int max = 9;
	for ( int i = 0; i < max; i++ ) 
	{
		for ( int j = 0; j < max; j++ )
		{
			this->actors.push_back( ActorFactory::makeTile() );
			
			if ( ( i + j ) % 2 == 0 )
			{
				this->actors[ 1 + i * max + j ]->material->diffuseColor = glm::vec3( 1.0f, 1.0f, 1.0f );
			}
			else
			{
				this->actors[ 1 + i * max + j ]->material->diffuseColor = glm::vec3( 0.2f, 0.2f, 0.2f );
			}			
			
			this->actors[ 1 + i * max + j ]->transform->translate(glm::vec3(i - max / 2, -1.0f, j - max / 2));
		}
	}
}

/***************************************************************************************************
* ~SceneGraph function
*
* Placeholder.
***************************************************************************************************/
SceneGraph::~SceneGraph( void )
{
	delete this->camera;
	delete this->light;
	//for (int i = 0; i < this->actors.size(); i++) {
		//delete this->actors[i];
	//}
	this->actors.clear();
}