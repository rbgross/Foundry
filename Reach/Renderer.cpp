/***************************************************************************************************
* Renderer.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Renderer function
*
* Placeholder.
***************************************************************************************************/
Renderer::Renderer( void )
{
	this->shaders.push_back(ShaderFactory::Flat());
	shaders[0]->Use();
}

/***************************************************************************************************
* ~Renderer function
*
* Placeholder.
***************************************************************************************************/
Renderer::~Renderer( void )
{
	for (int i = 0; i < this->shaders.size(); i++) {
		delete this->shaders[i];
	}
	this->shaders.clear();
}

/***************************************************************************************************
* initialize function
*
* Placeholder.
***************************************************************************************************/
void Renderer::initialize( void )
{
	// Assign the value for the model matrix
	//glUniformMatrix4fv( uniModel, 1, GL_FALSE, glm::value_ptr( this->sceneGraph->actor->transform->model ) );

	// Assign the value for the view matrix
	shaders[0]->SetUniform("view", Global::sceneGraph->camera->view);

	// Assign the value for the projection matrix
	shaders[0]->SetUniform("proj", Global::sceneGraph->camera->proj);

	// Assign the value for the light position in world space
	shaders[0]->SetUniform("lightPosition", Global::sceneGraph->light->lightPos);

	// Assign the value for the diffuse color of the model
	//glUniform3fv( uniDiffCol, 1, glm::value_ptr( this->sceneGraph->actor->material->diffuseColor) );

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
}

/***************************************************************************************************
* draw function
*
* Placeholder.
***************************************************************************************************/
void Renderer::draw( void )
{	
	/* Render here */
	// Clear the screen to black
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	for ( unsigned int i = 0; i < Global::sceneGraph->actors.size(); i++ ) {
		shaders[0]->SetUniform("model", Global::sceneGraph->actors[i]->transform->model );
		
		// Assign the value for the diffuse color of the model
		shaders[0]->SetUniform("diffuseColor", Global::sceneGraph->actors[i]->material->diffuseColor);

		// Bind this vertex array
		glBindVertexArray( Global::sceneGraph->actors[i]->mesh->vao );

		// Draw the mesh
		glDrawElements( GL_TRIANGLES, Global::sceneGraph->actors[i]->mesh->elements.size(), GL_UNSIGNED_INT, Global::sceneGraph->actors[i]->mesh->elements.data() );
		
	}

	Global::window->swapBuffers();
}