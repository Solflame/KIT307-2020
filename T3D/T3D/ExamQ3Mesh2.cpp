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

		int vStemTotal = (4 * 4);
		int vArcTotal = density * 4;
		int qStemTotal = 5;
		int qArcTotal = density * 4;


		initArrays(
			vStemTotal + vArcTotal,	// Vert
			0,	// Tri
			qStemTotal + qArcTotal	// Quad
		);

		float angle = (2 * M_PI) / density;


		// Set vertices - STEM
		int vPos = 0;

		/*for (int i = 0; i < vStemTotal / 4; i++) {
			setVertex(i, 0, 0, 0);
		}*/

		setVertex(vPos, 0, 0, 0); vPos++;
		setVertex(vPos, width, 0, 0); vPos++;
		setVertex(vPos, width, -width, 0); vPos++;
		setVertex(vPos, 0, -width, 0); vPos++;

		setVertex(vPos, 0, 0, radius); vPos++;
		setVertex(vPos, width, 0, radius); vPos++;
		setVertex(vPos, width, -width, radius); vPos++;
		setVertex(vPos, 0, -width, radius); vPos++;


		// Set Quads - STEM
		int qPos = 0;
		for (int i = 0; i < qStemTotal; i++) {

			setFace(i, i, i + 1, i + 2, i + 3);
		}


		checkArrays();
		calcNormals();
	}

	ExamQ3Mesh2::~ExamQ3Mesh2(void) {

	}
}