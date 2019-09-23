#include "taglib/apetag.h"
#include "taglib/asftag.h"
#include "taglib/id3v1tag.h"
#include "taglib/id3v2tag.h"
#include "taglib/modtag.h"
#include "taglib/mp4tag.h"
#include "taglib/xiphcomment.h"
#include "taglib/infotag.h"
#include "tag.h"

using namespace Napi;

FunctionReference Tag::constructor;

Object Tag::Init(Napi::Env env, Object exports) {
  auto func = DefineClass(env, "Tag", {
    InstanceAccessor("title", &Tag::GetTitle, &Tag::SetTitle),
    InstanceAccessor("artist", &Tag::GetArtist, &Tag::SetArtist),
    InstanceAccessor("album", &Tag::GetAlbum, &Tag::SetAlbum),
    InstanceAccessor("comment", &Tag::GetComment, &Tag::SetComment),
    InstanceAccessor("genre", &Tag::GetGenre, &Tag::SetGenre),
    InstanceAccessor("year", &Tag::GetYear, &Tag::SetYear),
    InstanceAccessor("track", &Tag::GetTrack, &Tag::SetTrack),

    InstanceAccessor("type", &Tag::GetType, nullptr)
  });

  constructor = Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Tag", func);
  return exports;
}

Object Tag::New(std::initializer_list<napi_value> args) {
  return constructor.New(args);
}

Tag::Tag(const CallbackInfo &info) : ObjectWrap(info) {
  auto env = info.Env();

  if (info.Length() < 1) {
    TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsExternal()) {
    TypeError::New(env, "Argument 1 should be a native Tag object. Calling this construconstructor on JS is not recommended.").ThrowAsJavaScriptException();
    return;
  }

  tagPtr = info[0].As<External<TagLib::Tag>>().Data();
  tagType = FetchTagType(tagPtr);
}

Value Tag::GetTitle(const CallbackInfo &info) {
  return String::New(info.Env(), tagPtr->title().to8Bit(true));
}
Value Tag::GetArtist(const CallbackInfo &info) {
  return String::New(info.Env(), tagPtr->artist().to8Bit(true));
}
Value Tag::GetAlbum(const CallbackInfo &info) {
  return String::New(info.Env(), tagPtr->album().to8Bit(true));
}
Value Tag::GetComment(const CallbackInfo &info) {
  return String::New(info.Env(), tagPtr->comment().to8Bit(true));
}
Value Tag::GetGenre(const CallbackInfo &info) {
  return String::New(info.Env(), tagPtr->genre().to8Bit(true));
}
Value Tag::GetYear(const CallbackInfo &info) {
  return Number::New(info.Env(), tagPtr->year());
}
Value Tag::GetTrack(const CallbackInfo &info) {
  return Number::New(info.Env(), tagPtr->track());
}

void Tag::SetTitle(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setTitle(TagLib::String{value.As<String>().Utf8Value(), TagLib::String::Type::UTF8});
}
void Tag::SetArtist(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setArtist(TagLib::String{value.As<String>().Utf8Value(), TagLib::String::Type::UTF8});
}
void Tag::SetAlbum(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setAlbum(TagLib::String{value.As<String>().Utf8Value(), TagLib::String::Type::UTF8});
}
void Tag::SetComment(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setComment(TagLib::String{value.As<String>().Utf8Value(), TagLib::String::Type::UTF8});
}
void Tag::SetGenre(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setGenre(TagLib::String{value.As<String>().Utf8Value(), TagLib::String::Type::UTF8});
}
void Tag::SetYear(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setYear(value.As<Number>().Uint32Value());
}
void Tag::SetTrack(const Napi::CallbackInfo &info, const Napi::Value &value) {
  tagPtr->setTrack(value.As<Number>().Uint32Value());
}

Value Tag::GetType(const CallbackInfo &info) {
  return String::New(info.Env(), tagType);
}

std::string Tag::FetchTagType(TagLib::Tag* tagPtr) {
  if(dynamic_cast<TagLib::APE::Tag*>(tagPtr))
    return "APE";
  if(dynamic_cast<TagLib::ASF::Tag*>(tagPtr))
    return "ASF";
  if(dynamic_cast<TagLib::ID3v1::Tag*>(tagPtr))
    return "ID3v1";
  if(dynamic_cast<TagLib::ID3v2::Tag*>(tagPtr))
    return "ID3v2";
  if(dynamic_cast<TagLib::Mod::Tag*>(tagPtr))
    return "Mod";
  if(dynamic_cast<TagLib::MP4::Tag*>(tagPtr))
    return "MP4";
  if(dynamic_cast<TagLib::Ogg::XiphComment*>(tagPtr))
    return "XiphComment";
  if(dynamic_cast<TagLib::RIFF::Info::Tag*>(tagPtr))
    return "RIFF";
  return "";
}
