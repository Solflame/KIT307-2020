/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Mesh classes - Exam Content
*/

#ifndef EXAM_MESH_H
#define EXAM_MESH_H

#include "Mesh.h"

namespace T3D {

	class ExamQ3Mesh1 : public Mesh {
	public:
		ExamQ3Mesh1(T3DApplication* app);
		~ExamQ3Mesh1(void);
	};


	class CylindricalSection : public Mesh {
	public:
		CylindricalSection(
			T3DApplication* app,
			float r1,
			float r2,
			float h,
			float theta,
			int density
		);

		~CylindricalSection(void);

		void setVertex(int id, int x, int y, int z);
		void setFace(int id, int a, int b, int c, int d);

		float* vertices;
		unsigned int* indices;
	};
}
#endif