/* ========================================
 * KIT307 - Computer Graphics and Animation
 * ========================================
 *
 * Author - John Aslin
 *
 * Dumpster mesh for Assignment 2 - Task 2: Textured Object
*/

#ifndef DUMPSTER_H
#define DUMPSTER_H

#include "Mesh.h"

namespace T3D {

	class Dumpster : public Mesh {
	public:
		Dumpster(float size = 20.0f);
		~Dumpster(void);
	};
}

#endif