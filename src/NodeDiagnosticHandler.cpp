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

#include "NodeDiagnosticHandler.h"

void NodeDiagnosticHandler::error( zorba::ZorbaException const &exception ) {
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Local<Value>::New(String::New( exception.diagnostic().message() )) };
  callback->Call(Context::GetCurrent()->Global(), argc, argv);
}

void NodeDiagnosticHandler::warning( zorba::XQueryWarning const &warning ) {
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Local<Value>::New(String::New( warning.diagnostic().message() )) };
  callback->Call(Context::GetCurrent()->Global(), argc, argv);
}

