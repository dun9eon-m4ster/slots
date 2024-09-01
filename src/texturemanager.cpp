#include "texturemanager.h"
#include "texture.h"
#include "iostream"
#include "SDL_render.h"

TextureManager::TextureManager()
{
	load("picture.bmp");
	load("1.bmp");
	load("2.bmp");
	load("3.bmp");
	load("4.bmp");
	load("5.bmp");
	load("6.bmp");
	load("7.bmp");
	load("8.bmp");
	load("9.bmp");
	load("0.bmp");
}

bool TextureManager::load(const std::string& file_name)
{
	auto image = SDL_LoadBMP(file_name.c_str());
	if (!image)
	{
		std::cout	<< "TextureManager::load() - failed to load texture" 
					<< SDL_GetError() << "   "
					<< file_name << "   "
					<< std::endl;
		return false;
	}

	texture_array[file_name] = std::shared_ptr<Texture>(new Texture(image));

	return true;
}




TextureManager* TextureManager::instance()
{
	static TextureManager manager;
	return &manager;
}

std::shared_ptr<Texture> TextureManager::texture(const std::string& texture_name)
{
	auto iterator = texture_array.find(texture_name);
	if(iterator == texture_array.end())
		return nullptr;

	return iterator->second;
}
