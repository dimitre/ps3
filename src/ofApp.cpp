#include "ofApp.h"

using namespace ps3eye;
	ps3eye::PS3EYECam::PS3EYERef eye;

void ofApp::setup(){
	ofSetFrameRate(0);
	ofSetVerticalSync(false);
	pixels.allocate(camDimensions.x, camDimensions.y, OF_IMAGE_COLOR);
	unsigned char * videoFrame [CAMW * CAMH * 3];
	const auto & devices( PS3EYECam::getDevices() );
	
	cout << "devices size:  " << devices.size() << endl;
	// if(devices.size()) {
		
	// 	for (const auto & device : devices) {
	// 		eye = device;
	// 		bool ok = eye->init(camDimensions.x, camDimensions.y, FPS, PS3EYECam::EOutputFormat::RGB);
	// 		if (ok) {
	// 			videoTexture.allocate(camDimensions.x, camDimensions.y, GL_RGB);
	// 			eye->start();
	// 		} else {
	// 		}
	// 	}
	// }
}

void ofApp::update(){
	// if (eye) {
	// 	eye->getFrame(pixels.getData());
	// }
}

void ofApp::draw(){
	// videoTexture.loadData(pixels);
	// videoTexture.draw(0,0,eye->getWidth(),eye->getHeight());
}

void ofApp::keyPressed(int key) {
}

void ofApp::exit(){
	// You should stop before exiting
	// otherwise the app will keep working
//	if(eye) eye->stop();
//	delete[] videoFrame;
}
