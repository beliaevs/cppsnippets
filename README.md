# Howto build these projects with CMake?

For example you want to build project operators.
Firstly you should create directory for build output, i.e. operators_build somewhere out of cppsnippets folder.
cd to operators_build
## Linux build
* cmake -S ~/GitHub/cppsnippets/operators -B release -DCMAKE_BUILD_TYPE=RELEASE 
* cmake -S ~/GitHub/cppsnippets/operators -B debug -DCMAKE_BUILD_TYPE=DEBUG (if you want to) 
* cmake --build release

## Windows VS build
* cmake -S GitHub\cppshippets\operators -B .
* cmake --build . --config Release
* cmake --build . --config Debug


