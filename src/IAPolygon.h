//
//  IAPolygon.h
//  MeshMapper
//
//  Created by plutots on 17/06/15.
//
//

#ifndef __MeshMapper__IAPolygon__
#define __MeshMapper__IAPolygon__

#include "ofxMSAInteractiveObject.h"
#include "IAVertex.h"
#include "ofMain.h"


class IAPolygon : public ofxMSAInteractiveObject {
public:
    
    ofPolyline *polygon;
    list<IAVertex*> iaverts;
    
    float mouse_anchorX;
    float mouse_anchorY;
    
    bool drag;
    bool active;
    bool isConvex;
    
    IAPolygon();
    ~IAPolygon();
    
    void addVertex(float x, float y);
    bool hitTest(int tx, int ty) const;
    void translate(float d, float dy);
    virtual void constraints();
    IAVertex* getIAVertex(int i);
    void setup();
    void update();
    void draw();
    void drawIAVerts();
    void updateIAVerts();
    virtual bool checkConvex();
    virtual void onDragOver(int x, int y, int button);
    virtual void onPress(int x, int y, int button);
    virtual void onPressOutside(int x, int y, int button);
    virtual void onRelease(int x, int y, int button);
    
};





#endif /* defined(__MeshMapper__IAPolygon__) */
