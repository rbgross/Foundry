/***************************************************************************************************
* ShaderFactory.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* Flat function
*
* Placeholder.
***************************************************************************************************/
Shader* ShaderFactory::Flat(void)
{
	Shader* shader = new Shader();
	shader->LoadShaderFromFile(GL_VERTEX_SHADER, "Flat.vert");
	shader->LoadShaderFromFile(GL_FRAGMENT_SHADER, "Flat.frag");
	shader->BindAttribute(ATTRIB_POSITION, "position");
	shader->BindAttribute(ATTRIB_NORMAL, "normal");
	//shader->BindAttribute(ATTRIB_TEXTURE, "texCoord");
	shader->BindFragmentData(FRAGDATA_OUTCOLOR, "outColor");
	shader->LinkProgram();
	shader->AddUniform("model");
	shader->AddUniform("view");
	shader->AddUniform("proj");
	shader->AddUniform("lightPosition");
	shader->AddUniform("diffuseColor");

	return shader;
}

/***************************************************************************************************
* ADS function
*
* Placeholder.
***************************************************************************************************/
Shader* ShaderFactory::ADS(void)
{
	Shader* shader = new Shader();
	shader->LoadShaderFromFile(GL_VERTEX_SHADER, "ADS.vert");
	shader->LoadShaderFromFile(GL_FRAGMENT_SHADER, "ADS.frag");
	shader->BindAttribute(ATTRIB_POSITION, "position");
	shader->BindAttribute(ATTRIB_NORMAL, "normal");
	//shader->BindAttribute(ATTRIB_TEXTURE, "texCoord");
	shader->BindFragmentData(FRAGDATA_OUTCOLOR, "outColor");
	shader->LinkProgram();
	shader->AddUniform("model");
	shader->AddUniform("view");
	shader->AddUniform("proj");
	shader->AddUniform("lightPosition");
	shader->AddUniform("diffuseColor");

	return shader;
}