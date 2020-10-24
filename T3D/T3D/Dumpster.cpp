/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Dumpster mesh for Assignment 2 - Task 2: Textured Object
*/

#include "Dumpster.h"

namespace T3D {

	Dumpster::Dumpster(float size) {

		// Initiate vertex and index arrays
		initArrays(
			(4 * 6) * 2,	// Vertices
			0,				// Triangles
			6 * 2 - 2		// Quads
		);

		int pos = 0;	// Position counter
		float half = size / 2;	// Height of the box sides
		float depth = size / 4;	// Depth of the lid

		// Set vertices - BOX
		// Back
		setVertex(pos++, -size, -half, -half);
		setVertex(pos++, size, -half, -half);
		setVertex(pos++, size, half - depth, -half);
		setVertex(pos++, -size, half - depth, -half);

		// Front
		setVertex(pos++, -size, -half, half);
		setVertex(pos++, size, -half, half);
		setVertex(pos++, size, half - depth, half);
		setVertex(pos++, -size, half - depth, half);

		// Left
		setVertex(pos++, -size, -half, -half);
		setVertex(pos++, -size, half - depth, -half);
		setVertex(pos++, -size, half - depth, half);
		setVertex(pos++, -size, -half, half);

		// Right
		setVertex(pos++, size, -half, -half);
		setVertex(pos++, size, half - depth, -half);
		setVertex(pos++, size, half - depth, half);
		setVertex(pos++, size, -half, half);

		// Bottom
		setVertex(pos++, -size, -half, -half);
		setVertex(pos++, -size, -half, half);
		setVertex(pos++, size, -half, half);
		setVertex(pos++, size, -half, -half);

		// Top
		setVertex(pos++, -size, half - depth, -half);
		setVertex(pos++, -size, half - depth, half);
		setVertex(pos++, size, half - depth, half);
		setVertex(pos++, size, half - depth, -half);


		// Set vertices - LID
		// Back
		setVertex(pos++, -size, half - depth, -half);
		setVertex(pos++, size, half - depth, -half);
		setVertex(pos++, size, half, -half);
		setVertex(pos++, -size, half, -half);

		// Front
		setVertex(pos++, -size, half - depth, half);
		setVertex(pos++, size, half - depth, half);
		setVertex(pos++, size, half, half - depth);
		setVertex(pos++, -size, half, half - depth);

		// Left
		setVertex(pos++, -size, half - depth, -half);
		setVertex(pos++, -size, half, -half);
		setVertex(pos++, -size, half, half - depth);
		setVertex(pos++, -size, half - depth, half);

		// Right
		setVertex(pos++, size, half - depth, -half);
		setVertex(pos++, size, half, -half);
		setVertex(pos++, size, half, half - depth);
		setVertex(pos++, size, half - depth, half);

		// Bottom
		setVertex(pos++, -size, half - depth, -half);
		setVertex(pos++, -size, half - depth, half);
		setVertex(pos++, size, half - depth, half);
		setVertex(pos++, size, half - depth, -half);

		// Top
		setVertex(pos++, -size, half, -half);
		setVertex(pos++, -size, half, half - depth);
		setVertex(pos++, size, half, half - depth);
		setVertex(pos++, size, half, -half);


		// Reset count
		pos = 0;

		// Set quads - BOX
		// Back
		setFace(pos++, 3, 2, 1, 0);

		// Front
		setFace(pos++, 4, 5, 6, 7);

		// Left
		setFace(pos++, 11, 10, 9, 8);

		// Right
		setFace(pos++, 12, 13, 14, 15);

		// Bottom
		setFace(pos++, 19, 18, 17, 16);

		// Top
		//setFace(pos++, 20, 21, 22, 23);	// Hidden face. Kept incase lid is opened


		// Set quads - LID
		// Back
		setFace(pos++, 27, 26, 25, 24);

		// Front
		setFace(pos++, 28, 29, 30, 31);

		// Left
		setFace(pos++, 35, 34, 33, 32);

		// Right
		setFace(pos++, 36, 37, 38, 39);

		// Bottom
		//setFace(pos++, 43, 42, 41, 40);	// Hidden face. Kept incase lid is opened

		// Top
		setFace(pos++, 44, 45, 46, 47);


		checkArrays();
		calcNormals();


		// Reset count
		pos = 0;

		// Set texture position - BOX
		// Back
		setUV(pos++, 0.5, 1);
		setUV(pos++, 1, 1);
		setUV(pos++, 1, 0.5625);
		setUV(pos++, 0.5, 0.5625);

		// Front
		setUV(pos++, 0, 0.5);
		setUV(pos++, 0.5, 0.5);
		setUV(pos++, 0.5, 0.0625);
		setUV(pos++, 0, 0.0625);

		// Left
		setUV(pos++, 0, 1);
		setUV(pos++, 0, 0.5625);
		setUV(pos++, 0.25, 0.5625);
		setUV(pos++, 0.25, 1);

		// Right
		setUV(pos++, 0.25, 1);
		setUV(pos++, 0.25, 0.5625);
		setUV(pos++, 0.5, 0.5625);
		setUV(pos++, 0.5, 1);

		// Bottom
		setUV(pos++, 0.5, 0.0625);
		setUV(pos++, 0.5, 0.5);
		setUV(pos++, 1, 0.5);
		setUV(pos++, 1, 0.0625);

		// Top
		pos = pos + 4;	// Hidden face. Kept incase lid is opened


		// Set texture position - LID
		// Back
		setUV(pos++, 0.5, 0.5625);
		setUV(pos++, 1, 0.5625);
		setUV(pos++, 1, 0.5);
		setUV(pos++, 0.5, 0.5);

		// Front
		setUV(pos++, 0, 0.0625);
		setUV(pos++, 0.5, 0.0625);
		setUV(pos++, 0.5, 0);
		setUV(pos++, 0, 0);

		// Left
		setUV(pos++, 0, 0.5625);
		setUV(pos++, 0, 0.5);
		setUV(pos++, 0.25, 0.5);
		setUV(pos++, 0.25, 0.5625);

		// Right
		setUV(pos++, 0.25, 0.5625);
		setUV(pos++, 0.25, 0.5);
		setUV(pos++, 0.5, 0.5);
		setUV(pos++, 0.5, 0.5625);

		// Bottom
		pos = pos + 4;	// Hidden face. Kept incase lid is opened

		// Top
		setUV(pos++, 0.5, 0.0625);
		setUV(pos++, 0.5, 0.5);
		setUV(pos++, 1, 0.5);
		setUV(pos++, 1, 0.0625);
	}

	Dumpster::~Dumpster(void) {
	}
}