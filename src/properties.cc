#include "properties.h"

using namespace Napi;

FunctionReference Properties::constructor;

Object Properties::Init(Napi::Env env, Object exports) {
  auto func = DefineClass(env, "Properties", {
    InstanceAccessor("length", &Properties::GetLength, nullptr),
    InstanceAccessor("bitrate", &Properties::GetBitrate, nullptr),
    InstanceAccessor("sampleRate", &Properties::GetSampleRate, nullptr),
    InstanceAccessor("channels", &Properties::GetChannels, nullptr)
  });

  constructor = Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Properties", func);
  return exports;
}

Object Properties::New(std::initializer_list<napi_value> args) {
  return constructor.New(args);
}

Properties::Properties(const CallbackInfo &info) : ObjectWrap(info) {
  auto env = info.Env();

  if (info.Length() < 1) {
    TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsExternal()) {
    TypeError::New(env, "Argument 1 should be a native AudioProperties object. Calling this constructor on JS is not recommended.").ThrowAsJavaScriptException();
    return;
  }

  auto props = info[0].As<External<TagLib::AudioProperties>>().Data();
  length = props->length();
  bitrate = props->bitrate();
  sampleRate = props->sampleRate();
  channels = props->channels();
}

Value Properties::GetLength(const CallbackInfo &info) {
  return Number::New(info.Env(), length);
}

Value Properties::GetBitrate(const CallbackInfo &info) {
  return Number::New(info.Env(), bitrate);
}

Value Properties::GetSampleRate(const CallbackInfo &info) {
  return Number::New(info.Env(), sampleRate);
}

Value Properties::GetChannels(const CallbackInfo &info) {
  return Number::New(info.Env(), channels);
}