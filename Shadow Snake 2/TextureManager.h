//
//  TextureManager.h
//  Shadow Snake
//
//  Created by Sinclair Target on 1/11/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake__TextureManager__
#define __Shadow_Snake__TextureManager__

#include <string>
#include <map>
#include <SDL2/SDL.h>

class TextureManager
{
public:
    // singleton implementation
    static TextureManager* instance()
    {
        if (s_instance == nullptr)
            s_instance = new TextureManager();
        return s_instance;
    }
    
    bool load(std::string filename, std::string id);
    void drawFrame(std::string id, int x, int y, int width, int height,
              int currentFrame);
    void drawFrameScaled(std::string id, int x, int y, int width, int height,
                         int scale);
    void drawSquare(int x, int y, int size, int type);
    void drawSquareBloated(int x, int y, int size, int type);
    void drawText(SDL_Surface* text, int x, int y, int width, int height);
    
    void setRenderer(SDL_Renderer* renderer)
    {
        m_renderer = renderer;
    }
    
    void clearFromTextureMap(std::string id);
    
private:
    TextureManager() { }
    static TextureManager* s_instance;
    
    SDL_Renderer* m_renderer;
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* defined(__Shadow_Snake__TextureManager__) */
