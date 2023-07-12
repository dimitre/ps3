#include "ofMain.h"
#include "ofApp.h"

#define WINDOWWIDTH 1280
#define WINDOWHEIGHT 920

//#include "MultiWindow2022.h"


////========================================================================
int main( ){

	ofWindowSettings settings;
	settings.setSize(WINDOWWIDTH, WINDOWHEIGHT);
	settings.windowMode = OF_WINDOW;

	auto mainWindow = ofCreateWindow(settings);
	auto mainApp = make_shared<ofApp>();

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
