{
  'targets': [
    {
      'target_name': 'taglib-node-binding-native',
      'sources': [ 'src/taglib.cc', 'src/tag.cc', 'src/fileref.cc' ],
      'conditions': [
        ['OS=="linux"', {
          'libraries': [ '<(module_root_dir)/src/lib/libtag-linux.a' ],
        }]
      ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")", "<(module_root_dir)/src"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions', '-fno-rtti' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}