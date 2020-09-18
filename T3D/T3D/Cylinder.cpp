/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Cylinder mesh
*/

#include "Cylinder.h"

namespace T3D {

	Cylinder::Cylinder(float radius, float height, int density) {

		// Init vertex and index arrays
		initArrays(
			density * 2 + ((density + 1) * 2),	// Number of vertices
			density * 2,						// Number of tris
			density								// Numnber of quads
		);

		// Set vertices
		float dTheta = Math::TWO_PI / density;

		for (int i = 0; i < density; i++) {
			float theta = i * dTheta;
			float x = radius * cos(theta);
			float z = radius * sin(theta);

			// Top edge
			setVertex(i, x, height, z);

			// Bottom edge
			setVertex(density + i, x, -height, z);

			// Top cap
			setVertex((density * 2) + i, x, height, z);

			// Bottom cap
			setVertex((density * 3) + i, x, -height, z);
		}

		// Top cap center
		setVertex((density * 4), 0, height, 0);

		// Bottom cap center
		setVertex((density * 4) + 1, 0, -height, 0);


		// Build tris
		for (int i = 0; i < density; i++) {
			// Top cap
			setFace(
				i,									// Face ID
				(density * 2) + (i + 1) % density,	// Next vertex
				(density * 2) + i,					// Current vertex
				(density * 4)						// Center vertex
			);

			// Bottom cap
			setFace(
				density + i,						// Face Id
				(density * 3) + i,					// Current vertex
				(density * 3) + (i + 1) % density,	// Next vertex
				(density * 4) + 1					// Center vertex
			);
		}


		// Build quads
		for (int i = 0; i < density; i++) {
			setFace(
				i,								// Face ID
				i,								// Current top vertex
				(i + 1) % density,				// Next top vertex
				density + (i + 1) % density,	// Next bottom vertex
				density + i						// Current bottom vertex
			);
		}


		// Check vertx and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}


	Cylinder::~Cylinder(void) {

	}
}