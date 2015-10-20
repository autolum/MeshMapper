#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // int nx = 8;
   // int ny = 8;
    
    ofSetFrameRate(60);
    /*gui.setup();
    gui.setPosition(ofPoint(10,10));
    gui.add(meshX.setup("MeshX",5,1,20));
    gui.add(meshY.setup("MeshY",5,1,20));
    gui.add(setMesh.setup("setMesh",false));
    */
    Datgui = new ofxDatGui( 10, 10 );
    Datgui->addHeader("::MeshMapper::");
    Datgui->addSlider("MESH X", 2, 50, 5);
    Datgui->addSlider("MESH Y", 2, 50, 5);
    Datgui->addButton("SET MESH");
    Datgui->addToggle("PERSPECTIVE", false);
    
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
   /* if(setmesh==true){
        mapMesh->clearMesh();
        mapMesh->init(meshX, meshY);
        setmesh=false;
    }*/
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
    
    if(key == 'b'){
        mapMesh->OUTQuad->enabled = true;
        mapMesh->iaverts.disable();
        mapMesh->iaverts.disableAllEvents();
        
    }
    
    if(key == 'f'){
        ofToggleFullscreen();
    }
    
    if(key == 'v'){
        editVtcs = true;
            mapMesh->OUTQuad->enabled = false;
            mapMesh->iaverts.enable();
            mapMesh->iaverts.enableMouseEvents();
            mapMesh->iaverts.enableKeyEvents();
        
    }
    
    if(key == 's'){
        mapMesh->save();
    }

    if(key == 'l'){
        mapMesh->load();
    }
    
    if(key == 'p'){
        proMode = !proMode;
    }
    
    if(key == 'i'){
        inputMode = !inputMode;
    }
    if(key == 'o'){
        mapMesh->OUTQuad->perspective = true;
    }
}
//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if(e.target->getLabel() == "SET MESH") setmesh();
    else if(e.target->is("PERSPECTIVE")){
        if(e.target->getEnabled()==true){
            mapMesh->OUTQuad->perspective = true;}
        else if(e.target->getEnabled()==false){
            mapMesh->OUTQuad->perspective = false;}
        }
    }

//--------------------------------------------------------------
void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    if (e.target->getLabel() == "MESH X"){
        meshX = e.target->getValue(); meshX = meshX -1;  }
    else if (e.target->getLabel() == "MESH Y"){
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