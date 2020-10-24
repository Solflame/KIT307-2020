// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// main.cpp
//
// Main entry point. Creates and runs a T3DApplication

#include "T3DTest.h"
#include "Tutorial1.h"
#include "ShaderTest.h"
#include "GLTestApplication.h"
#include "Assignment2Test.h"

#ifdef main
#undef main
#endif


using namespace T3D;

int main(int argc, char* argv[]) {
	//T3DApplication *theApp = new T3DTest();
	//T3DApplication *theApp = new Tutorial1();
	//T3DApplication *theApp = new GLTestApplication();
	//T3DApplication *theApp = new ShaderTest();
	T3DApplication* theApp = new Assignment2Test();

	theApp->run();
	delete theApp;

	return 0;
}