#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    
private:
    SDL_Window *m_window ;
    SDL_Renderer *m_renderer ;
    SDL_Texture *m_texture ;
    Uint32 *m_pixelsBuffer ;
    Uint32 *m_pixelsBufferBlured;
    SDL_Event m_event;

public:
    Screen():m_window(NULL), m_renderer(NULL), m_texture(NULL), m_pixelsBuffer(NULL), m_pixelsBufferBlured(NULL){}
    bool init();
    bool processEvents();
    void close();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

    void boxBlur();
    //void clear();



};



#endif