//tester
#include "Screen.h"


bool Screen::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        
        return false;
    }
    m_window = SDL_CreateWindow("Particle Fire Explosion", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_SHOWN );
    
    if(m_window == NULL){
        
        SDL_Quit();
        return false;
    }

    

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    m_texture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if(m_renderer == NULL){
       
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if(m_texture == NULL){
        
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
        SDL_Quit();
        return false;
    }

   m_pixelsBuffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];
    memset(m_pixelsBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
        m_pixelsBuffer[i] = 0 ;
    }
    this->update();

    return true; 
}

void Screen::close(){
    delete [] m_pixelsBuffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Screen::processEvents(){
    while(SDL_PollEvent(&m_event)){
        if(m_event.type == SDL_QUIT){
            return false;
        }
    }
    return true;
}

void Screen::update(){
    if(m_texture != NULL && m_renderer != NULL && m_window != NULL && m_pixelsBuffer != NULL){
        SDL_UpdateTexture(m_texture, NULL, m_pixelsBuffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT){
        return;
    }
    Uint32 color =0;

    color+= red;
    color <<= 8;
    color+= green;
    color <<= 8;
    color+= blue;
    color <<= 8;
    color+= 0xFF;
    
    
    m_pixelsBuffer[(y*SCREEN_WIDTH) + x] = color;
}

void Screen::clear(){
    memset(m_pixelsBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}


