#pragma once
#include "ofMain.h"
#include "ps3eye.h"

// #define FPS 83
#define FPS 60
#define VGA

#ifdef VGA
	#define CAMW 640
	#define CAMH 480
#else
	#define CAMW 320
	#define CAMH 240
#endif

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	
	glm::vec2 camDimensions = { CAMW, CAMH };
	
	ofPixels pixels;
	ofTexture videoTexture;
	
//	unsigned char * videoFrame;
	unsigned char videoFrame [ CAMW * CAMH * 3];

};
