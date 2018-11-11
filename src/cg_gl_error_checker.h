#ifndef CG_GL_ERROR_CHECKER_H
#define CG_GL_ERROR_CHECKER_H

#include <Cg/cg.h>
#include <Cg/cgGL.h>

#define CG_DEBUG(x, cgContext) \
	x;\
	cgErrorLog(__FILE__, #x, __LINE__, cgContext);

void cgErrorLog(const char* fileName, const char* functionName,
	unsigned int lineNumber, const CGcontext &currentCgContext);

#endif
