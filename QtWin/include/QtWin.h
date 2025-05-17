
#ifndef QTWIN_API_H
#define QTWIN_API_H

#ifdef QTWIN_STATIC_DEFINE
#  define QTWIN_API
#  define QTWIN_NO_EXPORT
#else
#  ifndef QTWIN_API
#    ifdef QtWin_EXPORTS
        /* We are building this library */
#      define QTWIN_API __declspec(dllexport)
#    else
        /* We are using this library */
#      define QTWIN_API __declspec(dllimport)
#    endif
#  endif

#  ifndef QTWIN_NO_EXPORT
#    define QTWIN_NO_EXPORT 
#  endif
#endif

#ifndef QTWIN_DEPRECATED
#  define QTWIN_DEPRECATED __declspec(deprecated)
#endif

#ifndef QTWIN_DEPRECATED_EXPORT
#  define QTWIN_DEPRECATED_EXPORT QTWIN_API QTWIN_DEPRECATED
#endif

#ifndef QTWIN_DEPRECATED_NO_EXPORT
#  define QTWIN_DEPRECATED_NO_EXPORT QTWIN_NO_EXPORT QTWIN_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef QTWIN_NO_DEPRECATED
#    define QTWIN_NO_DEPRECATED
#  endif
#endif

#endif /* QTWIN_API_H */
