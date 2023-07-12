
struct cam {

	ps3eye::PS3EYECam::PS3EYERef eye;
	unsigned char videoFrame [CAMW * CAMH * 3];
	ofTexture videoTexture;
	
	int index = 0;

	int camFrameCount = 0;
	int camFpsLastSampleFrame = 0;
	float camFpsLastSampleTime = 0;
	float camFps = 0;
	
	
	~cam() {
		if(eye) eye->stop();
//		delete[] videoFrame;
	}
	
	ofxMicroUI * uiCv = NULL;

	
	void update() {
		cout << CAMW << endl;
		cout << CAMH << endl;
		cout << "update" << endl;
		if (eye) {
			cout << "inside" << endl;

			cout << "sizeof: " << sizeof(videoFrame) << endl;
			eye->getFrame(videoFrame);
//			camFrameCount++;
//			float timeNow = ofGetElapsedTimeMillis();
//			if( timeNow > camFpsLastSampleTime + 1000 ) {
//				uint32_t framesPassed = camFrameCount - camFpsLastSampleFrame;
//				camFps = (float)(framesPassed / ((timeNow - camFpsLastSampleTime)*0.001f));
//
//				camFpsLastSampleTime = timeNow;
//				camFpsLastSampleFrame = camFrameCount;
//			}
		}
	}
	
	void draw() {
		if (eye) {
//				cout << "draw " << index << endl;
#ifdef USECOLOR
			videoTexture.loadData(videoFrame, eye->getWidth(),eye->getHeight(), GL_RGB);
#else
			videoTexture.loadData(videoFrame, eye->getWidth(),eye->getHeight(), GL_LUMINANCE);
#endif
			ofSetColor(255);
			videoTexture.draw(eye->getWidth()*index,0,eye->getWidth(),eye->getHeight());
		} else {
//				cout << "not eye " << index << endl;
		}
	}
	
	/*
	ofxCvGrayscaleImage irImg;
	ofxCv::ContourFinder finder;

	
	void updateFinder() {
		irImg.setFromPixels(videoFrame, eye->getWidth(), eye->getHeight());
		irImg.threshold(uiCv->pFloat["threshold"]);
		// nao precisaria invert se nao estivessemos usando findholes no cv
		if (uiCv->pBool["invert"]) {
			irImg.invert();
		}
		
		if (uiCv->pFloat["blurRadius"]) {
			irImg.blur(uiCv->pFloat["blurRadius"]);
		}

		finder.getTracker().setPersistence(uiCv->pInt["persistence"]);
		finder.getTracker().setMaximumDistance(uiCv->pFloat["maxDist"]);
		finder.setMinAreaRadius(uiCv->pFloat["minArea"]);
		finder.setMaxAreaRadius(uiCv->pFloat["maxArea"]);
		finder.setFindHoles(uiCv->pBool["findHoles"]);
		finder.findContours(irImg);
	}
	
	void drawFinder() {
		ofSetColor(255, 255, 0);
		irImg.draw(eye->getWidth(), 0);
		
		ofPushMatrix();
		ofSetColor(255, 0, 80);
		ofTranslate(eye->getWidth(), 0);
		finder.draw();
		
		glm::vec2 lastPoint = { 0, 0 };
		for (int i = 0; i < finder.size(); i++) {
			auto pt = finder.getCenter(i);
	//		string label = ofToString(finder.getLabel(i));
			string label = "";
	//		if (lastPoint != glm::vec2(0,0))
			{
				ofDrawLine(lastPoint.x, lastPoint.y, pt.x, pt.y);
	//			float angle = ofRadToDeg(atan2(lastPoint.y - pt.y, lastPoint.x - pt.x));
				float angle = ofRadToDeg(atan2(pt.y - lastPoint.y, pt.x - lastPoint.x));
				label += " " + ofToString(angle);
			}
			
			ofDrawBitmapString(label, pt.x, pt.y);
			lastPoint = { pt.x, pt.y };
		}
	} */
};
