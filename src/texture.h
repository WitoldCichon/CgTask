#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
 public:
  Texture(const std::string textureFileName, unsigned int t_name);
  ~Texture();

 private:
  int width;
  int height;
  int bytesPerPixel;
  unsigned int name;
  void *data;
};

#endif
