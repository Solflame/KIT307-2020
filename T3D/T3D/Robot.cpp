/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Robot Composite for Assignment 2 - Task 1: Animated Movie
*/

#include "Robot.h"

namespace T3D {

	Robot::Robot(T3DApplication* app, Material* primaryMat, Material* secondaryMat, Material* metalMat, Material* wheelMat) : GameObject(app) {

		float headRadius = 0.3f;
		float torsoHeight = 0.8f;
		float torsoRadius = 0.5f;
		float footSize = 0.2f;
		float limbLength = 0.2f;
		float limbRadius = 0.08f;
		float jointRadius = 0.1f;
		int limbDensity = 16;

		this->getTransform()->name = "Robot";
		this->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));


		// Define component meshes
		Cylinder* torsoMesh = new Cylinder(torsoRadius, torsoHeight, limbDensity);
		Cylinder* limbMesh = new Cylinder(limbRadius, limbLength, limbDensity);
		Cube* clawMesh = new Cube(jointRadius);
		Sphere* wheelMesh = new Sphere(jointRadius * 2);



		// Add a origin for rotations
		origin = new GameObject(app);
		origin->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		origin->getTransform()->setParent(getTransform());
		origin->getTransform()->name = "Origin";


		// Add component - TORSO
		torso = new GameObject(app);
		torso->setMesh(torsoMesh);
		torso->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		torso->getTransform()->setParent(origin->getTransform());
		torso->setMaterial(secondaryMat);
		torso->getTransform()->name = "Torso";

		// Add joint - NECK
		neckJoint = new GameObject(app);
		neckJoint->setMesh(new Sphere(jointRadius));
		neckJoint->getTransform()->setLocalPosition(Vector3(0, (torsoHeight + jointRadius / 2), 0));
		neckJoint->getTransform()->setParent(torso->getTransform());
		neckJoint->setMaterial(metalMat);
		neckJoint->getTransform()->name = "Neck";

		// Add component - HEAD
		head = new GameObject(app);
		head->setMesh(new Sphere(headRadius));
		head->getTransform()->setLocalPosition(Vector3(0, headRadius, 0));
		head->getTransform()->setParent(neckJoint->getTransform());
		head->setMaterial(primaryMat);
		head->getTransform()->name = "Head";

		// Add components - LEFT ARM
		leftShoulderJoint = new GameObject(app);
		leftShoulderJoint->setMesh(new Sphere(jointRadius));
		leftShoulderJoint->getTransform()->setLocalPosition(Vector3(torsoRadius, torsoHeight - jointRadius, 0));
		leftShoulderJoint->getTransform()->setParent(torso->getTransform());
		leftShoulderJoint->setMaterial(metalMat);
		leftShoulderJoint->getTransform()->name = "LeftShoulder";

		leftUpperArm = new GameObject(app);
		leftUpperArm->setMesh(limbMesh);
		leftUpperArm->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		leftUpperArm->getTransform()->setParent(leftShoulderJoint->getTransform());
		leftUpperArm->setMaterial(secondaryMat);
		leftUpperArm->getTransform()->name = "LeftUpperArm";

		leftElbowJoint = new GameObject(app);
		leftElbowJoint->setMesh(new Sphere(jointRadius));
		leftElbowJoint->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		leftElbowJoint->getTransform()->setParent(leftUpperArm->getTransform());
		leftElbowJoint->setMaterial(metalMat);
		leftElbowJoint->getTransform()->name = "LeftElbow";

		leftLowerArm = new GameObject(app);
		leftLowerArm->setMesh(limbMesh);
		leftLowerArm->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		leftLowerArm->getTransform()->setParent(leftElbowJoint->getTransform());
		leftLowerArm->setMaterial(secondaryMat);
		leftLowerArm->getTransform()->name = "LeftLowerArm";

		leftWristJoint = new GameObject(app);
		leftWristJoint->setMesh(new Sphere(jointRadius));
		leftWristJoint->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		leftWristJoint->getTransform()->setParent(leftLowerArm->getTransform());
		leftWristJoint->setMaterial(metalMat);
		leftWristJoint->getTransform()->name = "LeftWrist";

		leftClaw = new GameObject(app);
		leftClaw->setMesh(clawMesh);
		leftClaw->getTransform()->setLocalPosition(Vector3(0, -(jointRadius + jointRadius / 2), 0));
		leftClaw->getTransform()->setParent(leftWristJoint->getTransform());
		leftClaw->setMaterial(primaryMat);
		leftClaw->getTransform()->name = "LeftClaw";

		// Add components - RIGHT ARM
		rightShoulderJoint = new GameObject(app);
		rightShoulderJoint->setMesh(new Sphere(jointRadius));
		rightShoulderJoint->getTransform()->setLocalPosition(Vector3(-torsoRadius, torsoHeight - jointRadius, 0));
		rightShoulderJoint->getTransform()->setParent(torso->getTransform());
		rightShoulderJoint->setMaterial(metalMat);
		rightShoulderJoint->getTransform()->name = "RightShoulder";

		rightUpperArm = new GameObject(app);
		rightUpperArm->setMesh(limbMesh);
		rightUpperArm->getTransform()->setLocalPosition(Vector3(0, (limbLength + jointRadius / 2), 0));
		rightUpperArm->getTransform()->setParent(rightShoulderJoint->getTransform());
		rightUpperArm->setMaterial(secondaryMat);
		rightUpperArm->getTransform()->name = "RightUpperArm";

		rightElbowJoint = new GameObject(app);
		rightElbowJoint->setMesh(new Sphere(jointRadius));
		rightElbowJoint->getTransform()->setLocalPosition(Vector3(0, (limbLength + jointRadius / 2), 0));
		rightElbowJoint->getTransform()->setParent(rightUpperArm->getTransform());
		rightElbowJoint->setMaterial(metalMat);
		rightElbowJoint->getTransform()->name = "RightElbow";

		rightLowerArm = new GameObject(app);
		rightLowerArm->setMesh(limbMesh);
		rightLowerArm->getTransform()->setLocalPosition(Vector3(0, (limbLength + jointRadius / 2), 0));
		rightLowerArm->getTransform()->setParent(rightElbowJoint->getTransform());
		rightLowerArm->setMaterial(secondaryMat);
		rightLowerArm->getTransform()->name = "RightLowerArm";

		rightWristJoint = new GameObject(app);
		rightWristJoint->setMesh(new Sphere(jointRadius));
		rightWristJoint->getTransform()->setLocalPosition(Vector3(0, (limbLength + jointRadius / 2), 0));
		rightWristJoint->getTransform()->setParent(rightLowerArm->getTransform());
		rightWristJoint->setMaterial(metalMat);
		rightWristJoint->getTransform()->name = "RightWrist";

		rightClaw = new GameObject(app);
		rightClaw->setMesh(clawMesh);
		rightClaw->getTransform()->setLocalPosition(Vector3(0, (jointRadius + jointRadius / 2), 0));
		rightClaw->getTransform()->setParent(rightWristJoint->getTransform());
		rightClaw->setMaterial(primaryMat);
		rightClaw->getTransform()->name = "RightClaw";

		// Add components - LEG
		hipJoint = new GameObject(app);
		hipJoint->setMesh(new Sphere(jointRadius));
		hipJoint->getTransform()->setLocalPosition(Vector3(0, -torsoHeight, 0));
		hipJoint->getTransform()->setParent(torso->getTransform());
		hipJoint->setMaterial(metalMat);
		hipJoint->getTransform()->name = "Hip";

		upperLeg = new GameObject(app);
		upperLeg->setMesh(limbMesh);
		upperLeg->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		upperLeg->getTransform()->setParent(hipJoint->getTransform());
		upperLeg->setMaterial(secondaryMat);
		upperLeg->getTransform()->name = "UpperLeg";

		kneeJoint = new GameObject(app);
		kneeJoint->setMesh(new Sphere(jointRadius));
		kneeJoint->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		kneeJoint->getTransform()->setParent(upperLeg->getTransform());
		kneeJoint->setMaterial(metalMat);
		kneeJoint->getTransform()->name = "Knee";

		lowerLeg = new GameObject(app);
		lowerLeg->setMesh(limbMesh);
		lowerLeg->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		lowerLeg->getTransform()->setParent(kneeJoint->getTransform());
		lowerLeg->setMaterial(secondaryMat);
		lowerLeg->getTransform()->name = "LowerLeg";

		ankleJoint = new GameObject(app);
		ankleJoint->setMesh(new Sphere(jointRadius));
		ankleJoint->getTransform()->setLocalPosition(Vector3(0, -(limbLength + jointRadius / 2), 0));
		ankleJoint->getTransform()->setParent(lowerLeg->getTransform());
		ankleJoint->setMaterial(metalMat);
		ankleJoint->getTransform()->name = "Ankle";

		wheel = new GameObject(app);
		wheel->setMesh(wheelMesh);
		wheel->getTransform()->setLocalPosition(Vector3(0, -(jointRadius + jointRadius / 2), 0));
		wheel->getTransform()->setParent(ankleJoint->getTransform());
		wheel->setMaterial(wheelMat);
		wheel->getTransform()->name = "Wheel";
	}


	Robot::~Robot(void) {

	}
}