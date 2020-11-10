/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Exam content - 2020
*/

#include "Exam2020.h"

namespace T3D {

	Exam2020::Exam2020(void) {
		//drawArea = new Texture(1024, 640, false);
		/*drawArea = new Texture(1024, 512, false);
		drawArea->clear(Colour(255, 255, 255, 255));*/

		// Initialise
		/*drawExamTask = NULL;
		perfLogTask = NULL;*/
	}


	Exam2020::~Exam2020(void) {

	}


	bool Exam2020::init() {
		WinGLApplication::init();

		/**
		 *  2D Drawing
		 */
		/*renderer->loadTexture(drawArea, false);
		renderer->add2DOverlay(drawArea, 0, 0);

		drawExamTask = new DrawExamTask(this, drawArea);
		addTask(drawExamTask);

		perfLogTask = new PerfLogTask(this);
		addTask(perfLogTask);*/


		/**
		 * 3D Meshs
		 */

		 // Light
		GameObject* lightObj = new GameObject(this);
		Light* light = new Light(Light::DIRECTIONAL);
		light->setAmbient(1, 1, 1);
		light->setDiffuse(1, 1, 1);
		light->setSpecular(1, 1, 1);
		lightObj->setLight(light);
		lightObj->getTransform()->
			setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
		lightObj->getTransform()->setParent(root);

		// Camera
		GameObject* cameraObj = new GameObject(this);
		renderer->camera =
			new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
		cameraObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
		cameraObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
		cameraObj->setCamera(renderer->camera);
		cameraObj->getTransform()->setParent(root);
		cameraObj->addComponent(new KeyboardController());

		GameObject* examQ3Mesh2 = new GameObject(this);
		examQ3Mesh2->setMesh(new ExamQ3Mesh2(50, 100, 30));
		examQ3Mesh2->setMaterial(new Material(255, 0, 0, 255));
		examQ3Mesh2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		examQ3Mesh2->getTransform()->setParent(root);

		return true;
	}
}