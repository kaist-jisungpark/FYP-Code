/*
    This file has been generated by bvtidl.pl. DO NOT MODIFY!
*/
#ifndef __BVTLOGGER_H__
#define __BVTLOGGER_H__

#include <bvt_c/bvt_retval.h>

#ifndef DOXY_IGNORE
#ifdef _WIN32
#	ifdef BUILDING_BVTSDK
#		define BVTSDK_EXPORT __declspec(dllexport)
#	else
#		define BVTSDK_EXPORT __declspec(dllimport)
#	endif
#else
#	define BVTSDK_EXPORT
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \file
 * \defgroup BVTLogger BVTLogger Object
 * The SDK is capable of producing a significant amount of debugging 
 * output.  The Logger object exists to allow the user to control 
 * (or disable) the output.  Users can also use Logger to add their
 * own custom log messages.
 * @{
*/

/** Don't log anything. 
 */
#define BVTLOGGER_NONE	(int)(-1)

/** Log critical events. 
 */
#define BVTLOGGER_CRITICAL	(int)(0)

#define BVTLOGGER_WARNING	(int)(1)

#define BVTLOGGER_STATUS	(int)(2)

/** Set the log threshold level.  Events above level
 * will be logged to the target.
 * \param level Log level 
 */
BVTSDK_EXPORT void BVTLogger_SetLevel(int level);

/** The log target can be a filename, "stdout", "stderr", or "null".
 * If null is specified, log output is disabled.
 * \param target File/device to log output to 
 */
BVTSDK_EXPORT RetVal BVTLogger_SetTarget(const char* target);

/** @}*/

#ifdef __cplusplus
}
#endif

#endif