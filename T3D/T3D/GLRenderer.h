// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// glrenderer.h
//
// Handles rendering tasks using OpenGL

#ifndef GLRENDERER_H
#define GLRENDERER_H

#define WINDOW_WIDTH		1024
#define	WINDOW_HEIGHT		512

#include <list>
#include "renderer.h"

namespace T3D
{
	// Entry for simple display of text on screen. This is intended for diagnostic type display only
	// Messages are only displayed for current frame then deleted
	// This would be better implemented as a proper GameObject within the scene but there is currently
	// no way to manage a 2D rendering context.
	typedef struct {
		Texture *texture;
		int x,y;					// screen/window coordinates
	} overlay2D;


	class GLRenderer :
		public Renderer
	{
	public:
		GLRenderer(void);
		virtual ~GLRenderer(void);

		void prerender();
		void postrender();

		void setCamera(Camera *cam);

		void draw(GameObject* object);
		
		void loadTexture(Texture *tex, bool repeat = false);
		void reloadTexture(Texture *tex);
		void unloadTexture(Texture *tex);

		void loadSkybox(std::string tex);

		bool exists2DOverlay(Texture *texture);					// is there a existing 2D overlay using this texture?
		void add2DOverlay(Texture *texture, int x, int y);		// 2D overlay (used for on screen diagnostic messages mainly)
		void remove2DOverlay(Texture *texture);					// remove overlay

	private:
		void loadMaterial(Material* mat);
		void unloadMaterial(Material* mat);

		int GLRenderer::getTextureFormat(Texture *tex);

		void drawMesh(Mesh *mesh);
		void drawSkybox();

		void showD2DOverlays();
		void drawText();
		void draw2DMesh(overlay2D *overlay);

		std::list<overlay2D *> overlays;

	};
}

#endif
