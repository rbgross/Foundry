/***************************************************************************************************
* Foundry.h
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#define GLEW_STATIC 
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <float.h>

/* DEFINES */
enum Attributes {
	ATTRIB_POSITION,
	ATTRIB_NORMAL,
	ATTRIB_TEXTURE
};

enum RenderTargets {
	FRAGDATA_OUTCOLOR
};

/* CLASS DEFINITIONS */
class Actor;
class ActorFactory;
class Camera;
class Controller;
//class Global;
class Light;
//class Main;
class Material;
class Mesh;
class OBBCollider;
//class Physics;
class Renderer;
class ResourceManager;
class SceneGraph;
class Shader;
class ShaderFactory;
class SphereCollider;
class Transform;
class Window;

// Actor class definition
class Actor
{
	public:
		Mesh* mesh;
		Material* material;
		Transform* transform;
		Controller* controller;
		SphereCollider* sphereCollider;
		OBBCollider* obbCollider;
		Actor( void );
		~Actor( void );
};

// ActorFactory class definition
class ActorFactory
{
	public:
		static Actor* makeCube( void );
		static Actor* makeTile( void );
		static Actor* makeSphere( void );
		static Actor* makePlane( void );
		static Actor* makeDragon( void );
};

// Camera class definition
class Camera
{	
	public:
		glm::vec3 camPos;
		glm::vec3 lookAt;
		glm::vec3 upDir;
		glm::mat4 view;
		float near;
		float far;
		float aspect;
		float fov;
		glm::mat4 proj;
		Camera( void );
		~Camera( void );
};

// Controller class definition
class Controller
{
	public:
		bool selected;
		Transform* transform;
		Controller( void );
		~Controller( void );
		void update( void );
};

// Light class definition
class Light
{
	public:
		glm::vec4 lightPos;
		Light( void );
		~Light( void );
};

// Material class definition
class Material
{
	public:
		glm::vec3 diffuseColor;
		Material( void );
		~Material( void );
};

// Mesh class definition
class Mesh
{
	private:
		GLuint vbo;
		GLuint ebo;
		std::vector< float > meshData;
	public:
		GLuint vao;
		std::vector< GLuint > elements;
		Mesh( std::vector< float >, std::vector< GLuint > );
		~Mesh( void );
};

// OBBCollider class definition
class OBBCollider
{
	private:
	public:
		glm::vec3 center;
		glm::mat3 orientation;
		glm::vec3 halfWidths;
		OBBCollider( void );
		~OBBCollider( void );	
};

// Renderer class definition
class Renderer
{
	private:
	public:
		GLuint activeShader;
		std::vector< Shader* > shaders;
		Renderer( void );
		~Renderer( void );
		void initialize( void );
		void draw( void );
};

// Resourcemanager class definition
class ResourceManager
{
	private:
	public:
		ResourceManager();
		~ResourceManager();
		std::map< std::string, Mesh* > meshes;
		void loadConfig( std::string );
		void loadMesh( std::string );
};

// SceneGraph class definition
class SceneGraph
{		
	public:
		Light* light;
		Camera* camera;
		std::vector< Actor* > actors;
		SceneGraph();
		~SceneGraph();
};

// Shader class definition
class Shader
{
	private:
		GLuint m_shaderProgram;
		std::map<std::string, GLuint> m_uniforms;
		void PrintShaderInfoLog(GLuint);
		void PrintProgramInfoLog(GLuint);
	public:
		Shader(void);
		~Shader(void);
		void LoadShaderFromFile(GLenum, std::string);
		void BindAttribute(GLuint, std::string);
		void BindFragmentData(GLuint, std::string);
		void LinkProgram(void);
		void Use(void);
		void AddUniform(std::string);
		void SetUniform(std::string, int);
		void SetUniform(std::string, float);
		void SetUniform(std::string, glm::vec3);
		void SetUniform(std::string, glm::vec4);
		void SetUniform(std::string, glm::mat3);
		void SetUniform(std::string, glm::mat4);
};

// ShaderFactory class definition
class ShaderFactory
{
public:
	static Shader* Flat(void);
	static Shader* ADS(void);
};

// SphereCollider class definition
class SphereCollider
{
	private:
	public:
		glm::vec3 center;
		float radius;
		SphereCollider( void );
		~SphereCollider( void );	
};

// Transform class definition
class Transform
{
	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 m_scale;
	public:
		glm::mat4 model;
		Transform( void );
		~Transform( void );
		void translate( glm::vec3 );
		void rotate( float, glm::vec3 );
		void scale( glm::vec3 );
		glm::vec3 getPosition( void );
		void setPosition( glm::vec3 );
		glm::vec3 getRotation( void );
		void setRotation( glm::vec3 );
		glm::vec3 getScale( void );
		void setScale( glm::vec3 );
};

// Window class definition
class Window
{
	private:
		GLFWwindow* window;
		bool initialized;
		int width;
		int height;
		std::string title;
	public:
		Window( void );
		~Window( void );
		int initialize( int, int, std::string );
		bool active( void );
		void swapBuffers( void );
		bool getKey( int );
		void getWindowSize( int*, int* );
		void getCursorPosition( double*, double* );
};

// Physics
glm::vec3 cameraToCursorRay( Camera* );
glm::vec3 pointToPointRay( glm::vec3, glm::vec3 );
bool raySphereIntersection( glm::vec3, glm::vec3, SphereCollider* );
bool sphereSphereIntersection( SphereCollider*, SphereCollider* );
bool rayOBBIntersection( glm::vec3, glm::vec3, OBBCollider* );
bool sphereOBBIntersection( SphereCollider*, OBBCollider* );

// GLOBAL VARIABLES
namespace Global {
	extern ResourceManager* resourceManager;
	extern Window* window;
	extern Renderer* renderer;
	extern SceneGraph* sceneGraph;
}