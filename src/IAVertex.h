//
//  IAVertex.h
//  MeshMapper
//
//  Created by plutots on 17/06/15.
//
//

#ifndef __MeshMapper__IAVertex__
#define __MeshMapper__IAVertex__

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"


class IAVertex : public ofxMSAInteractiveObject {
    
    public:
    
        static IAVertex* activeIAVertex;
    
        IAVertex();
        ~IAVertex();
    
        float size;
        float mouse_anchorX;
        float mouse_anchorY;
        bool drag;
        bool active;
        void set(float ix, float iy);
        bool hitTest(int tx, int ty) const;
        void setup();
        void update();
        void draw();
        void onRollOver(int x, int y);
        void onRollOut();
        void onMouseMove(int x, int y);
        virtual void onDragOver(int x, int y, int button);
        virtual void onDragOutside(int x, int y, int button);
        virtual void onPress(int x, int y, int button);
        virtual void onPressOutside(int x, int y, int button);
        virtual void onRelease(int x, int y, int button);
        virtual void keyPressed(int key);
};


#endif /* defined(__MeshMapper__IAVertex__) */
