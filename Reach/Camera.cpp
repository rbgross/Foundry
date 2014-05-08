/***************************************************************************************************
* Camera.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Camera function
*
* Placeholder.
***************************************************************************************************/
Camera::Camera( void )
{
	// Assign the value for the view matrix
	this->camPos = glm::vec3( 10.0f, 10.0f, 10.0f );
	this->lookAt = glm::vec3( 0.0f, 0.0f, 0.0f );
	this->upDir = glm::vec3( 0.0f, 1.0f, 0.0f );
	this->view = glm::lookAt( this->camPos, this->lookAt, this->upDir );

	// Assign the value for the projection matrix
	this->near = 1.0f;
	this->far = 100.0f;
	this->fov = 45.0f;
	this->aspect = 1024.0f / 768.0f;
	this->proj = glm::perspective( this->fov, this->aspect, this->near, this->far );
}

/***************************************************************************************************
* ~Camera function
*
* Placeholder.
***************************************************************************************************/
Camera::~Camera( void )
{
	
}