/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include "helpers.h"
#include "NodeDiagnosticHandler.h"

using namespace v8;

Handle<Value> Execute(const Arguments& args) {

  HandleScope scope;

  if ((args.Length() < 1) || (args.Length() > 3) || (args.Length() == 2)) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }
  if (!args[0]->IsString()) {
    ThrowException(Exception::TypeError(String::New("Wrong argument, first argument should be a valid string query")));
    return scope.Close(Undefined());
  }
  if (args.Length() > 1) {
    if (!args[1]->IsFunction()) {
      ThrowException(Exception::TypeError(String::New("Wrong argument, second argument should be a valid function")));
      return scope.Close(Undefined());
    }
    if (args.Length() > 2) {
      if (!args[2]->IsFunction()) {
        ThrowException(Exception::TypeError(String::New("Wrong argument, third argument should be a valid function")));
        return scope.Close(Undefined());
      }
    }
  }

  v8::String::Utf8Value param1(args[0]->ToString());
  std::string sQuery(*param1);
  std::ostringstream lOutputStream;
  Zorba_CompilerHints_t hints;
  zorba::XQuery_t query = getZorbaInstance()->createQuery();
  
  switch (args.Length()) {
  case 1:
    {
      try {
        query->compile(sQuery, hints);
        query->execute(lOutputStream);
      } catch (zorba::ZorbaException e) {
        ThrowException(Exception::Error(String::New(e.what())));
      }
    return scope.Close(String::New(lOutputStream.str().c_str()));
    }
    break;
  case 3:
    {
      Local<Function> function(Local<Function>::Cast(args[2]));
      NodeDiagnosticHandler diagnosticHandler(function);
      query->registerDiagnosticHandler(&diagnosticHandler);

      query->compile(sQuery, hints);
      query->execute(lOutputStream);
      const unsigned argc = 1;
      Local<Value> argv[argc] = { Local<Value>::New(String::New(lOutputStream.str().c_str())) };
      Local<Function>::Cast(args[1])->Call(Context::GetCurrent()->Global(), argc, argv);
      return scope.Close(Undefined());
    }
    break;
  }
  return scope.Close(String::New("Exit from a wrong path"));
}
