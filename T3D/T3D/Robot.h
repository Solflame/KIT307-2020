/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Robot Composite for Assignment 1 - Task 2: Composite
*/

#pragma once
#include "GameObject.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Math.h"
#include "Mesh.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include <vector>

namespace T3D {
	using std::vector;

	class Robot :
		public GameObject
	{
	public:
		Robot(T3DApplication* app, Material* matPrimary, Material* matSecondary);
		~Robot(void);


		GameObject* robot;

		// Sub-objects
		GameObject* wheel;
		GameObject* torso;
		GameObject* head;
		GameObject* eye;
		GameObject* leftArm;
		GameObject* rightArm;
		GameObject* leftClaw;
		GameObject* rightClaw;

		// Joints
		GameObject* originJoint;
		GameObject* hipJoint;
		GameObject* neckJoint;
		GameObject* eyeJoint;
		GameObject* leftShoulderJoint;
		GameObject* rightShoulderJoint;
		GameObject* leftWristJoint;
		GameObject* rightWristJoint;
	};
}