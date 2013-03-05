{
  "targets": [
    {
      "target_name": "zorba",
      "product_extension": "node",
      "sources": [ 
        "src/execute.cpp",
        "src/helpers.cpp",
        "src/main.cpp",
        "src/nodediagnostichandler.cpp"
      ],
      "include_dirs": [
        "include"
      ],
      "conditions": [
          ['OS=="win"', 
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
          ],
      ]
    }
    
  ]
}
