#include <napi.h>
#include <iostream>

#include "fileref.h"
#include "tag.h"
#include "properties.h"

using namespace Napi;

Object Init(Env env, Object exports) {
  FileRef::Init(env, exports);
  Tag::Init(env, exports);
  Properties::Init(env, exports);

  return exports;
}

NODE_API_MODULE(addon, Init)
