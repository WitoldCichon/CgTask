#include "cg_gl_error_checker.h"

#include <iostream>

void cgErrorLog(const char* fileName, const char* functionName,
                unsigned int lineNumber, const CGcontext& currentCgContext) {
  CGerror error;
  const char *errorMessage = cgGetLastErrorString(&error);

  if (error != CG_NO_ERROR) {
      std::cerr << fileName << " line "
                << lineNumber << ", "
                << functionName << ", "
                << errorMessage << " error code "
                << error << std::endl;
      if (error == CG_COMPILER_ERROR) {
        std::cerr << "Cg compiler error: " << cgGetLastListing(currentCgContext)
                  << std::endl;
      }
      exit(1);
  }
}
