interface PropertiesNative {
  readonly length: number;
  readonly bitrate: number;
  readonly sampleRate: number;
  readonly channels: number;
}

export class Properties {
  private constructor(instance: PropertiesNative) {
    this._instance = instance;
  }

  get length(): number {
    return this._instance.length;
  }

  get bitrate(): number {
    return this._instance.bitrate;
  }

  get sampleRate(): number {
    return this._instance.sampleRate;
  }

  get channels(): number {
    return this._instance.channels;
  }

  private _instance: PropertiesNative;
}
