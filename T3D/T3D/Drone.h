/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Drone Composite for Assignment 2 - Task 5: Extended Movie
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

	class Drone : public GameObject {
	public:
		Drone(T3DApplication* app, Material* bodyMaterial, Material* bladeMaterial);
		~Drone(void);

		GameObject* drone;


		/* ----------
		 * COMPONENTS
		 * ---------- */

		 // Chassis - Drone body
		GameObject* chassis;

		// Support - Connects the blades to the chassis
		GameObject* support;

		// Blades - Rotate within the chassis
		GameObject* blade1, * blade2, * blade3;

		// Upper Arms
		GameObject* upperArm1, * upperArm2, * upperArm3, * upperArm4;

		// Lower Arms
		GameObject* lowerArm1, * lowerArm2, * lowerArm3, * lowerArm4;


		/* ------
		 * JOINTS
		 * ------ */

		 // Blade Joint (Support > Blades)
		GameObject* bladeJoint;

		// Shoulder Joints (Chassis > Upper Arms)
		GameObject* shoulderJoint1, * shoulderJoint2, * shoulderJoint3, * shoulderJoint4;

		// Elbow Joints (Upper Arms > Lower Arms)
		GameObject* elbowJoint1, * elbowJoint2, * elbowJoint3, * elbowJoint4;


		/* ------
		 * SWEEPS
		 * ------ */
		GameObject* blade;
		SweepPath bladesp;
		Transform t;
	};
}