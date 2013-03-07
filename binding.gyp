{
  "targets": 
  [{
      "target_name": "zorba",
      "product_extension": "node",
      "sources": [ 
        "./src/Execute.cpp",
        "./src/helpers.cpp",
        "./src/main.cpp",
        "./src/NodeDiagnosticHandler.cpp"
      ],

      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      "include_dirs": [
        "./include"
      ],
      "conditions": [
          [
          'OS=="win"', 
            {
              "link_settings": {
                "libraries": [
                  "../win/lib/zorba_simplestore.lib"
                ]
              },
              "include_dirs": [
                "win/include"
              ]
            }
          ], [
          'OS=="mac"', 
            {
              'xcode_settings': 
              {
                'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
              }
	    }
          ]
      ]
  }]
}
