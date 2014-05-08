/***************************************************************************************************
* Window.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Window function
*
* Placeholder.
***************************************************************************************************/
Window::Window( void )
{
	this->initialized = false;
	this->width = 0;
	this->height = 0;
	this->title = "";
}

/***************************************************************************************************
* ~Window function
*
* Placeholder.
***************************************************************************************************/
Window::~Window( void )
{
	glfwTerminate();
}

/***************************************************************************************************
* initialize function
*
* Placeholder.
***************************************************************************************************/
int Window::initialize( int width, int height, std::string title )
{
    if ( this->initialized )
	{
		std::cerr << "This window has already been initialized." << std::endl;
		return -1;
	}
	
	this->width = width;
	this->height = height;
	this->title = title;
	
	/* Initialize GLFW */
    if ( !glfwInit() )
	{
        std::cerr << "GLFW failed to initialize." << std::endl;
		return -1;
	}

	// Provide Renderer hints to GLFW
	glfwWindowHint( GLFW_SAMPLES, 16 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );

    /* Create a windowed mode window and its OpenGL context */
    this->window = glfwCreateWindow( this->width, this->height, this->title.c_str(), NULL, NULL );
    if ( !window )
    {
        glfwTerminate();
		std::cerr << "GLFW failed to create a window." << std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	glewExperimental = GL_TRUE;
	if ( glewInit() != GLEW_OK ) 
	{
		glfwTerminate();
		std::cerr << "GLEW failed to initialize." << std::endl;
		return -1;
	}

	this->initialized = true;
    return 0;
}

/***************************************************************************************************
* windowActive function
*
* Placeholder.
***************************************************************************************************/
bool Window::active( void )
{
	return !glfwWindowShouldClose( this->window );
}

/***************************************************************************************************
* swapBuffers function
*
* Placeholder.
***************************************************************************************************/
void Window::swapBuffers( void )
{
	/* Swap front and back buffers */
	glfwSwapBuffers( this->window );

	/* Poll for and process events */
	glfwPollEvents();
}

/***************************************************************************************************
* getKey function
*
* Placeholder.
***************************************************************************************************/
bool Window::getKey( int key )
{
	return glfwGetKey( this->window, key ) == GLFW_PRESS;
}

/***************************************************************************************************
* getWindowSize function
*
* Placeholder.
***************************************************************************************************/
void Window::getWindowSize( int* width, int* height )
{
	glfwGetWindowSize( this->window, width, height );
}

/***************************************************************************************************
* getCursorPosition function
*
* Placeholder.
***************************************************************************************************/
void Window::getCursorPosition( double* xPos, double* yPos )
{
	glfwGetCursorPos( this->window, xPos, yPos );
}