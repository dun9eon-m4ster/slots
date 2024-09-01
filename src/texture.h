#ifndef TEXTURE_H
#define TEXTURE_H

struct SDL_Surface;

class Texture
{
public:
	Texture(SDL_Surface *_new_sdl_surface);
	Texture(const Texture& orher) = delete;
	Texture& operator=(const Texture& other) = delete;
	~Texture();
	SDL_Surface* get();

private:
	SDL_Surface* sdl_surface;
};

#endif // TEXTURE_H
