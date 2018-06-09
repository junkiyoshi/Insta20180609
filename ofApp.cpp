#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	float len = 720;

	this->cam.begin();
	ofRotateX(90);

	for (int z = 0; z <= len; z += 25) {

		for(int line = 0; line < 180; line++){
		
			ofPoint p1 = this->make_rect_point(len, ofGetFrameNum() + z + line, z - len * 0.5);
			ofPoint p2 = this->make_rect_point(len, ofGetFrameNum() + z + line + 1, z - len * 0.5);

			ofSetColor(239, ofMap(line, 0, 120, 0, 255));
			ofDrawLine(p1, p2);
		}

		ofDrawSphere(this->make_rect_point(len, ofGetFrameNum() + z + 180, z - len * 0.5), 5);
	}

	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg, int z) {

	int half_len = len * 0.5;
	int param = (deg + 45) / 90;

	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(half_len, ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), z);
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), half_len, z);
	case 2:

		return ofPoint(-half_len, ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), z);
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), -half_len, z);
	default:

		return ofPoint(0, 0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}