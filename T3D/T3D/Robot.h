/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Robot Composite for Assignment 2 - Task 1: Animated Movie
*/

#ifndef ROBOT_H
#define ROBOT_H

#include "GameObject.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Math.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include <vector>

namespace T3D {
	using std::vector;

	class Robot : public GameObject {
	public:
		Robot(T3DApplication* app, Material* primaryMat, Material* secondaryMat, Material* metalMat, Material* wheelMat);
		~Robot(void);

		GameObject* origin;

		GameObject* head;
		GameObject* torso;

		GameObject* leftUpperArm;
		GameObject* leftLowerArm;
		GameObject* leftClaw;
		GameObject* rightUpperArm;
		GameObject* rightLowerArm;
		GameObject* rightClaw;

		GameObject* upperLeg;
		GameObject* lowerLeg;
		GameObject* wheel;


		GameObject* neckJoint;

		GameObject* leftShoulderJoint;
		GameObject* leftElbowJoint;
		GameObject* leftWristJoint;
		GameObject* rightShoulderJoint;
		GameObject* rightElbowJoint;
		GameObject* rightWristJoint;

		GameObject* hipJoint;
		GameObject* kneeJoint;
		GameObject* ankleJoint;
	};
}
#endif