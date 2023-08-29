#ifndef HEADER_TEXTURE
#define HEADER_TEXTURE

#include <SDL.h>
#include <SDL_image.h>
#include <string>

// Texture wrapper class
class Texture {
public:
    // Initializes variables
    Texture();

    // Deallocates memory
    ~Texture();

    // Loads image at specified path
    int loadFromFile(SDL_Renderer* renderer, std::string path);

    // Deallocates texture
    void free();

    // Renders texture at given point
    void render(SDL_Renderer* renderer, int x, int y);

    // Gets image dimensions
    int getWidth();
    int getHeight();

private:
    // The actual hardware texture
    SDL_Texture* texture;

    // Image dimensions
    int width;
    int height;
};

#endif