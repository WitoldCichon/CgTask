#ifndef SHADER_H
#define SHADER_H

#include "cg_gl_error_checker.h"

#include <string>

struct ShaderAttrib {
  std::string shaderFileName;
  std::string shaderEntryFunctionName;
  CGGLenum shaderType;

  ShaderAttrib(ShaderAttrib &&) = default;
  ShaderAttrib(const ShaderAttrib &) = delete;
};

class Shader {
 public:
  Shader(const CGcontext &context, ShaderAttrib t_attributes);
  ~Shader() = default;

  void bind();
  void unbind();

  CGprogram& getProgram();

private:
  ShaderAttrib attributes;
  CGprofile profile;
  CGprogram program;
};

#endif
