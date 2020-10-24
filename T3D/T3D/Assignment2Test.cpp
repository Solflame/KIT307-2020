/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * T3D Application for Assignment 2
*/

#include "Assignment2Test.h"

namespace T3D {

	Assignment2Test::Assignment2Test(void) {

	}

	Assignment2Test::~Assignment2Test(void) {

	}

	bool Assignment2Test::init() {
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

		// Add coloured materials
		Material* whiteMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		whiteMat->setDiffuse(1.0f, 1.0f, 1.0f, 1.0f);

		Material* gunmetalMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		gunmetalMat->setDiffuse(0.16f, 0.20f, 0.22f, 1.0f);
		gunmetalMat->setShininess(20);

		Material* silverMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		silverMat->setDiffuse(0.75f, 0.75f, 0.75f, 1.0f);
		silverMat->setSpecular(0.5f, 0.5f, 0.5f, 0.5f);
		silverMat->setShininess(20);

		Material* brassMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		brassMat->setDiffuse(1.0f, 0.659f, 0.294f, 1.0f);
		brassMat->setSpecular(0.5f, 0.5f, 0.5f, 0.5f);
		brassMat->setShininess(20);

		Material* goldMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		goldMat->setDiffuse(0.83f, 0.69f, 0.22f, 1.0f);
		goldMat->setSpecular(0.5f, 0.5f, 0.5f, 0.5f);
		goldMat->setShininess(2.0f);

		Material* blueMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		blueMat->setDiffuse(0, 0.424f, 0.502f, 1.0f);

		Material* purpleMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		purpleMat->setDiffuse(0.337f, 0.184f, 0.494f, 1.0f);
		purpleMat->setSpecular(0.5f, 0.5f, 0.5f, 0.5f);
		purpleMat->setShininess(2.0f);

		Material* brownMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		brownMat->setDiffuse(0.4f, 0.26f, 0.13f, 1.0f);


		// Task 1: Animated Movie 50%

		// Composites
		Robot* robot = new Robot(this, whiteMat, brassMat, silverMat, gunmetalMat);
		robot->getTransform()->setParent(root);

		Drone* drone = new Drone(this, silverMat, gunmetalMat);
		drone->getTransform()->setParent(root);


		// Sweeps
		Hat* hat = new Hat(this);
		hat->getTransform()->setParent(root);
		hat->setMaterial(purpleMat);

		Hat* hatOld = new Hat(this);
		hatOld->getTransform()->setParent(root);
		hatOld->setMaterial(brownMat);


		// Enviornment objects
		GameObject* sidewalkA = new GameObject(this);
		sidewalkA->setMesh(new Cube(1.0));
		sidewalkA->getTransform()->setLocalScale(Vector3(40, 0.2f, 2));
		sidewalkA->getTransform()->setParent(root);
		sidewalkA->setMaterial(whiteMat);

		GameObject* sidewalkB = new GameObject(this);
		sidewalkB->setMesh(new Cube(1.0));
		sidewalkB->getTransform()->setLocalScale(Vector3(40, 0.2f, 2));
		sidewalkB->getTransform()->setParent(root);
		sidewalkB->setMaterial(whiteMat);

		GameObject* road = new GameObject(this);
		road->setMesh(new Cube(1.0));
		road->getTransform()->setLocalScale(Vector3(40, 0.1f, 4));
		road->getTransform()->setParent(root);
		road->setMaterial(gunmetalMat);

		GameObject* hatShop = new GameObject(this);
		hatShop->setMesh(new Cube(1.0));
		hatShop->getTransform()->setLocalScale(Vector3(8, 0.2f, 4));
		hatShop->getTransform()->setParent(root);
		hatShop->setMaterial(blueMat);

		GameObject* emptyShop = new GameObject(this);
		emptyShop->setMesh(new Cube(1.0));
		emptyShop->getTransform()->setLocalScale(Vector3(8, 0.2f, 4));
		emptyShop->getTransform()->setParent(root);
		emptyShop->setMaterial(blueMat);

		GameObject* shopPillar = new GameObject(this);
		shopPillar->setMesh(new Cylinder(0.5, 1.25, 6));
		shopPillar->getTransform()->setParent(root);
		shopPillar->setMaterial(goldMat);

		GameObject* camera = new GameObject(this);
		renderer->camera =
			new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
		camera->getTransform()->setLocalPosition(Vector3(6, 4, 6));
		camera->getTransform()->setLocalRotation(Quaternion(Vector3(-DEG_45 / 2, DEG_45, 0)));
		camera->setCamera(renderer->camera);
		camera->getTransform()->setParent(robot->getTransform());
		camera->getTransform()->name = "Camera";
		/*camera->getTransform()->setParent(root);
		camera->addComponent(new KeyboardController());*/

		// Create animations
		float animationLength = 60.0f;

		Animation* hatAnim = new Animation(animationLength);
		hat->addComponent(hatAnim);
		Animation* hatOldAnim = new Animation(animationLength);
		hatOld->addComponent(hatOldAnim);
		Animation* robotAnim = new Animation(animationLength);
		robot->addComponent(robotAnim);
		Animation* droneAnim = new Animation(animationLength);
		drone->addComponent(droneAnim);

		// Set environment positions
		sidewalkA->getTransform()->setLocalPosition(Vector3(0, -2.25, -6));
		sidewalkB->getTransform()->setLocalPosition(Vector3(0, -2.25, 6));
		road->getTransform()->setLocalPosition(Vector3(0, -2.35f, 0));
		hatShop->getTransform()->setLocalPosition(Vector3(-13, -2.25, -12));
		emptyShop->getTransform()->setLocalPosition(Vector3(13, -2.25, -12));
		shopPillar->getTransform()->setLocalPosition(Vector3(-13, -1, -11.25));

		// Set animation keyframes
		float robotRotX = 0;
		float robotRotY = 0;
		float robotRotZ = 0;
		float animStep = 0;

		// Initial start position <0s>
		robotAnim->addKey("Robot", animStep = 0, robot->getTransform()->getQuaternion(), Vector3(-25, 0, -6));
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX = 0, robotRotY = DEG_90, robotRotZ = 0)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Neck", animStep, Quaternion(Vector3(0, 0, 0)), robot->neckJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->leftWristJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->rightWristJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Hip", animStep, Quaternion(Vector3(0, 0, 0)), robot->hipJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Knee", animStep, Quaternion(Vector3(0, 0, 0)), robot->kneeJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Ankle", animStep, Quaternion(Vector3(0, 0, 0)), robot->ankleJoint->getTransform()->getLocalPosition());
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 1.25, -11.25));
		hatOldAnim->addKey("Hat", animStep, hatOld->getTransform()->getQuaternion(), Vector3(-25, 2.25, -6));
		droneAnim->addKey("Drone", animStep, drone->getTransform()->getQuaternion(), Vector3(0, 0, -15));

		// Walk to shop <4s>
		robotAnim->addKey("Robot", animStep += 4, robot->getTransform()->getQuaternion(), Vector3(-13, 0, -6));
		hatOldAnim->addKey("Hat", animStep, hatOld->getTransform()->getQuaternion(), Vector3(-13, 2.25, -6));

		// Turn and enter shop <2s>
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Origin", animStep += 1, Quaternion(Vector3(robotRotX, robotRotY += DEG_90, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Robot", animStep += 1, robot->getTransform()->getQuaternion(), Vector3(-13, 0, -10));
		hatOldAnim->addKey("Hat", animStep, hatOld->getTransform()->getQuaternion(), Vector3(-13, 2.25, -10));

		// Swap hats <4s>
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->leftWristJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->rightWristJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("LeftShoulder", animStep += 0.5, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, DEG_90, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftWrist", animStep, Quaternion(Vector3(DEG_45, 0, 0)), robot->leftWristJoint->getTransform()->getLocalPosition());
		hatOldAnim->addKey("Hat", animStep, hatOld->getTransform()->getQuaternion(), Vector3(-13, 2.25f, -10));

		robotAnim->addKey("LeftShoulder", animStep += 0.2f, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, DEG_90, DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftWrist", animStep, Quaternion(Vector3(DEG_45, 0, 0)), robot->leftWristJoint->getTransform()->getLocalPosition());
		hatOldAnim->addKey("Hat", animStep, Quaternion(Vector3(0, 0, DEG_90)), Vector3(-14, 2.5f, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_180)), Vector3(-15, 1.5f, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_270)), Vector3(-16, 1, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_360)), Vector3(-17, 0.5f, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, 0)), Vector3(-18, 0, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_45)), Vector3(-18.5f, -0.5f, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_90)), Vector3(-19, -1, -10));
		hatOldAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, DEG_180)), Vector3(-19.5f, -2, -10));

		robotAnim->addKey("RightShoulder", animStep += 0.5f, Quaternion(Vector3(-DEG_90, DEG_180, DEG_90)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45 / 2, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightWrist", animStep, Quaternion(Vector3(-DEG_45, 0, 0)), robot->rightWristJoint->getTransform()->getLocalPosition());
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 1.25f, -11.25f));

		robotAnim->addKey("RightShoulder", animStep += 0.2f, Quaternion(Vector3(-DEG_90, DEG_180, DEG_90)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightWrist", animStep, Quaternion(Vector3(-DEG_45, 0, 0)), robot->rightWristJoint->getTransform()->getLocalPosition());
		hatAnim->addKey("Hat", animStep, Quaternion(Vector3(DEG_90, 0, 0)), Vector3(-13, 1.5f, -11.25f));
		hatAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(DEG_180, 0, 0)), Vector3(-13, 2.5f, -11));
		hatAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(DEG_270, 0, 0)), Vector3(-13, 3, -10.5f));
		hatAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(DEG_360, 0, 0)), Vector3(-13, 3.5f, -10));
		hatAnim->addKey("Hat", animStep += 0.1f, Quaternion(Vector3(0, 0, 0)), Vector3(-13, 2.25f, -10));

		robotAnim->addKey("LeftShoulder", animStep += 0.5f, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->leftWristJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightWrist", animStep, Quaternion(Vector3(0, 0, 0)), robot->rightWristJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("Robot", animStep += 1, robot->getTransform()->getQuaternion(), Vector3(-13, 0, -10));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 2.25, -10));

		// Turn and exit shop <3s>
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Origin", animStep += 1, Quaternion(Vector3(robotRotX, robotRotY -= DEG_180, robotRotZ)), robot->origin->getTransform()->getLocalPosition());

		robotAnim->addKey("Robot", animStep += 2, robot->getTransform()->getQuaternion(), Vector3(-13, 0, -6));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 2.25, -6));

		// Stike a pose <3.5s>
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 2.25, -6));

		robotAnim->addKey("LeftShoulder", animStep += 1.5, Quaternion(Vector3(0, 0, DEG_90)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(0, 0, -DEG_135)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, 0, DEG_90)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(0, 0, -DEG_135)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("LeftShoulder", animStep += 1, Quaternion(Vector3(0, 0, DEG_90)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(0, 0, -DEG_135)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, 0, DEG_90)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(0, 0, -DEG_135)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("LeftShoulder", animStep += 1, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY += DEG_90, robotRotZ)), robot->origin->getTransform()->getLocalPosition());

		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(-13, 0, -6));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-13, 2.25, -6));

		// Walk towards dumpster <3s>
		robotAnim->addKey("Robot", animStep += 3, robot->getTransform()->getQuaternion(), Vector3(-1, 0, -6));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(-1, 2.25, -6));

		// Drone ambush <2.5s>
		droneAnim->addKey("Drone", animStep, drone->getTransform()->getQuaternion(), Vector3(0, 0, -15));
		droneAnim->addKey("Drone", animStep += 1, drone->getTransform()->getQuaternion(), Vector3(0, 3, -15));
		droneAnim->addKey("Drone", animStep += 1, drone->getTransform()->getQuaternion(), Vector3(5, 4, -6));
		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(5, 0, -6));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(5, 2.25, -6));

		droneAnim->addKey("Drone", animStep += 0.5f, drone->getTransform()->getQuaternion(), Vector3(5, 14, -6));
		hatAnim->addKey("Hat", animStep, hat->getTransform()->getQuaternion(), Vector3(5, 12.25, -6));

		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());

		// Turn in suprise <1s>
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, DEG_90, DEG_45)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(DEG_45, 0, -DEG_45)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, DEG_180, DEG_135)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(-DEG_45, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Origin", animStep, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());

		robotAnim->addKey("Origin", animStep += 1, Quaternion(Vector3(robotRotX, robotRotY -= DEG_180, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, 0, DEG_45 / 2)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(0, 0, 0)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, 0, DEG_135 + DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(0, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		// Slump into sadness <2s>
		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(0, 0, DEG_45 / 2)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(0, 0, 0)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(0, 0, DEG_135 + DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(0, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Hip", animStep, Quaternion(Vector3(0, 0, 0)), robot->hipJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Knee", animStep, Quaternion(Vector3(0, 0, 0)), robot->kneeJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Ankle", animStep, Quaternion(Vector3(0, 0, 0)), robot->ankleJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("Origin", animStep += 2, Quaternion(Vector3(robotRotX += DEG_45 / 2, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(0, -0.15f, -6));
		robotAnim->addKey("Hip", animStep, Quaternion(Vector3(-DEG_45 / 2, 0, 0)), robot->hipJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Knee", animStep, Quaternion(Vector3(0, 0, 0)), robot->kneeJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Ankle", animStep, Quaternion(Vector3(0, 0, 0)), robot->ankleJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("LeftShoulder", animStep, Quaternion(Vector3(-DEG_45 / 2, 0, DEG_45 / 2)), robot->leftShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("LeftElbow", animStep, Quaternion(Vector3(-DEG_45 / 2, 0, 0)), robot->leftElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(DEG_45 / 2, 0, DEG_135 + DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45 / 2, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		// Walk back to shop <8.5s>
		robotAnim->addKey("Origin", animStep += 0.5f, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(0, -0.15f, -6));

		robotAnim->addKey("Robot", animStep += 8, robot->getTransform()->getQuaternion(), Vector3(-13, -0.15f, -6));

		// Dismiss old hat <2.2s>
		robotAnim->addKey("Origin", animStep += 0.5f, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(-13, -0.15f, -6));
		robotAnim->addKey("Neck", animStep, Quaternion(Vector3(0, 0, 0)), robot->neckJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep, Quaternion(Vector3(DEG_45 / 2, 0, DEG_135 + DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45 / 2, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("Neck", animStep += 0.5f, Quaternion(Vector3(-DEG_45 / 2, -DEG_45 / 2, 0)), robot->neckJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightShoulder", animStep += 0.5f, Quaternion(Vector3(DEG_45 / 2, 0, DEG_45)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45 / 4, 0, -DEG_45)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("RightShoulder", animStep += 0.2f, Quaternion(Vector3(DEG_45 / 2, 0, DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45 / 2, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());

		robotAnim->addKey("RightShoulder", animStep += 0.5f, Quaternion(Vector3(DEG_45 / 2, 0, DEG_135 + DEG_45 / 2)), robot->rightShoulderJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("RightElbow", animStep, Quaternion(Vector3(DEG_45 / 2, 0, 0)), robot->rightElbowJoint->getTransform()->getLocalPosition());
		robotAnim->addKey("Neck", animStep, Quaternion(Vector3(0, 0, 0)), robot->neckJoint->getTransform()->getLocalPosition());

		// Walk out of scene <8.5s>
		robotAnim->addKey("Origin", animStep += 0.5f, Quaternion(Vector3(robotRotX, robotRotY, robotRotZ)), robot->origin->getTransform()->getLocalPosition());
		robotAnim->addKey("Robot", animStep, robot->getTransform()->getQuaternion(), Vector3(-13, -0.15f, -6));

		robotAnim->addKey("Robot", animStep += 8, robot->getTransform()->getQuaternion(), Vector3(-30, -0.15f, -6));


		// Execute the animation
		robotAnim->loop(true);
		robotAnim->play();

		droneAnim->loop(true);
		droneAnim->play();

		hatAnim->loop(true);
		hatAnim->play();

		hatOldAnim->loop(true);
		hatOldAnim->play();


		// Task 2: Textured Object 15%
		Texture* dumpsterTex = new Texture("Resources/dumpster.png", true, true);
		renderer->loadTexture(dumpsterTex);
		Material* dumpsterMat = renderer->createMaterial(Renderer::PR_OPAQUE);
		dumpsterMat->setTexture(dumpsterTex);

		GameObject* dumpster = new GameObject(this);
		dumpster->setMesh(new Dumpster(4));
		dumpster->getTransform()->setLocalPosition(Vector3(0, 0, -11));
		dumpster->getTransform()->setParent(root);
		dumpster->setMaterial(dumpsterMat);


		// Task 3: Shader 10%
		// Task 4: Programming Extension 25%


		// Task 5: Extended Movie 25%

		// Music: Memories, royalty free music from Bensound
		backgroundMusic = this->soundManager->createMusic("Resources/bensound-memories.mp3");
		backgroundMusic->play();
		// For the additional animated composite, see Task 1: Drone


		return true;
	}
}