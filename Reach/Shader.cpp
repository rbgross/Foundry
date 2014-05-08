/***************************************************************************************************
* Shader.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Shader function
*
* Placeholder.
***************************************************************************************************/
Shader::Shader()
{
	//Create the program
	this->m_shaderProgram = glCreateProgram();	
}

/***************************************************************************************************
* ~Shader function
*
* Placeholder.
***************************************************************************************************/
Shader::~Shader( void )
{
	// Clean up the program before exiting
	glDeleteProgram(this->m_shaderProgram);
}

/***************************************************************************************************
* LoadShaderFromFile function
*
* Placeholder.
***************************************************************************************************/
void Shader::LoadShaderFromFile( GLenum shaderType, std::string fileName )
{	
	//Attempt to open the file
	std::ifstream in(fileName.c_str());
	if (!in) {
		std::cerr << "Unable to open shader file " << fileName << ".";
		return;
	}

	//Read in the file contents to a string
	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string source = buffer.str();
	in.close();
	const char* code = source.c_str();

	//Create, compile, and attach the shader
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &code, NULL);
	glCompileShader(shader);
	glAttachShader(this->m_shaderProgram, shader);

	//Print any errors to the log
	PrintShaderInfoLog(shader);

	//Flag the shader for deletion when not in use
	glDeleteShader(shader);
}

/***************************************************************************************************
* BindAttribute function
*
* Placeholder.
***************************************************************************************************/
void Shader::BindAttribute(GLuint index, std::string name)
{
	glBindAttribLocation(this->m_shaderProgram, index, name.c_str());
}

/***************************************************************************************************
* BindFragmentData function
*
* Placeholder.
***************************************************************************************************/
void Shader::BindFragmentData(GLuint index, std::string name)
{
	glBindFragDataLocation(this->m_shaderProgram, index, name.c_str());
}

/***************************************************************************************************
* LinkProgram function
*
* Placeholder.
***************************************************************************************************/
void Shader::LinkProgram()
{
	// Link the vertex and fragment shader into a shader program
	glLinkProgram(this->m_shaderProgram);

	// Print the shader logs
	PrintProgramInfoLog(this->m_shaderProgram);
}

/***************************************************************************************************
* Use function
*
* Placeholder.
***************************************************************************************************/
void Shader::Use()
{
	glUseProgram(this->m_shaderProgram);
}

/***************************************************************************************************
* AddUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::AddUniform(std::string name)
{
	this->m_uniforms[name] = glGetUniformLocation(this->m_shaderProgram, name.c_str());
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, int value)
{
	glUniform1i(this->m_uniforms[name], value);
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, float value)
{
	glUniform1f(this->m_uniforms[name], value);
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, glm::vec3 value)
{
	glUniform3fv(this->m_uniforms[name], 1, glm::value_ptr(value));
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, glm::vec4 value)
{
	glUniform4fv(this->m_uniforms[name], 1, glm::value_ptr(value));
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, glm::mat3 value)
{
	glUniformMatrix3fv(this->m_uniforms[name], 1, GL_FALSE, glm::value_ptr(value));
}

/***************************************************************************************************
* SetUniform function
*
* Placeholder.
***************************************************************************************************/
void Shader::SetUniform(std::string name, glm::mat4 value)
{
	glUniformMatrix4fv(this->m_uniforms[name], 1, GL_FALSE, glm::value_ptr(value));
}

/***************************************************************************************************
* PrintShaderInfoLog function
*
* Placeholder.
***************************************************************************************************/
void Shader::PrintShaderInfoLog(GLuint shader)
{
    //Get the info log length
	int infoLogLength = 0; 
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
 
	//Write out the info log, if it exists
	if (infoLogLength > 1) {
		int charsWritten = 0;
		char *infoLog = new char[infoLogLength];
        glGetShaderInfoLog(shader, infoLogLength, &charsWritten, infoLog);
		std::cerr << infoLog << std::endl;
		delete infoLog;
	}
}
 
/***************************************************************************************************
* PrintProgramInfoLog function
*
* Placeholder.
***************************************************************************************************/
void Shader::PrintProgramInfoLog(GLuint program)
{
	//Get the info log length
	int infoLogLength = 0; 
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
 
	//Write out the info log, if it exists
    if (infoLogLength > 1) {
        int charsWritten = 0;
		char* infoLog = new char[infoLogLength];
        glGetProgramInfoLog(program, infoLogLength, &charsWritten, infoLog);
		std::cerr << infoLog << std::endl;
		delete infoLog;
    }
}