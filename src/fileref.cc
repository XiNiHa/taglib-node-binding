#include <algorithm>
#include "taglib/mpegfile.h"
#include "taglib/id3v1tag.h"
#include "taglib/id3v2tag.h"
#include "taglib/apetag.h"
#include "taglib/flacfile.h"
#include "taglib/xiphcomment.h"
#include "fileref.h"
#include "tag.h"

using namespace Napi;

FunctionReference FileRef::constructor;

Object FileRef::Init(Napi::Env env, Object exports) {
  auto func = DefineClass(env, "FileRef", {
    InstanceAccessor("tag", &FileRef::GetTag, nullptr),
    InstanceAccessor("extension", &FileRef::GetExtension, nullptr),
    InstanceMethod("save", &FileRef::Save)
  });

  constructor = Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("FileRef", func);
  return exports;
}

FileRef::FileRef(const CallbackInfo &info) : ObjectWrap(info) {
  auto env = info.Env();

  if (info.Length() < 1) {
    TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsString()) {
    TypeError::New(env, "Argument 1 should be the file name in string.").ThrowAsJavaScriptException();
    return;
  }

  auto fileName = info[0].As<String>().Utf8Value();
  f = TagLib::FileRef{fileName.c_str()};

  if (f.isNull()) {
    Error::New(env, "Cannot find the file.").ThrowAsJavaScriptException();
    return;
  }
  
  auto dot = fileName.rfind(".");
  if (dot != std::string::npos) {
    ext = fileName.substr(dot + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), toupper);
  }
}

Value FileRef::Save(const CallbackInfo &info) {
  return Boolean::From(info.Env(), f.save());
}

Value FileRef::GetTag(const CallbackInfo &info) {
  auto env = info.Env();
  auto ptr = f.tag();

  // MP3 needs special logic for getting Tag* as MP3 can have 3 tag types
  if (ext == "MP3") {
    auto mpegFile = dynamic_cast<TagLib::MPEG::File*>(f.file());

    if (mpegFile->hasID3v2Tag()) {
      ptr = dynamic_cast<TagLib::Tag*>(mpegFile->ID3v2Tag());
    }
    else if (mpegFile->hasAPETag()) {
      ptr = dynamic_cast<TagLib::Tag*>(mpegFile->APETag());
    }
    else if (mpegFile->hasID3v1Tag()) {
      ptr = dynamic_cast<TagLib::Tag*>(mpegFile->ID3v1Tag());
    }
  }
  // Same for FLAC, different tag types
  else if (ext == "FLAC") {
    auto flacFile = dynamic_cast<TagLib::FLAC::File*>(f.file());

    if (flacFile->hasXiphComment()) {
      ptr = dynamic_cast<TagLib::Tag*>(flacFile->xiphComment());
    }
    else if (flacFile->hasID3v2Tag()) {
      ptr = dynamic_cast<TagLib::Tag*>(flacFile->ID3v2Tag());
    }
    else if (flacFile->hasID3v1Tag()) {
      ptr = dynamic_cast<TagLib::Tag*>(flacFile->ID3v1Tag());
    }
  }

  return Tag::New({ External<TagLib::Tag>::New(env, ptr) });
}

Value FileRef::GetExtension(const CallbackInfo &info) {
  return String::New(info.Env(), ext);
}