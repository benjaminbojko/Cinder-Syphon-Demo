#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinderSyphon.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SyphonDemoApp : public App {
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    syphonServer   mServer;
};

void SyphonDemoApp::setup()
{
    mServer.setName("Cinder Syphon Demo");
}

void SyphonDemoApp::update()
{
}

void SyphonDemoApp::draw()
{
    gl::clear(Color(sinf(getElapsedSeconds() * 1.0f) * 0.25f + 0.5f,
                    sinf(getElapsedSeconds() * 0.6f) * 0.25f + 0.5f,
                    sinf(getElapsedSeconds() * 0.3f) * 0.25f + 0.5f));
    
    gl::enableAlphaBlending();
    gl::drawStringCentered("Hello from Cinder!", getWindowCenter() - vec2(0, 32), Color::white(), Font("Arial", 64));
    gl::disableAlphaBlending();
    
    mServer.publishScreen();
}

CINDER_APP( SyphonDemoApp, RendererGl(RendererGl::Options().msaa(8)) )
