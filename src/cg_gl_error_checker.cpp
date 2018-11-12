#include "cg_gl_error_checker.h"

#include <iostream>

void cgErrorLog(const char* fileName, unsigned int lineNumber) {
  CGerror error;
  const char *errorMessage = cgGetLastErrorString(&error);

  if (error != CG_NO_ERROR) {
      std::cerr << fileName << " line "
                << lineNumber << ", "
                << errorMessage << " error code "
                << error << std::endl;
      exit(1);
  }
}
