//
//  IAVertVec.h
//  MeshMapper
//
//  Created by plutots on 19/06/15.
//
//

#ifndef __MeshMapper__IAVertVec__
#define __MeshMapper__IAVertVec__

#include "ofxMSAInteractiveObject.h"
#include "IAVertex.h"
#include "ofMain.h"


class IAVertVec {
    public:
        vector<IAVertex*> iaverts;
    
        IAVertVec();
        ~IAVertVec();
    
        void addIAVertex(float x, float y);
        void disableAllEvents();
        void enableMouseEvents();
        void enableKeyEvents();
        void disable();
        void enable();
        void draw();
        void update();
        void clear();
        void setsize(float s);
};



#endif /* defined(__MeshMapper__IAVertVec__) */
