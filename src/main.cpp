#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;

    settings.setSize(600, 600);
    settings.setPosition(glm::vec2(300,300));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

    settings.setSize(600, 300);
    settings.setPosition(glm::vec2(0,0));
    settings.resizable = false;

    settings.shareContextWith = mainWindow; // share openGL resources
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    guiWindow->setVerticalSync(false);

    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupComposite();
    ofAddListener(guiWindow->events().draw,
                  mainApp.get(),
                  &ofApp::drawComposite);

    ofRunApp(mainWindow, mainApp);

    ofRunMainLoop();
}
