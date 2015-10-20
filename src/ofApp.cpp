#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // int nx = 8;
   // int ny = 8;
    
    ofSetFrameRate(60);
    Datgui = new ofxDatGui( 10, 10 );
    Datgui->addHeader("::MeshMapper::");
    ofxDatGuiFolder* folder = Datgui->addFolder("SETUP [s=save || l=load || f=Fullscreen]", ofColor::red);
    folder->addSlider("MESHRES X", 2, 50, 5);
    folder->addSlider("MESHRES Y", 2, 50, 5);
    folder->addButton("SET MESHRESOLUTION");
    folder->addToggle("PERSPECTIVE", false);
    folder->addToggle("EDIT VERTICES", false);
    folder->addToggle("SHOW INPUT", false);
    folder->addToggle("PROJECTION MODE", false);
    Datgui->onButtonEvent(this, &ofApp::onButtonEvent);
    Datgui->onSliderEvent(this, &ofApp::onSliderEvent);
    Datgui->setOpacity(0.5);
    
    //quad = new IAQuad;
    mapMesh = new IOMesh;
    meshX = 4;
    meshY = 4;
    mapMesh->init(meshX, meshY);
    editVtcs = false;
    
    syphonClient.setup();
    syphonClient.set("Composition", "Arena");
    
    ofBackground(0,43,54);
    
    syFbo.allocate(1024,768);
   // syFbo.getTextureReference().getTextureData().bFlipTexture = true;

 
    proMode = false;
    inputMode = true;
    
    syFbo.begin();
        ofClear(0);
    syFbo.end();
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
    Datgui->update();
    mapMesh->update();
    mapMesh->iaverts.update();
  
    /*
    syFbo.begin();
        syphonClient.draw(0, 0);
    syFbo.end();
    */

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    if (!proMode) ofBackground(0,43,54);
    
    
    syFbo.begin();
        ofBackground(0);
        syphonClient.draw(0,0,syFbo.getWidth(),syFbo.getHeight());
    syFbo.end();
    
    
    syFbo.getTexture().bind();
    if (inputMode) mapMesh->mesh.draw();
    syFbo.getTexture().unbind();
    
    
    if(!proMode){
    mapMesh->mesh.drawWireframe();
    
    //syphonClient.draw(0, 0);
    
    mapMesh->drawOutput();
    
    mapMesh->iaverts.draw();
    }
    //gui.draw();
}
//--------------------------------------------------------------
void ofApp::setmesh(){
    mapMesh->clearMesh();
    mapMesh->init(meshX, meshY);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

    
    if(key == 'f'){
        ofToggleFullscreen();
    }
 
    
    if(key == 's'){
        mapMesh->save();
    }

    if(key == 'l'){
        mapMesh->load();
    }
 
}
//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if(e.target->getLabel() == "SET MESHRESOLUTION") setmesh();
    else if(e.target->is("PERSPECTIVE")){
        if(e.target->getEnabled()==true){
            mapMesh->OUTQuad->perspective = true;}
        else if(e.target->getEnabled()==false){
            mapMesh->OUTQuad->perspective = false;}
        }
    else if(e.target->is("EDIT VERTICES")){
        if(e.target->getEnabled()==true){
            mapMesh->OUTQuad->enabled = false;
            mapMesh->iaverts.enable();
            mapMesh->iaverts.enableMouseEvents();
            mapMesh->iaverts.enableKeyEvents();
        }
        else if(e.target->getEnabled()==false){
            mapMesh->OUTQuad->enabled = true;
            mapMesh->iaverts.disable();
            mapMesh->iaverts.disableAllEvents();
        }
    }
    else if(e.target->is("SHOW INPUT")){
        if(e.target->getEnabled()==true){
            inputMode = true;
    }
        else if (e.target->getEnabled() == false){
            inputMode = false;
        }
        }
    else if(e.target->is("PROJECTION MODE")){
        if(e.target->getEnabled()==true){
            proMode = true;
        }
        else if (e.target->getEnabled() == false){
            proMode = false;
        }
    }
    }

//--------------------------------------------------------------
void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    if (e.target->getLabel() == "MESHRES X"){
        meshX = e.target->getValue(); meshX = meshX -1;  }
    else if (e.target->getLabel() == "MESHRES Y"){
        meshY = e.target->getValue(); meshY = meshY -1;  }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}