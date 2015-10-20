//
//  IAMesh.h
//  MeshMapper
//
//  Created by plutots on 19/06/15.
//
//

#ifndef __MeshMapper__IAMesh__
#define __MeshMapper__IAMesh__

#include "IAVertVec.h"
#include "IAQuad.h"
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxHomography.h"

class IOMesh {
    
    public:
        IAQuad* OUTQuad;
        IAVertVec iaverts;
        vector<ofPoint> inVerts;
        ofMesh mesh;
       // ofMatrix4x4 hMatrix;
        IOMesh();
        ~IOMesh();
        void init(int _nx,int _ny);
        void drawInput();
        void drawOutput();
        void update();
        void transformOut();
        void cHomography();
        void updateMesh();
        void clearMesh();
        void save();
        void load();
    private:
        int nx, ny;
        ofxXmlSettings mapXML;

};

#endif /* defined(__MeshMapper__IAMesh__) */
