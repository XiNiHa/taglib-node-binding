#pragma once

#include "taglib/tag.h"
#include <napi.h>

class Tag: public Napi::ObjectWrap<Tag> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::Object New(std::initializer_list<napi_value> args);
  static std::string FetchTagType(TagLib::Tag* tagPtr);
  Tag(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  TagLib::Tag* tagPtr;
  std::string tagType;

  Napi::Value GetTitle(const Napi::CallbackInfo &info);
  Napi::Value GetArtist(const Napi::CallbackInfo &info);
  Napi::Value GetAlbum(const Napi::CallbackInfo &info);
  Napi::Value GetComment(const Napi::CallbackInfo &info);
  Napi::Value GetGenre(const Napi::CallbackInfo &info);
  Napi::Value GetYear(const Napi::CallbackInfo &info);
  Napi::Value GetTrack(const Napi::CallbackInfo &info);

  void SetTitle(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetArtist(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetAlbum(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetComment(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetGenre(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetYear(const Napi::CallbackInfo &info, const Napi::Value &value);
  void SetTrack(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value GetType(const Napi::CallbackInfo &info);
};
