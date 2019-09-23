#pragma once

#include "taglib/fileref.h"
#include <napi.h>

class FileRef: public Napi::ObjectWrap<FileRef> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  FileRef(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  TagLib::FileRef f;
  std::string ext;

  Napi::Value Save(const Napi::CallbackInfo &info);

  Napi::Value GetTag(const Napi::CallbackInfo &info);
  Napi::Value GetExtension(const Napi::CallbackInfo &info);
};
