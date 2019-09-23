const { FileRef, Tag } = require("../dist/binding.js");
const assert = require("assert");
const path = require("path");

assert(FileRef, "The expected module is undefined");
assert(Tag, "The expected module is undefined");

function getExpected(extension, data) {
  return `TNB ${extension} ${data}`;
}

// All test files are encoded by FFmpeg and tagged by Mp3tag.
function testRead() {
  console.log("Testing AAC.m4a");
  let f = new FileRef(path.join(__dirname, "audio", "AAC.m4a"));
  assert.strictEqual(f.extension, "M4A", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");

  console.log("Testing FLAC.flac");
  f = new FileRef(path.join(__dirname, "audio", "FLAC.flac"));
  assert.strictEqual(f.extension, "FLAC", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");
  
  console.log("Testing MP3_ID3v1.mp3");
  f = new FileRef(path.join(__dirname, "audio", "MP3_ID3v1.mp3"));
  assert.strictEqual(f.extension, "MP3", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, "", "Unexpected value returned"); //ID3v1 doesn't have it
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");
  assert.strictEqual(f.tag.type, "ID3v1", "unexpected value returned");

  console.log("Testing MP3_ID3v2.3.mp3");
  f = new FileRef(path.join(__dirname, "audio", "MP3_ID3v2.3.mp3"));
  assert.strictEqual(f.extension, "MP3", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");
  assert.strictEqual(f.tag.type, "ID3v2", "unexpected value returned");

  console.log("Testing MP3_ID3v2.4.mp3");
  f = new FileRef(path.join(__dirname, "audio", "MP3_ID3v2.4.mp3"));
  assert.strictEqual(f.extension, "MP3", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");
  assert.strictEqual(f.tag.type, "ID3v2", "unexpected value returned");

  console.log("Testing OGG.ogg");
  f = new FileRef(path.join(__dirname, "audio", "OGG.ogg"));
  assert.strictEqual(f.extension, "OGG", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");

  console.log("Testing OPUS.opus");
  f = new FileRef(path.join(__dirname, "audio", "OPUS.opus"));
  assert.strictEqual(f.extension, "OPUS", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");

  console.log("Testing WAV_ID3v2.4.wav");
  f = new FileRef(path.join(__dirname, "audio", "WAV_ID3v2.4.wav"));
  assert.strictEqual(f.extension, "WAV", "Unexpected value returned");
  assert.strictEqual(f.tag.title, getExpected(f.extension, "title"), "Unexpected value returned");
  assert.strictEqual(f.tag.album, getExpected(f.extension, "album"), "Unexpected value returned");
  assert.strictEqual(f.tag.artist, getExpected(f.extension, "artist"), "Unexpected value returned");
  assert.strictEqual(f.tag.comment, getExpected(f.extension, "comment"), "Unexpected value returned");
  assert.strictEqual(f.tag.genre, getExpected(f.extension, "genre"), "Unexpected value returned");
  assert.strictEqual(f.tag.year, 2000, "Unexpected value returned");
  assert.strictEqual(f.tag.track, 1, "Unexpected value returned");
  assert.strictEqual(f.tag.type, "ID3v2", "Unexpected value returned");

  console.log("Testing ID3v2.4_Unicode.mp3");
  f = new FileRef(path.join(__dirname, "audio", "ID3v2.4_Unicode.mp3"));
  assert.strictEqual(f.tag.title, "유니코드 제목(Unicode Title)", "Unexpected value returned");
  assert.strictEqual(f.tag.album, "유니코드 앨범(Unicode Album)", "Unexpected value returned");
  assert.strictEqual(f.tag.artist, "유니코드 아티스트(Unicode Artist)", "Unexpected value returned");
  assert.strictEqual(f.tag.comment, "유니코드 설명(Unicode Comment)", "Unexpected value returned");
  assert.strictEqual(f.tag.genre, "유니코드 장르(Unicode Genre)", "Unexpected value returned");
}

testRead();

console.log("All tests passed.");