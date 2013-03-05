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


#include <node.h>
#include <v8.h>
#include <zorba/zorba.h>
#include "helpers.h"

using namespace v8;


void init(Handle<Object> target) {
  target->Set(String::NewSymbol("execute"),
      FunctionTemplate::New(Execute)->GetFunction());
}
NODE_MODULE(zorba, init)
