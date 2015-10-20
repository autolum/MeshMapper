//
//  IAMesh.cpp
//  MeshMapper
//
//  Created by plutots on 19/06/15.
//
//

#include "IOMesh.h"
//#include "homography.h"

IOMesh::IOMesh(){
    
    OUTQuad = new IAQuad;
    nx = 1;
    ny = 1;
    
   // OUTQuad->perspective = false;
    
    iaverts.disableAllEvents();
    
    ofMesh mesh;
    
}

IOMesh::~IOMesh(){
    
    delete OUTQuad;

}

void IOMesh::init(int _nx,int _ny){
    
    nx = _nx;
    ny = _ny;
    iaverts.clear();
    
    float dx = (OUTQuad->getIAVertex(3)->x-OUTQuad->getIAVertex(0)->x)/nx;
    float dy = (OUTQuad->getIAVertex(1)->y-OUTQuad->getIAVertex(0)->y)/ny;
    float xo = OUTQuad->getIAVertex(0)->x;
    float yo = OUTQuad->getIAVertex(0)->y;
    float dxm = ofGetWidth()/nx;
    float dym = ofGetHeight()/ny;
    
    
    for (int j = 0; j < ny+1; ++j){
        for (int i = 0; i < nx+1; ++i){
            float py = j*dy+yo;
            float px = i*dx+xo;
            iaverts.addIAVertex(px, py);
            mesh.addVertex(ofVec3f(px,py,0.0));
            mesh.addTexCoord(ofVec2f(i*dxm, j*dym));
            
      
    }}
    
    for (int j = 0; j < ny; ++j){
        for (int i = 0; i < nx; ++i){
            int tl = j*(nx+1)+i;
            int tr = j*(nx+1)+i+1;
            int bl = (j+1)*(nx+1)+i;
            int br = (j+1)*(nx+1)+i+1;
            
            if(i%2==0){
                mesh.addTriangle(tl, bl, tr);
                mesh.addTriangle(tr, bl, br);
            }
            else {
                mesh.addTriangle(tl, bl, br);
                mesh.addTriangle(tl, br, tr);
            }
        }
    }
    
    
    
    iaverts.disableAllEvents();
    iaverts.setsize(8);
    
}

void IOMesh::transformOut(){
    
    
    float dx = (OUTQuad->getIAVertex(3)->x-OUTQuad->getIAVertex(0)->x)/nx;
    float dy = (OUTQuad->getIAVertex(1)->y-OUTQuad->getIAVertex(0)->y)/ny;
    float xo = OUTQuad->getIAVertex(0)->x;
    float yo = OUTQuad->getIAVertex(0)->y;
    
    //inVerts.resize((nx+1)*(ny+1));
    if(OUTQuad->perspective == false){
    for (int j = 0; j < ny+1; ++j){
        for (int i = 0; i < nx+1; ++i){
            float py = j*dy+yo;
            float px = i*dx+xo;
            iaverts.iaverts[i+j*(nx+1)]->x = px;
            iaverts.iaverts[i+j*(nx+1)]->y = py;
        }}
    }
    
       else if(OUTQuad->perspective == true){
           float dx = (OUTQuad->getIAVertex(3)->x-OUTQuad->getIAVertex(0)->x)/nx;
           float dy = (OUTQuad->getIAVertex(1)->y-OUTQuad->getIAVertex(0)->y)/ny;
           float xo = OUTQuad->getIAVertex(0)->x;
           float yo = OUTQuad->getIAVertex(0)->y;
           for (int j = 0; j < ny+1; ++j){
               for (int i = 0; i < nx+1; ++i){
                   float py = j*dy+yo;
                   float px = i*dx+xo;
                   ofPoint point(px,py);
                   ofPoint pointInScreen = ofxHomography::toScreenCoordinates(point, OUTQuad->homograph);
                   iaverts.iaverts[i+j*(nx+1)]->x = pointInScreen.x;
                   iaverts.iaverts[i+j*(nx+1)]->y = pointInScreen.y;
               }}
     }
    
}

void IOMesh::drawOutput(){
    OUTQuad->draw();
}

void IOMesh::updateMesh(){
    
    for(int i = 0; i < iaverts.iaverts.size(); ++i){
        float x = iaverts.iaverts[i]->x;
        float y = iaverts.iaverts[i]->y;
        mesh.setVertex(i, ofVec3f(x,y,0.0));
    }
    
}

void IOMesh::clearMesh(){
    mesh.clear();
}

void IOMesh::update(){
    iaverts.update();
    OUTQuad->update();
    if(OUTQuad->enabled) transformOut();
    updateMesh();
}

void IOMesh::save(){
    mapXML.addTag("positions");
    mapXML.pushTag("positions");
    //points is a vector<ofPoint> that we want to save to a file
    for(int i = 0; i < iaverts.iaverts.size(); i++){
        //each position tag represents one point
        mapXML.addTag("position");
        mapXML.pushTag("position",i);
        float x = iaverts.iaverts[i]->x;
        float y = iaverts.iaverts[i]->y;
        //so set the three values in the file
        mapXML.addValue("X", x);
        mapXML.addValue("Y", y);
        mapXML.popTag();//pop position
    }
    mapXML.popTag(); //pop position
    mapXML.saveFile("map.xml");
}

void IOMesh::load(){
    
    OUTQuad->enabled = false;
    iaverts.enable();
    iaverts.enableMouseEvents();
    iaverts.enableKeyEvents();
    
    if(mapXML.loadFile("map.xml")){
        mapXML.pushTag("positions");
        int numberOfSavedPoints = mapXML.getNumTags("position");
        for(int i = 0; i < iaverts.iaverts.size(); i++){
            mapXML.pushTag("position", i);
            ofPoint p;
            iaverts.iaverts[i]->x = mapXML.getValue("X", 0);
            iaverts.iaverts[i]->y = mapXML.getValue("Y", 0);
            mapXML.popTag();
        }
        mapXML.popTag(); //pop position
    }
}


