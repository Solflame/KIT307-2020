/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * T3D Application for Assignment 1
*/

#include "Assignment1Test.h"

namespace T3D {

	Assignment1Test::Assignment1Test(void) {

	}

	Assignment1Test::~Assignment1Test(void) {

	}

	bool Assignment1Test::init() {
		WinGLApplication::init();

		// Adds a single directional light
		GameObject* lightObj = new GameObject(this);
		Light* light = new Light(Light::DIRECTIONAL);
		light->setAmbient(1, 1, 1);
		light->setDiffuse(1, 1, 1);
		light->setSpecular(1, 1, 1);
		lightObj->setLight(light);
		lightObj->getTransform()->
			setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
		lightObj->getTransform()->setParent(root);


		// Adds a camera
		GameObject* camObj = new GameObject(this);
		renderer->camera =
			new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
		camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
		camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
		camObj->setCamera(renderer->camera);
		camObj->getTransform()->setParent(root);
		camObj->addComponent(new KeyboardController());


		// Add coloured materials
		Material* matWhite = renderer->createMaterial(Renderer::PR_OPAQUE);
		matWhite->setDiffuse(1, 1, 1, 1);

		Material* matBlue = renderer->createMaterial(Renderer::PR_OPAQUE);
		matBlue->setDiffuse(0, 0.424f, 0.502f, 1);

		Material* matPurple = renderer->createMaterial(Renderer::PR_OPAQUE);
		matPurple->setDiffuse(0.337f, 0.184f, 0.494f, 1);

		Material* matBrass = renderer->createMaterial(Renderer::PR_OPAQUE);
		matBrass->setDiffuse(1.0f, 0.659f, 0.294f, 1);


		// Task 1: Sweep 15%
		UFO* ufo = new UFO(this);
		ufo->setMaterial(matPurple);
		ufo->getTransform()->setLocalPosition(Vector3(-10, 0, 0));
		ufo->getTransform()->setLocalScale(Vector3(1, 1, 1));
		ufo->getTransform()->setParent(root);


		// Task 2: Composite 25%
		Robot* robot = new Robot(this, matWhite, matBlue);
		robot->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		robot->getTransform()->setLocalScale(Vector3(10, 10, 10));
		robot->getTransform()->setParent(root);


		// Task 3: Key 30%
		GameObject* key = new GameObject(this);
		key->setMesh(new Key(40, 8, 30, 10, 2, 10, 20, { 1.0f, 1.0f, 1.0f, 0.7f, 1.0f, 0.7f, 0.9f, 1.0f, 0.4f }));
		key->setMaterial(matBrass);
		key->getTransform()->setLocalPosition(Vector3(10, 0, 0));
		key->getTransform()->setLocalScale(Vector3(0.05f, 0.05f, 0.05f));
		key->getTransform()->setParent(root);


		// Task 4: Fancy Key 30%


		// Task 5: Additional composite 30%



		return true;
	}
}