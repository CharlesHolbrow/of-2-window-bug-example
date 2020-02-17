#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableDepthTest();

    c1.setFarClip(50);
    c1.setNearClip(6);
    c1.setVFlip(true);
    c1.setLensOffset({-1, 0});

    c2.setFarClip(50);
    c2.setNearClip(6);
    c2.setVFlip(true);
    c2.setLensOffset({1, 0});

    cam.setDistance(100);

    left.allocate(300, 300);
    right.allocate(300, 300);
    left.begin();
    ofClear(0, 0, 0, 255);
    left.end();
    right.begin();
    ofClear(0, 0, 0, 255);
    right.end();
}

void ofApp::setupComposite(){

}

//--------------------------------------------------------------
void ofApp::update(){
    float t = ofGetElapsedTimef();
    node.setPosition(sin(t) * 50, cos(t*1.3) * 10, -40);
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0, 0, 0, 255);
    ofPushStyle();
    cam.begin();
    ofSetColor(255, 100, 100);
    c1.draw();
    c1.drawFrustum();
    ofSetColor(10, 155, 10);
    c2.draw();
    c2.drawFrustum();
    node.draw();
    cam.end();
    ofPopStyle();
}

void ofApp::drawComposite(ofEventArgs & args) {
    ofSetColor(50, 0, 0, 255);
    ofPushStyle();

    left.begin(); // Calls push style
    ofClear(0, 0, 0, 255);
    c1.begin();
    node.draw();
    c1.end();
    left.end(); // Calls Pop style

    // The color set at the top of this method has been replaced by whatever
    // color was set when ofApp::draw() returned. Note that this does not happen
    // if this same block of code were in the the main draw function.
    // I suspect that this is because you are not supposed to use nested FBOs
    // and an fbo is effectively pushed for this secondary window.

    right.begin();
    ofClear(0, 0, 0, 255);
    c2.begin();
    node.draw();
    c2.end();
    right.end();


    ofSetColor(255, 255, 255, 255);
    left.draw(0, 0);
    right.draw(300, 0);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
