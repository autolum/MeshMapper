//
//  IAQuad.h
//  MeshMapper
//
//  Created by plutots on 18/06/15.
//
//

#ifndef __MeshMapper__IAQuad__
#define __MeshMapper__IAQuad__

#include "IAPolygon.h"
#include "ofMain.h"
#include "ofxHomography.h"

class IAQuad : public IAPolygon {
    
    public:
    
    bool perspective;
    
    IAQuad();
    ~IAQuad();
    
    bool checkConvex();
    void constraints();
    ofPoint originalCorners[4];
    ofPoint distortedCorners[4];
    ofMatrix4x4 homograph;
};

#endif /* defined(__MeshMapper__IAQuad__) */
