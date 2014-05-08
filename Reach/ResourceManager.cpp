/***************************************************************************************************
* ResourceManager.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* ResourceManager function
*
* Placeholder.
***************************************************************************************************/
ResourceManager::ResourceManager( void )
{
	
}

/***************************************************************************************************
* ~ResourceManager function
*
* Placeholder.
***************************************************************************************************/
ResourceManager::~ResourceManager( void )
{
	
}

/***************************************************************************************************
* loadConfig function
*
* Placeholder.
***************************************************************************************************/
void ResourceManager::loadConfig( std::string fileName )
{
	std::ifstream in( fileName );
	if ( !in )
	{
		std::cerr << "Unable to open " << fileName << ".";
		return;
	}

	in.close();
}

/***************************************************************************************************
* loadMesh function
*
* Placeholder.
***************************************************************************************************/
void ResourceManager::loadMesh( std::string fileName )
{
	if ( this->meshes.find( fileName ) != this->meshes.end() )
	{
		std::cerr << "Mesh " << fileName << " has already been loaded." << std::endl;
		return;
	}
	
	std::ifstream in( fileName.c_str() );
	if ( !in )
	{
		std::cerr << "Unable to open " << fileName << ".";
		return;
	}

	std::string line;
	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec3 > normals;
	std::vector< glm::vec2 > texCoords;

	std::vector< float> meshData;
	std::vector< GLuint > elements;

	while ( getline( in, line ) ) {
		std::istringstream s( line );
		std::string token;
		s >> token;

		if ( token == "v" ) {
			glm::vec3 v;
			s >> v.x >> v.y >> v.z;
			vertices.push_back( v );
		} else if ( token == "vn" ) {
			glm::vec3 v;
			s >> v.x >> v.y >> v.z;
			normals.push_back( v );
		} else if ( token == "vt" ) {
			glm::vec2 v;
			s >> v.x >> v.y;
			texCoords.push_back( v );
		} else if ( token == "f" ) {
			unsigned int v, t, n;
			std::streamoff pos;
			for ( unsigned int i = 0; i < 3; i++ ) {
				s >> v;
				pos = s.tellg();
				s.seekg( pos + 1 );
				s >> t;
				pos = s.tellg();
				s.seekg( pos + 1 );
				s >> n;
				pos = s.tellg();
				s.seekg( pos + 1 );
				meshData.push_back( vertices[ v - 1 ].x );
				meshData.push_back( vertices[ v - 1 ].y );
				meshData.push_back( vertices[ v - 1 ].z );
				meshData.push_back( texCoords[ t - 1 ].x );
				meshData.push_back( texCoords[ t - 1 ].y );
				meshData.push_back( normals[ n - 1 ].x );
				meshData.push_back( normals[ n - 1 ].y );
				meshData.push_back( normals[ n - 1 ].z );
				elements.push_back( elements.size() );
			}
		}
	}

	in.close();

	meshData.shrink_to_fit();
	elements.shrink_to_fit();

	this->meshes[ fileName ] = new Mesh( meshData, elements );
}