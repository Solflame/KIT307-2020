/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Robot Composite for Assignment 1 - Task 2: Composite
*/

#include "Robot.h"

namespace T3D {

	Robot::Robot(T3DApplication* app, Material* matPrimary, Material* matSecondary) : GameObject(app) {

		setMesh(new Cube(0.1f));
		getTransform()->name = "Robot";

		// Add joint - Origin
		originJoint = new GameObject(app);
		originJoint->getTransform()->setParent(getTransform());
		originJoint->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		originJoint->getTransform()->name = "OriginJoint";


		// Add mesh - Wheel
		wheel = new GameObject(app);
		wheel->setMesh(new Sphere(0.05f, 16));
		wheel->getTransform()->setParent(originJoint->getTransform());
		wheel->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		wheel->getTransform()->name = "Wheel";
		wheel->setMaterial(matPrimary);


		// Add joint - Hip
		hipJoint = new GameObject(app);
		hipJoint->getTransform()->setParent(wheel->getTransform());
		hipJoint->getTransform()->setLocalPosition(Vector3(0, 0.06f, 0));
		hipJoint->getTransform()->name = "HipJoint";


		// Add mesh - Torso
		torso = new GameObject(app);
		torso->setMesh(new Cylinder(0.08f, 0.1f, 32));
		torso->getTransform()->setParent(hipJoint->getTransform());
		torso->getTransform()->setLocalPosition(Vector3(0, 0.05f, 0));
		torso->getTransform()->name = "Torso";
		torso->setMaterial(matPrimary);


		// Add joint - Neck
		neckJoint = new GameObject(app);
		neckJoint->getTransform()->setParent(torso->getTransform());
		neckJoint->getTransform()->setLocalPosition(Vector3(0, 0.1f, 0));
		neckJoint->getTransform()->name = "NeckJoint";


		// Add mesh - Head
		head = new GameObject(app);
		head->setMesh(new Cube(0.05f));
		head->getTransform()->setParent(neckJoint->getTransform());
		head->getTransform()->setLocalPosition(Vector3(0, 0.05f, 0));
		head->getTransform()->name = "Head";
		head->setMaterial(matPrimary);


		// Add joint - Eye
		eyeJoint = new GameObject(app);
		eyeJoint->getTransform()->setParent(head->getTransform());
		eyeJoint->getTransform()->setLocalPosition(Vector3(0, 0.02f, 0.05f));
		eyeJoint->getTransform()->name = "EyeJoint";


		// Add mesh - Eye
		eye = new GameObject(app);
		eye->setMesh(new Cylinder(0.0125f, 0.005f, 16));
		eye->getTransform()->setParent(eyeJoint->getTransform());
		eye->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		eye->getTransform()->name = "Eye";
		eye->setMaterial(matSecondary);


		// Add joint - Shoulders
		leftShoulderJoint = new GameObject(app);
		leftShoulderJoint->getTransform()->setParent(torso->getTransform());
		leftShoulderJoint->getTransform()->setLocalPosition(Vector3(0.1f, 0.05f, 0));
		leftShoulderJoint->getTransform()->name = "LeftShoulderJoint";

		rightShoulderJoint = new GameObject(app);
		rightShoulderJoint->getTransform()->setParent(torso->getTransform());
		rightShoulderJoint->getTransform()->setLocalPosition(Vector3(-0.1f, 0.05f, 0));
		rightShoulderJoint->getTransform()->name = "RightShoulderJoint";

		// Add mesh - Arms
		leftArm = new GameObject(app);
		leftArm->setMesh(new Cylinder(0.02f, 0.05f, 16));
		leftArm->getTransform()->setParent(leftShoulderJoint->getTransform());
		leftArm->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		leftArm->getTransform()->name = "LeftArm";
		leftArm->setMaterial(matPrimary);

		rightArm = new GameObject(app);
		rightArm->setMesh(new Cylinder(0.02f, 0.05f, 16));
		rightArm->getTransform()->setParent(rightShoulderJoint->getTransform());
		rightArm->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		rightArm->getTransform()->name = "RightArm";
		rightArm->setMaterial(matPrimary);


		// Set default rotations
		eyeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	}


	Robot::~Robot(void) {

	}
}