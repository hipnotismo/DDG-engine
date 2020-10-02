#include "entity.h"

#include "ext/matrix_transform.hpp"
#include "ext/matrix_clip_space.hpp"
#include "ext/scalar_constants.hpp"

#include "renderer.h"

void Entity::updateTRS() {
	trs.TRS = trs.translate * trs.rotationX * trs.rotationY * trs.rotationZ * trs.scale;
}

Entity::Entity(Renderer* renderer) {
	_renderer = renderer;
	// se setea la identidad de las matrices
	trs.translate = glm::mat4(1.0);
	trs.rotationX = glm::mat4(1.0);
	trs.rotationY = glm::mat4(1.0);
	trs.rotationZ = glm::mat4(1.0);
	trs.scale = glm::mat4(1.0);

	setScale(1.0f, 1.0f, 1.0f);
	setPosition(0.0f, 0.0f, 0.0f);
	setRotX(0.0f);
	setRotY(0.0f);
	setRotZ(0.0f);
}

Entity::Entity()
{
}

Entity::~Entity() {}

Renderer* Entity::getRenderer() {
	return _renderer;
}
glm::mat4 Entity::getTRS() {
	return trs.TRS;
}
void Entity::setPosition(float x, float y, float z) {
	transform.position[0] = x; // Actualizo vec3 de posicion con nuevos valores
	transform.position[1] = y;
	transform.position[2] = z;
	trs.translate = glm::translate(glm::mat4(1.0f), transform.position); // setear lado derecho con los datos de vec3 position y w(1)
	updateTRS(); // Actualizo el TRS									// w x y z
}

void Entity::setRotX(float x) {
	transform.rotation[0] = x;
	glm::vec3 axis;
	axis[0] = 1.0f;
	axis[1] = 0.0f;
	axis[2] = 0.0f;
	trs.rotationX = glm::rotate(glm::mat4(1.0f), x, axis); // Se setea en diagonal la x y la variable representaria el angulo
	updateTRS();
}

void Entity::setRotY(float y) {
	transform.rotation[1] = y;
	glm::vec3 axis;
	axis[0] = 0.0f;
	axis[1] = 1.0f;
	axis[2] = 0.0f;
	trs.rotationX = glm::rotate(glm::mat4(1.0f), y, axis); // Se setea en diagonal la y
	updateTRS(); // Actualizo el TRS
}

void Entity::setRotZ(float z) {
	transform.rotation[2] = z;
	glm::vec3 axis;
	axis[0] = 0.0f;
	axis[1] = 0.0f;
	axis[2] = 1.0f;
	trs.rotationX = glm::rotate(glm::mat4(1.0f), z, axis); // Se setea en diagonal la z
	updateTRS(); // Actualizo el TRS
}

void Entity::setScale(float x, float y, float z) {
	transform.scale[0] = x; // Actualizo vec3 de escala con nuevos valores
	transform.scale[1] = y;
	transform.scale[2] = z;
	trs.scale = glm::scale(glm::mat4(1.0f), transform.scale); // setea en diagonal con los datos de vec3 escala y w(1)
	updateTRS(); // Actualizo el TRS	
}
