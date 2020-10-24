/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Shop Mesh for Assignment 2 - Task 1/5: Animation
*/

#ifndef SHOP_H
#define SHOP_H

#include "GameObject.h"
#include "Cube.h"
#include "Cylinder.h"
#include <vector>

namespace T3D {
	using std::vector;

	class Shop : public GameObject {
	public:
		Shop(T3DApplication* app, Material* primaryMat);
		~Shop(void);

		GameObject* backWall;
		GameObject* frontWall = new GameObject(app);
		GameObject* leftWall = new GameObject(app);
		GameObject* rightWall = new GameObject(app);
		GameObject* roof = new GameObject(app);
		GameObject* floor = new GameObject(app);
	};
}
#endif