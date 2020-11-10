/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Letter 'r' mesh - Exam Content
*/

#ifndef EXAM_Q3_MESH_H
#define EXAM_Q3_MESH_H

#include "Mesh.h"
#include <math.h>

namespace T3D {

	class ExamQ3Mesh2 : public Mesh {
	public:
		ExamQ3Mesh2(float radius, float width, int density);

		~ExamQ3Mesh2(void);
	};
}
#endif