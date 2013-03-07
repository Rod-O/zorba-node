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

#include "QueryManager.h"

using namespace v8;

std::queue<std::shared_ptr<NodeQuery>> QueryManager::querysToExecute;
std::mutex QueryManager::mutex;
std::thread QueryManager::thread;

void QueryManager::pushQuery(std::string lQuery, std::shared_ptr<Local<Function>> lResultCallback, std::shared_ptr<Local<Function>> lErrorCallback) {
// TESTING CALLBACK
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Local<Value>::New(String::New("Hellllloooo")) };
    (*lResultCallback)->Call(Context::GetCurrent()->Global(), argc, argv);
  mutex.lock();
  querysToExecute.push(std::make_shared<NodeQuery>(lQuery, lResultCallback, lErrorCallback));
  if (querysToExecute.size()==1) {
    thread = std::thread(&QueryManager::executor);
  }
  mutex.unlock();
  QueryManager::thread.join();  // So far, can't be multithreaded
}

void QueryManager::executor() {
  mutex.lock();
  while (querysToExecute.size()>0) {
    auto lQuery = querysToExecute.front();
    mutex.unlock();

// TESTING CALLBACK  - NOT WORKING :(
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Local<Value>::Cast(String::New("Hellllloooo")) };
    (*lQuery->resultCallback)->Call(Context::GetCurrent()->Global(), argc, argv);

    // ZORBA
    Zorba_CompilerHints_t hints;
    std::ostringstream lOutputStream;
    zorba::Zorba* zorba = getZorbaInstance();
    zorba::XQuery_t query = zorba->createQuery();
    NodeDiagnosticHandler diagnosticHandler(*lQuery->errorCallback);
    query->registerDiagnosticHandler(&diagnosticHandler);
    query->compile(lQuery->query, hints);
    query->execute(lOutputStream);
    //CALLBACK
    v8::String::Utf8Value param1((*lQuery->resultCallback)->ToString());
    //const unsigned argc = 1;
    //Local<Value> argv[argc] = { Local<Value>::New(String::New(lOutputStream.str().c_str())) };
    //lQuery->resultCallback->Call(Context::GetCurrent()->Global(), argc, argv);

    mutex.lock();
    querysToExecute.pop();
  }
  mutex.unlock();
}




