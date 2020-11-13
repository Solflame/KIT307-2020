/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Letter 'r' mesh - Exam Content
*/

#define _USE_MATH_DEFINES
#include "ExamQ3Mesh2.h"


namespace T3D {

	ExamQ3Mesh2::ExamQ3Mesh2(float radius, float width, int density) {

		int vStemTotal = (4 * 2 * 2) + 4;	// Total vertices for the stem
		int vArcTotal = (4 * density) * 2;	// Total vertices for the arc
		int qStemTotal = 5;	// Total quads for the stem
		int qArcTotal = density;//4 * density;	// Total quads for the arc


		initArrays(
			vStemTotal + vArcTotal,	// Vert
			0,	// Tri
			qStemTotal //+ qArcTotal	// Quad
		);

		double dTheta = M_PI / density;


		// Set vertices - STEM
		int vPos = 0;
		float stemLeftX = -radius;
		float stemRightX = -radius + width;
		float stemBackZ = -width / 2;
		float stemFrontZ = width / 2;

		// Back left edges
		setVertex(vPos, stemLeftX, 0, stemBackZ); vPos++;	// Bottom edge
		setVertex(vPos, stemLeftX, radius, stemBackZ); vPos++;	// Top edge

		// Back right edges
		setVertex(vPos, stemRightX, 0, stemBackZ); vPos++;	// Bottom edge
		setVertex(vPos, stemRightX, radius, stemBackZ);	vPos++;	// Top edge

		// Front left edges
		setVertex(vPos, stemLeftX, 0, stemFrontZ); vPos++;	// Bottom edge
		setVertex(vPos, stemLeftX, radius, stemFrontZ); vPos++;	// Top edge

		// Front right edges
		setVertex(vPos, stemRightX, 0, stemFrontZ);	vPos++;	// Bottom edge
		setVertex(vPos, stemRightX, radius, stemFrontZ); vPos++;	// Top edge

		// Duplicate for flat texturing

		// Back left edges
		setVertex(vPos, stemLeftX, 0, stemBackZ); vPos++;	// Bottom edge
		setVertex(vPos, stemLeftX, radius, stemBackZ); vPos++;	// Top edge

		// Back right edges
		setVertex(vPos, stemRightX, 0, stemBackZ); vPos++;	// Bottom edge
		setVertex(vPos, stemRightX, radius, stemBackZ);	vPos++;	// Top edge

		// Front left edges
		setVertex(vPos, stemLeftX, 0, stemFrontZ); vPos++;	// Bottom edge
		setVertex(vPos, stemLeftX, radius, stemFrontZ); vPos++;	// Top edge

		// Front right edges
		setVertex(vPos, stemRightX, 0, stemFrontZ);	vPos++;	// Bottom edge
		setVertex(vPos, stemRightX, radius, stemFrontZ); vPos++;	// Top edge

		// Bottom left edges
		setVertex(vPos, stemLeftX, 0, stemBackZ); vPos++;	// Back edge
		setVertex(vPos, stemLeftX, 0, stemFrontZ); vPos++;	// Front edge

		// Bottom right edges
		setVertex(vPos, stemRightX, 0, stemBackZ);	vPos++;	// Back edge
		setVertex(vPos, stemRightX, 0, stemFrontZ); vPos++;	// Front edge


		// Set vertices - ARC
		for (int i = 0; i < density; i++) {
			float theta = (float)(i * dTheta);
			float arcTopX = radius * cos(theta);
			float arcBotX = (radius - width) * cos(theta);
			float arcTopY = radius + (radius * sin(theta));
			float arcBotY = radius + ((radius - width) * sin(theta));
			float arcBackZ = -width / 2;
			float arcFrontZ = width / 2;

			// Back edges
			setVertex(vPos, arcBotX, arcBotY, arcBackZ); vPos++;	// Bottom edge
			setVertex(vPos, arcTopX, arcTopY, arcBackZ); vPos++;	// Top edge

			// Front edges
			setVertex(vPos, arcBotX, arcBotY, arcFrontZ); vPos++;	// Bottom edge
			setVertex(vPos, arcTopX, arcTopY, arcFrontZ); vPos++;	// Top edge

			// Duplicate for flat texturing

			// Back edges
			setVertex(vPos, arcBotX, arcBotY, arcBackZ); vPos++;	// Bottom edge
			setVertex(vPos, arcTopX, arcTopY, arcBackZ); vPos++;	// Top edge

			// Front edges
			setVertex(vPos, arcBotX, arcBotY, arcFrontZ); vPos++;	// Bottom edge
			setVertex(vPos, arcTopX, arcTopY, arcFrontZ); vPos++;	// Top edge
		}


		// Set Quads - STEM
		int qPos = 0;

		setFace(qPos, 0, 1, 3, 2); qPos++;	// Back face
		setFace(qPos, 6, 7, 5, 4); qPos++;	// Front face
		setFace(qPos, 12, 13, 9, 8); qPos++;	// Left face
		setFace(qPos, 10, 11, 15, 14); qPos++;	// Right face
		setFace(qPos, 18, 19, 17, 16); qPos++;	// Bottom face


		// Set Quads - ARC

		for (int i = 0; i < density; i++) {
		}


		checkArrays();
		calcNormals();
	}

	ExamQ3Mesh2::~ExamQ3Mesh2(void) {

	}
}