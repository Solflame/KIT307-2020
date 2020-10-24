/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Hat sweep for Assignment 2 - Task 1: Animated Movie
*/

#include "Hat.h"

namespace T3D {

	Hat::Hat(T3DApplication* app) : GameObject(app) {

		vector<Vector3> hatProfile;	// Sweep profile for the hat

		// Add sweep points
		hatProfile.push_back(Vector3(0.5f, 1.0f, 0.0f));

		hatProfile.push_back(Vector3(0.3f, 1.0f, 0.0f));	// Inner brim connection
		hatProfile.push_back(Vector3(0.3f, 1.0f, 0.0f));

		hatProfile.push_back(Vector3(0.1f, 0.02f, 0.0f));	// Inner top connection

		hatProfile.push_back(Vector3(0.0f, 0.02f, 0.0f));

		hatProfile.push_back(Vector3(0.0f, 0.0f, 0.0f));

		hatProfile.push_back(Vector3(0.22f, 0.0f, 0.0f));	// Outer top
		hatProfile.push_back(Vector3(0.22f, 0.0f, 0.0f));

		hatProfile.push_back(Vector3(0.32f, 0.98f, 0.0f));	// Outer brim connection
		hatProfile.push_back(Vector3(0.32f, 0.98f, 0.0f));

		hatProfile.push_back(Vector3(0.5f, 0.98f, 0.0f));


		// Add transforms
		for (int i = 0; i < 16; i++) {
			t.setLocalPosition(Vector3(0, 0, 0));
			t.setLocalRotation(Quaternion(Vector3(Math::PI, Math::TWO_PI * i / 16, 0)));
			hatsp.addTransform(t);
		}


		// Set sweep mesh
		setMesh(new Sweep(hatProfile, hatsp, true));
		getTransform()->setLocalPosition(Vector3(0, 0, 0));
		getTransform()->setParent(getTransform());
		getTransform()->name = "Hat";
	}


	Hat::~Hat(void) {

	}
}