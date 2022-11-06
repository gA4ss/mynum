#ifndef MYNUM_DEBUG_H_
#define MYNUM_DEBUG_H_

#include <my/my_debug.h>

namespace mynum
{

#ifdef DEBUG
#define mynum_dbgprint(s) my::dbgprint(__FILE__, __LINE__, __FUNCTION__, "%s", (s))
#define mynum_dbgprint_fmt(format, ...) my::dbgprint(__FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__)
#else
#define mynum_dbgprint(s)
#define mynum_dbgprint_fmt(format, ...)
#endif

} // namespace mynum

#endif // MYNUM_DEBUG_H_