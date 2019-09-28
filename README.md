# taglib-node-binding
WIP Node.js binding of TagLib, currently supporting Windows and Linux

## Installation
CMake and appropriate build tools are required. (If you're on Windows, simply run `npm install -g windows-build-tools`)
```
npm install taglib-node-binding
```

## Example
TypeScript example (bindings provided)
```typescript
import { FileRef, Tag } from "taglib-node-binding";

const fileRef = new FileRef("MyMusic.mp3");
console.log(fileRef.tag.title); // Title property of the file
fileRef.tag.title = "My Music";
console.log(fileRef.tag.title); // "My Music"
fileRef.save();  // Change saved
```

## Future Plans
- [ ] Implement `Promise`-based API
- [ ] Implement tag-specific(album arts, etc...) features

Request features on the Issues section!

## Reference
### FileRef
#### `constructor(path: string)`
Creates a new `FileRef` instance and opens a file from `path`.
#### `get tag(): Tag`
Returns the `Tag` instance of the file.
#### `get properties(): Properties`
Returns the `Properties` instance of the file.
#### `get extension(): string`
Returns the extension of the file.
#### `save(): boolean`
Saves the file. Any changes made to the tag are saved through this function.

### Tag
#### `get title(): string`
Returns the `title` property of the `Tag`.
#### `set title(val: string)`
Updates the `title` property of the `Tag`.
#### `get artist(): string`
Returns the `artist` property of the `Tag`.
#### `set artist(val: string)`
Updates the `artist` property of the `Tag`.
#### `get album(): string`
Returns the `album` property of the `Tag`.
#### `set album(val: string)`
Updates the `album` property of the `Tag`.
#### `get comment(): string`
Returns the `comment` property of the `Tag`.
#### `set comment(val: string)`
Updates the `comment` property of the `Tag`.
#### `get genre(): string`
Returns the `genre` property of the `Tag`.
#### `set genre(val: string)`
Updates the `genre` property of the `Tag`.
#### `get year(): number`
Returns the `year` property of the `Tag`.
#### `set year(val: number)`
Updates the `year` property of the `Tag`.
#### `get track(): number`
Returns the `track` property of the `Tag`.
#### `set track(val: number)`
Updates the `track` property of the `Tag`.
#### `get type(): string`
Returns the type of the `Tag`.

### Properties
#### `get length(): number`
Returns the `length` property of the `Properties` in seconds.
#### `get bitrate(): number`
Returns the `bitrate` property of the `Properties`.
#### `get sampleRate(): number`
Returns the `sampleRate` property of the `Properties`.
#### `get channels(): number`
Returns the `channels` property of the `Properties`.