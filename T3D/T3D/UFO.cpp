/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Lollipop Sweep for Assignment 1 - Task 1: Sweep
*/

#include "UFO.h"

namespace T3D {

	UFO::UFO(T3DApplication* app) : GameObject(app) {

		// Add sweep points
		vector<Vector3> ufoProfile;

		ufoProfile.push_back(Vector3(0.0f, 0.0f, 0.0f));	// Bottom

		ufoProfile.push_back(Vector3(0.5f, 0.0f, 0.0f));
		ufoProfile.push_back(Vector3(0.5f, 0.0f, 0.0f));

		ufoProfile.push_back(Vector3(1.5f, 1.0f, 0.0f));
		ufoProfile.push_back(Vector3(1.5f, 1.0f, 0.0f));

		ufoProfile.push_back(Vector3(2.2f, 1.0f, 0.0f));
		ufoProfile.push_back(Vector3(2.22f, 1.05f, 0.0f));	// Ring tip
		ufoProfile.push_back(Vector3(2.2f, 1.1f, 0.0f));

		ufoProfile.push_back(Vector3(1.5f, 1.1f, 0.0f));
		ufoProfile.push_back(Vector3(1.5f, 1.1f, 0.0f));

		ufoProfile.push_back(Vector3(0.8f, 1.4f, 0.0f));
		ufoProfile.push_back(Vector3(0.8f, 1.4f, 0.0f));

		ufoProfile.push_back(Vector3(0.5f, 1.7f, 0.0f));

		ufoProfile.push_back(Vector3(0.25f, 1.8f, 0.0f));

		ufoProfile.push_back(Vector3(0.0f, 1.8f, 0.0f));	// Top


		// Add transforms
		for (int i = 0; i < 8; i++) {
			t.setLocalPosition(Vector3(0, 0, 0));
			t.setLocalRotation(Quaternion(Vector3(0, -Math::TWO_PI * i / 8, 0)));
			ufosp.addTransform(t);
		}


		// Set sweep mesh
		setMesh(new Sweep(ufoProfile, ufosp, true));
		getTransform()->setLocalPosition(Vector3(0, 0, 0));
		getTransform()->setParent(getTransform());
		getTransform()->name = "UFO";
	}


	UFO::~UFO(void) {

	}
}