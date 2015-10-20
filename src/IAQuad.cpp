//
//  IAQuad.cpp
//  MeshMapper
//
//  Created by plutots on 18/06/15.
//
//

#include "IAQuad.h"

IAQuad::IAQuad(){
    
    disableAllEvents();
    enableMouseEvents();
    //enableKeyEvents();
    polygon = new ofPolyline;
    active = false;
    enabled = true;
    perspective = false;
    
    float cx = ofGetWidth()*0.5;
    float cy = ofGetHeight()*0.5;
    
    addVertex(cx-100, cy-100);
    addVertex(cx-100, cy+100);
    addVertex(cx+100, cy+100);
    addVertex(cx+100, cy-100);
    
}

IAQuad::~IAQuad(){
    
    disableAllEvents();
    polygon->clear();
    delete polygon;
    while(!iaverts.empty()) delete iaverts.back(), iaverts.pop_back();
    iaverts.clear();
}

bool IAQuad::checkConvex(){
    float asum = 0;
    for(int i = 0; i < polygon->size(); ++i){
        asum += polygon->getAngleAtIndex(i);
    }
    return (abs(asum - 360) < 1);
}

void IAQuad::constraints(){
 

    if(perspective == false){
        originalCorners[0].set(getIAVertex(0)->x,getIAVertex(0)->y);
        originalCorners[1].set(getIAVertex(1)->x,getIAVertex(1)->y);
        originalCorners[2].set(getIAVertex(2)->x,getIAVertex(2)->y);
        originalCorners[3].set(getIAVertex(3)->x,getIAVertex(3)->y);
        if(IAVertex::activeIAVertex == getIAVertex(0)){
            getIAVertex(1)->x = IAVertex::activeIAVertex->x;
            getIAVertex(3)->y = IAVertex::activeIAVertex->y;
            originalCorners[0].set(getIAVertex(0)->x,getIAVertex(0)->y);

        }
        else if(IAVertex::activeIAVertex == getIAVertex(1)){
            getIAVertex(0)->x = IAVertex::activeIAVertex->x;
            getIAVertex(2)->y = IAVertex::activeIAVertex->y;
            originalCorners[1].set(getIAVertex(1)->x,getIAVertex(1)->y);

        }
        else if(IAVertex::activeIAVertex == getIAVertex(2)){
            getIAVertex(3)->x = IAVertex::activeIAVertex->x;
            getIAVertex(1)->y = IAVertex::activeIAVertex->y;
            originalCorners[2].set(getIAVertex(2)->x,getIAVertex(2)->y);

        }
        else if(IAVertex::activeIAVertex == getIAVertex(3)){
            getIAVertex(2)->x = IAVertex::activeIAVertex->x;
            getIAVertex(0)->y = IAVertex::activeIAVertex->y;
            originalCorners[3].set(getIAVertex(3)->x,getIAVertex(3)->y);

        }
    }
    else if(perspective == true){
        distortedCorners[0].set(getIAVertex(0)->x,getIAVertex(0)->y);
        distortedCorners[1].set(getIAVertex(1)->x,getIAVertex(1)->y);
        distortedCorners[2].set(getIAVertex(2)->x,getIAVertex(2)->y);
        distortedCorners[3].set(getIAVertex(3)->x,getIAVertex(3)->y);

        if(IAVertex::activeIAVertex == getIAVertex(0)){
            distortedCorners[0].set(getIAVertex(0)->x,getIAVertex(0)->y);
        }
        else if(IAVertex::activeIAVertex == getIAVertex(1)){
            distortedCorners[1].set(getIAVertex(1)->x,getIAVertex(1)->y);
        }
        else if(IAVertex::activeIAVertex == getIAVertex(2)){
            distortedCorners[2].set(getIAVertex(2)->x,getIAVertex(2)->y);
        }
        else if(IAVertex::activeIAVertex == getIAVertex(3)){
            distortedCorners[3].set(getIAVertex(3)->x,getIAVertex(3)->y);
        }
        homograph = ofxHomography::findHomography(originalCorners, distortedCorners);
}
}
