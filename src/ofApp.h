#pragma once

#include "ofMain.h"
#include "IAVertex.h"
#include "IAQuad.h"
#include "IOMesh.h"
#include "ofxSyphon.h"
#include "ofxGui.h"
#include "ofxDatGui.h"

#define		IDLE_COLOR		0x2aa198
#define		OVER_COLOR		0xcb4b16
#define		DOWN_COLOR		0xdc322f


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        bool editVtcs;
    
   /* ofxPanel gui;
    ofxSlider<int> meshX;
    ofxSlider<int> meshY;
    ofxToggle setMesh;
    */
    ofxDatGui* Datgui;
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onSliderEvent(ofxDatGuiSliderEvent e);
    void setmesh();
    int meshX;
    int meshY;
    
    private:
        //IAVertex dot;
        IOMesh* mapMesh;
        ofMesh mesh;
        ofxSyphonClient syphonClient;
        ofFbo syFbo;
        bool proMode;
    bool inputMode;
};
