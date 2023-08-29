#include "texture.hpp"

Texture::Texture() {
    // Initialize
    texture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    // Deallocate
    free();
}

int Texture::loadFromFile(SDL_Renderer* renderer, std::string path) {
    // Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return -1;
    } 

    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return -2;
    } 

    //Get image dimensions
    width = loadedSurface->w;
    height = loadedSurface->h;

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    texture = newTexture;
    return 0;
}

void Texture::free() {
    // Free texture if it exists
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void Texture::render(SDL_Renderer* renderer, int x, int y) {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}