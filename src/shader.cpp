#include "shader.h"

Shader::Shader(const CGcontext &context, ShaderAttrib t_attributes)
    : attributes(std::move(t_attributes)) {
  // Set proper profile based on the type of shader
  CG_DEBUG(profile = cgGLGetLatestProfile(attributes.shaderType));
  CG_DEBUG(cgGLSetOptimalOptions(profile));

  // Create and load a program
  CG_DEBUG(program = cgCreateProgramFromFile(
               context, CG_SOURCE, attributes.shaderFileName.c_str(), profile,
               attributes.shaderEntryFunctionName.c_str(), nullptr));
  CG_DEBUG(cgGLLoadProgram(program));
}

void Shader::bind() {
  CG_DEBUG(cgGLBindProgram(program));
  CG_DEBUG(cgGLEnableProfile(profile));
}

void Shader::unbind() {
  CG_DEBUG(cgGLDisableProfile(profile));
}
