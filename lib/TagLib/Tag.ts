interface TagNative {
  title: string;
  artist: string;
  album: string;
  comment: string;
  genre: string;
  year: number;
  track: number;

  readonly type: string;
}

export class Tag {
  constructor(native: TagNative) {
    this._instance = native;
  }

  get title(): string {
    return this._instance.title;
  }

  set title(val: string) {
    this._instance.title = val;
  }

  get artist(): string {
    return this._instance.artist;
  }

  set artist(val: string) {
    this._instance.artist = val;
  }

  get album(): string {
    return this._instance.album;
  }

  set album(val: string) {
    this._instance.album = val;
  }

  get comment(): string {
    return this._instance.comment;
  }

  set comment(val: string) {
    this._instance.comment = val;
  }

  get genre(): string {
    return this._instance.genre;
  }

  set genre(val: string) {
    this._instance.genre = val;
  }

  get year(): number {
    return this._instance.year;
  }

  set year(val: number) {
    this._instance.year = val;
  }

  get track(): number {
    return this._instance.track;
  }

  set track(val: number) {
    this._instance.track = val;
  }

  get type(): string {
    return this._instance.type;
  }

  private _instance: TagNative;
}
