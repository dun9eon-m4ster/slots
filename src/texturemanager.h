#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "map"
#include "memory"
#include "string"

class Texture;

class TextureManager
{
public:
	static TextureManager* instance();
	std::shared_ptr<Texture> texture(const std::string &texture_name);

private:
	TextureManager();
	TextureManager(const TextureManager &other) = delete;
	TextureManager& operator=(const TextureManager& other) = delete;
	bool load(const std::string& file_name);
	std::map<std::string, std::shared_ptr<Texture>> texture_array;
};

#endif // TEXTUREMANAGER_H
