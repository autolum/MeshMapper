//
//  IAVertVec.cpp
//  MeshMapper
//
//  Created by plutots on 19/06/15.
//
//

#include "IAVertVec.h"

IAVertVec::IAVertVec(){
    
}

IAVertVec::~IAVertVec(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        delete iaverts[i];
    }
    iaverts.clear();
}

void IAVertVec::addIAVertex(float x, float y){
    
    IAVertex* v = new IAVertex;
    v->set(x, y);
    iaverts.push_back(v);
}

void IAVertVec::disableAllEvents(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->disableAllEvents();
    }
}

void IAVertVec::enableMouseEvents(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->enableMouseEvents();
    }
}

void IAVertVec::enableKeyEvents(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->enableKeyEvents();
    }
}

void IAVertVec::disable(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->enabled = false;
    }
}

void IAVertVec::enable(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->enabled = true;
    }
}

void IAVertVec::draw(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->draw();
    }
}

void IAVertVec::setsize(float s){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->size = s;
    }
}

void IAVertVec::update(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        iaverts[i]->update();
    }
}

void IAVertVec::clear(){
    
    for(int i = 0; i < iaverts.size(); ++i){
        delete iaverts[i];
    }
    iaverts.clear();
}