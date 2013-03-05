/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// This header is configured by Zorba's build process -- DO NOT EDIT!

#ifndef ZORBA_CONFIG_H
#define ZORBA_CONFIG_H

////////// Platform & Compiler ////////////////////////////////////////////////

// Platform
/* #undef APPLE */
/* #undef LINUX */
/* #undef MINGW */
/* #undef UNIX */
#ifndef WIN32
#define WIN32
#endif
/* #undef CYGWIN */
#ifdef CYGWIN
# undef WIN32
#endif /* CYGWIN */

#ifdef WIN32
# pragma warning( disable: 4251 )
#endif /* WIN32 */

// Platform headers
/* #undef ZORBA_HAVE_COLL_H */
/* #undef ZORBA_HAVE_EXECINFO_H */
/* #undef ZORBA_HAVE_FLEXLEXER_H */
/* #undef ZORBA_HAVE_ICONV_H */
/* #undef ZORBA_HAVE_INTTYPES_H */
#define ZORBA_HAVE_LIMITS_H
/* #undef ZORBA_HAVE_PTHREAD_H */
#define ZORBA_HAVE_STDINT_H
#define ZORBA_HAVE_STDLIB_H
/* #undef ZORBA_HAVE_SYS_MOUNT_H */
#define ZORBA_HAVE_SYS_TYPES_H
/* #undef ZORBA_HAVE_TZFILE_H */
/* #undef ZORBA_HAVE_USTRING_H */
/* #undef ZORBA_HAVE_UTYPES_H */
/* #undef ZORBA_HAVE_UUID_H */

// Platform functions
/* #undef ZORBA_HAVE_CLOCKGETTIME_FUNCTION */
/* #undef ZORBA_HAVE_RUSAGE_FUNCTION */
#define ZORBA_HAVE_STRCAT_S_FUNCTION
#define ZORBA_HAVE_STRCPY_S_FUNCTION
#define ZORBA_HAVE_STRICMP_FUNCTION
/* #undef ZORBA_HAVE_STRTOF_FUNCTION */
/* #undef ZORBA_HAVE_STRTOLL_FUNCTION */

// Platform types
#define ZORBA_HAVE_INT32_T
#define ZORBA_HAVE_INT64_T
#define ZORBA_HAVE_MS_INT32
#define ZORBA_HAVE_MS_UINT32
#define ZORBA_HAVE_UINT32_T
/* #undef ZORBA_HAVE_STRUCT_TM_TM_GMTOFF */
/* #undef ZORBA_HAVE_STRUCT_TM___TM_GMTOFF */

// Platform type sizes
#define ZORBA_SIZEOF_DOUBLE        8
#define ZORBA_SIZEOF_FLOAT         4
#define ZORBA_SIZEOF_INT           4
#define ZORBA_SIZEOF_LONG          4
#define ZORBA_SIZEOF_LONG_LONG     8
#define ZORBA_SIZEOF_POINTER       4
#define ZORBA_SIZEOF_SHORT         2
#define ZORBA_SIZEOF_SIZE_T        4
#define ZORBA_SIZEOF_WCHAR_T       2

// Platform libraries
#define ZORBA_HAVE_CURL

#ifdef ZORBA_HAVE_STDINT_H
# include <stdint.h>
#endif

#ifdef ZORBA_HAVE_INTTYPES_H
# include <inttypes.h>
#endif

#ifndef ZORBA_HAVE_INT32_T
# ifdef ZORBA_HAVE_MS_INT32
    typedef __int32 int32_t;
# endif
#endif

#ifndef ZORBA_HAVE_UINT32_T
# ifdef ZORBA_HAVE_MS_UINT32
    typedef unsigned __int32 uint32_t;
# endif
#endif /* ZORBA_HAVE_UINT32_T */

#ifndef ZORBA_HAVE_INT64_T
typedef __int64 int64_t;
#endif /* ZORBA_HAVE_INT64_T */

// Compiler
/* #undef CLANG */
#define MSVC
/* #undef MSVC60 */
/* #undef MSVC70 */
/* #undef MSVC71 */
/* #undef MSVC80 */

// C++11 language features
#define ZORBA_CXX_NULLPTR
#define ZORBA_CXX_STATIC_ASSERT

// C++11 types
#define ZORBA_HAVE_ENABLE_IF
#define ZORBA_HAVE_UNORDERED_MAP
#define ZORBA_HAVE_UNORDERED_SET
#define ZORBA_HAVE_UNIQUE_PTR

////////// C++ tr1 include directory & namespace //////////////////////////////

#if defined( __GNUC__ ) && (__GNUC__ * 100 + __GNUC_MINOR__ < 430)
# define ZORBA_GCC_OLDER_THAN_430 1
#endif

#if defined( _MSC_VER ) && (_MSC_VER < 1600 /* 2010 */)
# define ZORBA_MSC_OLDER_THAN_2010 1
#endif

#if defined( ZORBA_GCC_OLDER_THAN_430 )
# define ZORBA_TR1_IN_TR1_SUBDIRECTORY 1
#endif

#if defined( ZORBA_GCC_OLDER_THAN_430 ) || defined( ZORBA_MSC_OLDER_THAN_2010 )
# define ZORBA_TR1_NS_IS_STD_TR1 1
#endif

#ifdef ZORBA_TR1_NS_IS_STD_TR1
# define ZORBA_TR1_NS std::tr1
#else
# define ZORBA_TR1_NS std
#endif

////////// GCC diagnostics ////////////////////////////////////////////////////

#if defined( __GNUC__ ) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 460)
# define GCC_GREATER_EQUAL_460 1
#endif

#if defined( GCC_GREATER_EQUAL_460 ) || defined( __llvm__ )
# define GCC_PRAGMA_DIAGNOSTIC_PUSH 1
#endif

////////// Zorba //////////////////////////////////////////////////////////////

#define ZORBA_STORE_NAME "zorba_simplestore"

// Version
#define ZORBA_VERSION "2.8.0"
#define ZORBA_MAJOR_NUMBER 2
#define ZORBA_MINOR_NUMBER 8
#define ZORBA_PATCH_NUMBER 0
#define ZORBA_CORE_URI_DIR "share/zorba/uris/core/2.8.0"
#define ZORBA_CORE_LIB_DIR "lib/zorba/core/2.8.0"
#define ZORBA_NONCORE_URI_DIR "share/zorba/uris"
#define ZORBA_NONCORE_LIB_DIR "lib/zorba"

// Zorba features
/* #undef ZORBA_NO_FULL_TEXT */
/* #undef ZORBA_NO_ICU */
/* #undef ZORBA_NO_XMLSCHEMA */
/* #undef ZORBA_NUMERIC_OPTIMIZATION */
/* #undef ZORBA_VERIFY_PEER_SSL_CERTIFICATE */
/* #undef ZORBA_WITH_BIG_INTEGER */
#define ZORBA_WITH_DEBUGGER
#define ZORBA_WITH_FILE_ACCESS
#define ZORBA_WITH_JSON
#define ZORBA_WITH_LIBXML2_SAX

// Zorba parser configuration
/* #undef ZORBA_DEBUG_PARSER */
/* #undef ZORBA_DEBUG_STRING */

// Zorba runtime configuration parameters
#define ZORBA_BATCHING_TYPE         0
#define ZORBA_BATCHING_BATCHSIZE    
#define ZORBA_FLOAT_POINT_PRECISION 18

// Zorba threading mechanism
/* #undef ZORBA_FOR_ONE_THREAD_ONLY */
/* #undef ZORBA_HAVE_PTHREAD_SPINLOCK */
/* #undef ZORBA_HAVE_PTHREAD_MUTEX */

// XQueryX
#define ZORBA_XQUERYX

////////// Building Zorba /////////////////////////////////////////////////////

#ifndef BUILDING_ZORBA_STATIC
# if defined WIN32 || defined CYGWIN
#   ifdef zorba_EXPORTS
#     ifdef __GNUC__
#       define ZORBA_DLL_PUBLIC __attribute__((dllexport))
#     else
#       define ZORBA_DLL_PUBLIC __declspec(dllexport)
#     endif /* __GNUC__ */
#   else /* zorba_EXPORTS */
#     ifdef __GNUC__
#       define ZORBA_DLL_PUBLIC __attribute__((dllimport))
#     else
#       define ZORBA_DLL_PUBLIC __declspec(dllimport)
#     endif /* __GNUC__ */
#   endif /* zorba_EXPORTS */
#   define ZORBA_DLL_LOCAL
# else
#   if __GNUC__ >= 4
#     define ZORBA_DLL_PUBLIC __attribute__ ((visibility("default")))
#     define ZORBA_DLL_LOCAL  __attribute__ ((visibility("hidden")))
#   else
#     define ZORBA_DLL_PUBLIC
#     define ZORBA_DLL_LOCAL
#   endif
# endif
#else /* BUILDING_ZORBA_STATIC */
# define ZORBA_DLL_PUBLIC
# define ZORBA_DLL_LOCAL
#endif /* BUILDING_ZORBA_STATIC */

#endif /* ZORBA_CONFIG_H */
