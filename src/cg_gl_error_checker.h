#ifndef CG_GL_ERROR_CHECKER_H
#define CG_GL_ERROR_CHECKER_H

#include <Cg/cg.h>
#include <Cg/cgGL.h>

#define CG_DEBUG(x) \
  x;\
  cgErrorLog(__FILE__, __LINE__);

void cgErrorLog(const char* fileName, unsigned int lineNumber);

#endif
