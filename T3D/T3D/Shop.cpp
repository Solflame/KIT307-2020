/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Shop Mesh for Assignment 2 - Task 1/5: Animation
*/

#include "Shop.h"

namespace T3D {

	Shop::Shop(T3DApplication* app, Material* primaryMat) : GameObject(app) {

		float shopWidth = 10.0f;
		float shopDepth = 8.0f;
		float shopHeight = 8.0f;


		backWall = new GameObject(app);
		backWall->setMesh(new Cube(1.0));/*
		backWall->getTransform()->setLocalPosition(Vector3(0, 0, -shopDepth));
		backWall->getTransform()->setParent(getTransform());
		backWall->setMaterial(primaryMat);*/
	}

	Shop::~Shop(void) {
	}
}