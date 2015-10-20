//
//  IAVertex.cpp
//  MeshMapper
//
//  Created by plutots on 17/06/15.
//
//

#include "IAVertex.h"
#include "constants.h"

IAVertex* IAVertex::activeIAVertex = NULL;

IAVertex::IAVertex(){
    size = 20;
    drag = false;
    enabled = true;
    disableAllEvents();
    enableMouseEvents();
    enableKeyEvents();
    activeIAVertex = NULL;
    mouse_anchorY = 0;
    mouse_anchorX = 0;
    x = 0;
    y = 0;
}

IAVertex::~IAVertex(){
    disableAllEvents();
}


void IAVertex::set(float ix, float iy){
    x = ix;
    y = iy;
}

bool IAVertex::hitTest(int tx, int ty) const {
    return (((x-tx)*(x-tx)+(y-ty)*(y-ty)) < size*size*0.25);
}

void IAVertex::setup() {
    enableMouseEvents();
    enableKeyEvents();
}

void IAVertex::update() {
    if(drag){
        x = getMouseX() + mouse_anchorX;
        y = getMouseY() + mouse_anchorY;
    }
    if(depth){
        
        z = getMouseY() + mouse_anchorY;
    }
}

void IAVertex::draw() {
    ofPushStyle();
    ofSetLineWidth(2);
    ofNoFill();
    ofSetCircleResolution(32);
    if(activeIAVertex == this){
        ofSetHexColor(DOWN_COLOR);
        ofLine(x, 0, x, ofGetHeight());
        ofLine(0, y, ofGetWidth(), y);
    }
    else if(isMouseOver()) ofSetHexColor(OVER_COLOR);
    else ofSetHexColor(IDLE_COLOR);
    ofCircle(x,y,size*0.5);
    ofPopStyle();
}


void IAVertex::onRollOver(int x, int y)
{
}

void IAVertex::onRollOut()
{
}

void IAVertex::onMouseMove(int x, int y)
{
}

void IAVertex::onDragOver(int x, int y, int button) {
    if (activeIAVertex == this){
        if(button == OF_MOUSE_BUTTON_LEFT){
        //this->x = x + mouse_anchorX;
        //this->y = y + mouse_anchorY;
            drag = true;}
        else if(button == OF_MOUSE_BUTTON_RIGHT){
            depth = true;}
        }
}


void IAVertex::onDragOutside(int x, int y, int button) {
    if (activeIAVertex == this){
        //this->x = x + mouse_anchorX;
        //this->y = y + mouse_anchorY;
        if(button == OF_MOUSE_BUTTON_LEFT){

        drag = true;
        }
        else if(button == OF_MOUSE_BUTTON_RIGHT){
            depth = true;}
    }
}

void IAVertex::onPress(int x, int y, int button) {
    activeIAVertex = this;
    //mouse_anchorX = IAVertex::x - x;
    //mouse_anchorY = IAVertex::y - y;;
}

void IAVertex::onPressOutside(int x, int y, int button) {
    if (activeIAVertex == this) activeIAVertex = NULL;
}

void IAVertex::onRelease(int x, int y, int button) {
    drag = false;
}

void IAVertex::keyPressed(int key){
    if (activeIAVertex == this){
        if (key == OF_KEY_LEFT) {
            --x;
        }
        if (key == OF_KEY_RIGHT) {
            ++x;
        }
        if (key == OF_KEY_UP) {
            ++y;
        }
        if (key == OF_KEY_DOWN) {
            --y;
        }
    }
}