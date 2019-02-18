//
// Created by Vadym KOZLOV on 7/7/18.
//

#ifndef ResourceManager_HPP
# define ResourceManager_HPP

#include <map>
#include <string>
#include <memory>
#include "GL/glew.h"
#include "ResourceManagement/Texture.hpp"
#include "ResourceManagement/Shader.hpp"

#define RESOURCES ResourceManager::getInstance()

class ResourceManager
{
public:
	static ResourceManager   &getInstance();
	void setBinFolder(std::string const& aPath);
	std::shared_ptr<Shader>		loadShader(const GLchar *, const GLchar *, std::string const &);
	std::shared_ptr<Shader>		getShader(std::string const &);
	std::shared_ptr<Texture>	loadTexture(const GLchar *, std::string const &, bool);
	std::shared_ptr<Texture>	getTexture(std::string const &name);
	void						clear();
	ResourceManager(ResourceManager const &) = delete;
	ResourceManager &operator=(ResourceManager const &) = delete;
private:
	ResourceManager();
	~ResourceManager();
	std::shared_ptr<Shader>		loadShaderFromFile(const GLchar *, const GLchar *);
	std::shared_ptr<Texture>	loadTextureFromFile(const GLchar*, bool);
private:
	std::map<std::string, std::shared_ptr<Shader>>			mShaders;
	std::map<std::string, std::shared_ptr<Texture>>		mTextures;
	std::string mBinFolder;
};


#endif