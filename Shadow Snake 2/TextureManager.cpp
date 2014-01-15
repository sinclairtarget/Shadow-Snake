//
//  TextureManager.cpp
//  Shadow Snake
//
//  Created by Sinclair Target on 1/11/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "TextureManager.h"
#include <SDL2_image/SDL_image.h>
#include <iostream>

TextureManager* TextureManager::s_instance = nullptr;

bool TextureManager::load(std::string filename, std::string id)
{
    std::cout << "Loading texture.\n";
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    
    if (tempSurface == nullptr)
    {
        std::cout << "Load failed. " << IMG_GetError() << std::endl;
        return false;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,
                                                        tempSurface);
    
    SDL_FreeSurface(tempSurface);
    
    if (texture == nullptr)
    {
        std::cout << "Texture creation failed. " << IMG_GetError();
        return false;
    }
    
    m_textureMap[id] = texture;
    return true;
}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
                               int height, int currentFrame)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = width * currentFrame;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopy(m_renderer, m_textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawSquare(int x, int y, int size, int type)
{    
    // HEAD_BIT(0) and SNAKE_BIT(1) are the same color
    type--;
    if (type < 0)
        type = 0;
    
    drawFrame("squares", x, y, size, size, type);
}

void TextureManager::drawSquareBloated(int x, int y, int size, int type)
{
    // HEAD_BIT(0) and SNAKE_BIT(1) are the same color
    type--;
    if (type < 0)
        type = 0;
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = size * type;
    srcRect.y = 0;
    srcRect.w = destRect.w = size;
    srcRect.h = destRect.h = size;
    destRect.x = x - 2;
    destRect.y = y - 2;
    destRect.w = size + 4;
    destRect.h = size + 4;
    
    SDL_RenderCopy(m_renderer, m_textureMap["squares"], &srcRect, &destRect);
}

void TextureManager::drawText(SDL_Surface* text, int x, int y, int width,
                              int height)
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, text);
    
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;
    
    SDL_RenderCopy(m_renderer, texture, NULL, &destRect);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    m_textureMap.erase(id);
}
