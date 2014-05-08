/***************************************************************************************************
* Mesh.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Mesh function
*
* Placeholder.
***************************************************************************************************/
Mesh::Mesh( std::vector< float > meshData, std::vector< GLuint > elements )
{
	this->meshData = meshData;
	this->elements = elements;
	
	// Create Vertex Array Object
	glGenVertexArrays( 1, &this->vao );
	glBindVertexArray( this->vao );

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers( 1, &this->vbo );
	glBindBuffer( GL_ARRAY_BUFFER, this->vbo );
	glBufferData( GL_ARRAY_BUFFER, this->meshData.size() * sizeof( float ), this->meshData.data(), GL_STATIC_DRAW );

	// Create an element array
	glGenBuffers( 1, &this->ebo );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->ebo );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, this->elements.size() * sizeof( GLuint ), this->elements.data(), GL_STATIC_DRAW );

	// Specify layout of mesh data
	glEnableVertexAttribArray( ATTRIB_POSITION );
	glVertexAttribPointer( ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0 );

	glEnableVertexAttribArray( ATTRIB_TEXTURE );
	glVertexAttribPointer( ATTRIB_TEXTURE, 2, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void*)( 3 * sizeof( float ) ) );

	glEnableVertexAttribArray( ATTRIB_NORMAL );
	glVertexAttribPointer( ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void*)( 5 * sizeof( float ) ) );

	// Unbind buffers
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, NULL );
	glBindBuffer( GL_ARRAY_BUFFER, NULL );
	glBindVertexArray( NULL );
}

/***************************************************************************************************
* ~Mesh function
*
* Placeholder.
***************************************************************************************************/
Mesh::~Mesh( void )
{
	glDeleteBuffers( 1, &this->ebo );
	glDeleteBuffers( 1, &this->vbo );
	glDeleteVertexArrays( 1, &this->vao );
}