#pragma once

#include "taglib/audioproperties.h"
#include <napi.h>

class Properties: public Napi::ObjectWrap<Properties> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::Object New(std::initializer_list<napi_value> args);
  Properties(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  
  Napi::Value GetLength(const Napi::CallbackInfo &info);
  Napi::Value GetBitrate(const Napi::CallbackInfo &info);
  Napi::Value GetSampleRate(const Napi::CallbackInfo &info);
  Napi::Value GetChannels(const Napi::CallbackInfo &info);

  int length;
  int bitrate;
  int sampleRate;
  int channels;
};
