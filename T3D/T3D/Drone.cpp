/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Drone composite for Assignment 2 - Task 1/5: Animation
*/

#include "Drone.h"

namespace T3D {

	Drone::Drone(T3DApplication* app, Material* bodyMaterial, Material* bladeMaterial) : GameObject(app) {

		float chassisHeight = 0.1f;
		float chassisRadius = 1;
		float limbLength = 0.1f;
		float limbRadius = 0.04f;
		float jointRadius = 0.1f;
		int limbDensity = 16;

		getTransform()->name = "Drone";
		this->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));


		// Define component meshes
		Cylinder* chassisMesh = new Cylinder(chassisRadius, chassisHeight, limbDensity);
		Cylinder* limbMesh = new Cylinder(limbRadius, limbLength, limbDensity);



		// Add component - Chassis
		chassis = new GameObject(app);
		chassis->setMesh(chassisMesh);
		chassis->setMaterial(bodyMaterial);
		chassis->getTransform()->setParent(getTransform());
		chassis->getTransform()->name = "Chassis";


		// Add joint - Blades
		bladeJoint = new GameObject(app);
		bladeJoint->getTransform()->setParent(chassis->getTransform());
		bladeJoint->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		bladeJoint->getTransform()->name = "BladeJoint";


		// Add component - Blades
		blade1 = new GameObject(app);
		blade1->setMesh(new Sphere(0.05f));
		blade1->setMaterial(bladeMaterial);
		blade1->getTransform()->setParent(bladeJoint->getTransform());
		blade1->getTransform()->name = "Blade1";

		blade2 = new GameObject(app);
		blade2->setMesh(new Sphere(0.05f));
		blade2->setMaterial(bladeMaterial);
		blade2->getTransform()->setParent(bladeJoint->getTransform());
		blade2->getTransform()->name = "Blade2";

		blade3 = new GameObject(app);
		blade3->setMesh(new Sphere(0.05f));
		blade3->setMaterial(bladeMaterial);
		blade3->getTransform()->setParent(bladeJoint->getTransform());
		blade3->getTransform()->name = "Blade3";


		// Add joint - Shoulders
		shoulderJoint1 = new GameObject(app);
		shoulderJoint1->getTransform()->setParent(chassis->getTransform());
		shoulderJoint1->getTransform()->setLocalPosition(Vector3(chassisRadius, 0, 0));
		shoulderJoint1->getTransform()->name = "ShoulderJoint1";

		shoulderJoint2 = new GameObject(app);
		shoulderJoint2->getTransform()->setParent(chassis->getTransform());
		shoulderJoint2->getTransform()->setLocalPosition(Vector3(-chassisRadius, 0, 0));
		shoulderJoint2->getTransform()->name = "ShoulderJoint2";

		shoulderJoint3 = new GameObject(app);
		shoulderJoint3->getTransform()->setParent(chassis->getTransform());
		shoulderJoint3->getTransform()->setLocalPosition(Vector3(0, 0, chassisRadius));
		shoulderJoint3->getTransform()->name = "ShoulderJoint3";

		shoulderJoint4 = new GameObject(app);
		shoulderJoint4->getTransform()->setParent(chassis->getTransform());
		shoulderJoint4->getTransform()->setLocalPosition(Vector3(0, 0, -chassisRadius));
		shoulderJoint4->getTransform()->name = "ShoulderJoint4";


		// Add component - Upper Arms
		upperArm1 = new GameObject(app);
		upperArm1->setMesh(limbMesh);
		upperArm1->setMaterial(bodyMaterial);
		upperArm1->getTransform()->setParent(shoulderJoint1->getTransform());
		upperArm1->getTransform()->name = "UpperArm1";

		upperArm2 = new GameObject(app);
		upperArm2->setMesh(limbMesh);
		upperArm2->setMaterial(bodyMaterial);
		upperArm2->getTransform()->setParent(shoulderJoint2->getTransform());
		upperArm2->getTransform()->name = "UpperArm2";

		upperArm3 = new GameObject(app);
		upperArm3->setMesh(limbMesh);
		upperArm3->setMaterial(bodyMaterial);
		upperArm3->getTransform()->setParent(shoulderJoint3->getTransform());
		upperArm3->getTransform()->name = "UpperArm3";

		upperArm4 = new GameObject(app);
		upperArm4->setMesh(limbMesh);
		upperArm4->setMaterial(bodyMaterial);
		upperArm4->getTransform()->setParent(shoulderJoint4->getTransform());
		upperArm4->getTransform()->name = "UpperArm4";


		// Add joint - Elbows
		elbowJoint1 = new GameObject(app);
		elbowJoint1->getTransform()->setParent(upperArm1->getTransform());
		elbowJoint1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		elbowJoint1->getTransform()->name = "ElbowJoint1";

		elbowJoint2 = new GameObject(app);
		elbowJoint2->getTransform()->setParent(upperArm2->getTransform());
		elbowJoint2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		elbowJoint2->getTransform()->name = "ElbowJoint2";

		elbowJoint3 = new GameObject(app);
		elbowJoint3->getTransform()->setParent(upperArm3->getTransform());
		elbowJoint3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		elbowJoint3->getTransform()->name = "ElbowJoint3";

		elbowJoint4 = new GameObject(app);
		elbowJoint4->getTransform()->setParent(upperArm4->getTransform());
		elbowJoint4->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		elbowJoint4->getTransform()->name = "ElbowJoint4";


		// Add component - Lower Arms
		lowerArm1 = new GameObject(app);
		lowerArm1->setMesh(limbMesh);
		lowerArm1->setMaterial(bodyMaterial);
		lowerArm1->getTransform()->setParent(elbowJoint1->getTransform());
		lowerArm1->getTransform()->name = "LowerArm1";

		lowerArm2 = new GameObject(app);
		lowerArm2->setMesh(limbMesh);
		lowerArm2->setMaterial(bodyMaterial);
		lowerArm2->getTransform()->setParent(elbowJoint2->getTransform());
		lowerArm2->getTransform()->name = "LowerArm2";

		lowerArm3 = new GameObject(app);
		lowerArm3->setMesh(limbMesh);
		lowerArm3->setMaterial(bodyMaterial);
		lowerArm3->getTransform()->setParent(elbowJoint3->getTransform());
		lowerArm3->getTransform()->name = "LowerArm3";

		lowerArm4 = new GameObject(app);
		lowerArm4->setMesh(limbMesh);
		lowerArm4->setMaterial(bodyMaterial);
		lowerArm4->getTransform()->setParent(elbowJoint4->getTransform());
		lowerArm4->getTransform()->name = "LowerArm4";
	}


	Drone::~Drone(void) {

	}
}