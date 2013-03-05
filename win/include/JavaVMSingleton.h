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

#ifndef JAVA_VM_SINGLETON
#define JAVA_VM_SINGLETON

#include <jni.h>
#include <zorba/static_context.h>

# if defined WIN32 || defined CYGWIN
#   ifdef util_jvm_EXPORTS
#     ifdef __GNUC__
#       define UTIL_JVM_DLL_PUBLIC __attribute__((dllexport))
#     else
#       define UTIL_JVM_DLL_PUBLIC __declspec(dllexport)
#     endif /* __GNUC__ */
#   else /* util_jvm_EXPORTS */
#     ifdef __GNUC__
#       define UTIL_JVM_DLL_PUBLIC __attribute__((dllimport))
#     else
#       define UTIL_JVM_DLL_PUBLIC __declspec(dllimport)
#     endif /* __GNUC__ */
#   endif /* util_jvm_EXPORTS */
# else
#   if __GNUC__ >= 4
#     define UTIL_JVM_DLL_PUBLIC __attribute__ ((visibility("default")))
#   else
#     define UTIL_JVM_DLL_PUBLIC
#   endif
# endif

namespace zorba { namespace jvm {

#define NO_OF_JVM_OPTIONS 3


class VMOpenException {};

class UTIL_JVM_DLL_PUBLIC JavaVMSingleton
{
public:
  //static JavaVMSingleton* getInstance(const char* classPath);
  static JavaVMSingleton* getInstance(const char* classPath, const char* javaLibPath);
  static JavaVMSingleton* getInstance(const zorba::StaticContext* aStaticContext);

  virtual ~JavaVMSingleton();
  JavaVM* getVM();
  JNIEnv* getEnv();

protected:
  JavaVMSingleton(const char* classPath, const char* javaLibPath);
  JavaVMSingleton(JavaVM *jvm, JNIEnv *env) : m_vm(jvm), m_env(env) {}
  static String computeClassPath(const zorba::StaticContext* aStaticContext);
  static String computeLibPath(const zorba::StaticContext* aStaticContext);

  static JavaVMSingleton* instance;
  JavaVM* m_vm;
  JNIEnv* m_env;
  JavaVMInitArgs args;
  JavaVMOption options[NO_OF_JVM_OPTIONS];

  char* classPathOption;
  char* awtOption;
  char* jlpOption;
};


}} //namespace zorba, jvm

#endif // JAVA_VM_SINGLETON




