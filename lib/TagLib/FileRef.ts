import bindings = require("bindings");
const tnb = bindings("taglib-node-binding-native");
import { Tag } from "./Tag";

interface FileRefNative {
  readonly tag: Tag;
  readonly extension: string;
  save(): boolean;
}

export class FileRef {
  constructor(path: string) {
    this._instance = new tnb.FileRef(path);
  }

  get tag(): Tag {
    return this._instance.tag;
  }

  get extension(): string {
    return this._instance.extension;
  }

  save(): boolean {
    return this._instance.save();
  }

  private _instance: FileRefNative;
}
