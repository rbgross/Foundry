/***************************************************************************************************
* Physics.cpp
*
* Placeholder.
***************************************************************************************************/

/* INCLUDES */
#include "Foundry.h"

/***************************************************************************************************
* cameraToCursorRay function
*
* Placeholder.
***************************************************************************************************/
glm::vec3 cameraToCursorRay( Camera* camera  )
{
	int width, height;
	double xpos, ypos;
	Global::window->getCursorPosition( &xpos, &ypos ); 
	Global::window->getWindowSize( &width, &height );

	float x = ( 2.0f * (int) xpos ) / width - 1.0f;
	float y = 1.0f - ( 2.0f * (int) ypos ) / height;
	
	glm::vec4 p = glm::inverse( camera->proj * camera->view ) * glm::vec4( x, y, 0, 1.0f );
	glm::vec3 ray = glm::normalize( glm::vec3( p / p.w ) - camera->camPos );

	return ray;
}

/***************************************************************************************************
* pointToPointRay function
*
* Placeholder.
***************************************************************************************************/
glm::vec3 pointToPointRay( glm::vec3 origin, glm::vec3 target )
{
	glm::vec3 ray = glm::normalize( target - origin );
	return ray;
}

/***************************************************************************************************
* raySphereIntersection function
*
* Placeholder.
***************************************************************************************************/
bool raySphereIntersection( glm::vec3 rayOrigin, glm::vec3 rayDirection, SphereCollider* sphereCollider )
{
	glm::vec3 l = rayOrigin - sphereCollider->center;
	float b = rayDirection.x * l.x + rayDirection.y * l.y + rayDirection.z * l.z;
	float c = l.x * l.x + l.y * l.y + l.z * l.z - sphereCollider->radius * sphereCollider->radius;
	return ( b * b - c ) >= 0;
}

/***************************************************************************************************
* sphereSphereIntersection function
*
* Placeholder.
***************************************************************************************************/
bool sphereSphereIntersection( SphereCollider* sphere1, SphereCollider* sphere2 )
{
	glm::vec3 c = sphere2->center - sphere1->center;
	float d = glm::dot(c, c);
	return (sphere1->radius + sphere2->radius) * (sphere1->radius + sphere2->radius) >= d;
}

/***************************************************************************************************
* rayOBBIntersection function
*
* Placeholder.
***************************************************************************************************/
bool rayOBBIntersection( glm::vec3 rayOrigin, glm::vec3 rayDirection, OBBCollider* obbCollider )
{
	float tmin = 0.0f;
	float tmax = FLT_MAX;

	rayOrigin = glm::inverse( obbCollider->orientation ) * ( rayOrigin - obbCollider->center ) + obbCollider->center;
	rayDirection = glm::inverse( obbCollider->orientation )  * rayDirection;
	
	// For all 3 slabs
	for ( int i = 0; i < 3; i++ ) {
		float amin = obbCollider->center[ i ] - obbCollider->halfWidths[ i ];
		float amax = obbCollider->center[ i ] + obbCollider->halfWidths[ i ];

		if ( abs( rayDirection[ i ] ) < 0.0001f ) {
			// Ray is parallel to slab, no hit if origina not within slab
			if ( rayOrigin[ i ] < amin || rayOrigin[ i ] > amax ) {
				return false;
			}
		} else {
			// Compute intersection t value of ray with near and far plane of slab
			float ood =  1.0f / rayDirection[ i ];
			float t1 = ( amin - rayOrigin[ i ] ) * ood;
			float t2 = ( amax - rayOrigin[ i ] ) * ood;
			// Make t1 be be intersection with near plane, t2 with far plane
			if ( t1 > t2 ) {
				float temp = t2;
				t2 = t1;
				t1 = temp;
			}
			// Compute the intersection of slab intersection intervals
			if ( t1 > tmin ) {
				tmin = t1;
			}
			if ( t2 < tmax ) {
				tmax = t2;
			}
			// Exit with no collision as soon as slab intersection test becomes empty
			if ( tmin > tmax ) {
				return false;
			}
		}
	}
	// Ray intersects all 3 slabs, return point (q) and intersection t value (tmin)
	glm::vec3 q = rayOrigin + rayDirection * tmin;
	return true;
}

/***************************************************************************************************
* sphereOBBIntersection function
*
* Placeholder.
***************************************************************************************************/
bool sphereOBBIntersection(SphereCollider* sphereCollider, OBBCollider* obbCollider)
{
	glm::vec3 d = sphereCollider->center - obbCollider->center;
	glm::vec3 q = obbCollider->center;

	for (int i = 0; i < 3; i++) {
		float dist = glm::dot(d, obbCollider->orientation[i]);
		if (dist > obbCollider->halfWidths[i]) dist = obbCollider->halfWidths[i];
		if (dist < -obbCollider->halfWidths[i]) dist = -obbCollider->halfWidths[i];
		q += dist * obbCollider->orientation[i];
	}

	glm::vec3 v = q - sphereCollider->center;
	return glm::dot(v, v) <= sphereCollider->radius * sphereCollider->radius;
}