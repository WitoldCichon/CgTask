#include "texture.h"
#include "cg_gl_error_checker.h"
#include "stb_image.h"

#include <GL/glu.h>

#include <iostream>

Texture::Texture(const std::string textureFileName, unsigned int t_name)
    : name(t_name)
{
  stbi_set_flip_vertically_on_load(1);
  // load an image from the file
  data = stbi_load(textureFileName.c_str(), &width, &height, &bytesPerPixel, 4);
  if (!data) {
    std::cerr << "Fail. Cannot load a texture from the file" << std::endl;
    exit(1);
  }

  // Create a GL texture
  CG_DEBUG(glBindTexture(GL_TEXTURE_2D, name));
  CG_DEBUG(gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA,
                             GL_UNSIGNED_BYTE, data));
  CG_DEBUG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                           GL_LINEAR_MIPMAP_LINEAR));
}

Texture::~Texture() { stbi_image_free(data); }
