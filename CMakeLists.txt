# Copyright 2006-2013 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
FIND_PACKAGE(NodeJS)

IF(NODEJS_FOUND)
  MESSAGE(STATUS "Generating NodeJS API")

  SET(SRCS
    src/helpers.cpp
    src/main.cpp
    src/NodeDiagnosticHandler.cpp
    src/Execute.cpp
  )

  ADD_LIBRARY(nodejs_api SHARED ${SRCS})
  
  FIND_PATH(NODEJS_INCLUDE node.h
    PATHS
      ${NODEJS_PATH}/src
      /usr/include/nodejs
  )

  INCLUDE_DIRECTORIES(
    ${NODEJS_INCLUDE}
    ${NODEJS_PATH}/deps/v8/include 
    ${NODEJS_PATH}/deps/uv/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

  SET_TARGET_PROPERTIES(nodejs_api PROPERTIES SUFFIX ".node" OUTPUT_NAME "zorba" PROJECT_LABEL "NodeJS" FOLDER "APIs")
  TARGET_LINK_LIBRARIES(nodejs_api ${NODEJS_LIBRARY})
  TARGET_LINK_LIBRARIES(nodejs_api zorba_simplestore)
  
  
  
ELSE(NODEJS_FOUND)
  MESSAGE(STATUS "Can't find NodeJS, this API won't be included.")
ENDIF(NODEJS_FOUND)
