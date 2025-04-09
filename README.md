# VyoriusDrones Task

## Requirements
`-` cmake (for building solution)

`-` MSVC compiler (MSBuild for solution -> executable)

`-` OpenGL (for graphics)

`-` SFML (used version = 2.6.1) (for window frame only)

`-` GLEW (used version = 2.1.0) (for OpenGL header)

`-` GLM (for mathematics)

`-` stb_image.h (for reading texture file)(already included in src/graphics)



## Installation
`1.` Clone the respository

`2.` Install the libraries (SFML, GLEW, GLM) in the lib directory

`3.` Configure the cmake for the project
```bash
mkdir build
cd build
cmake ..
cd ..
```

`4.` Build the project files
```bash
cmake --build build --target ALL_BUILD --config Debug
<path/to/compiler> <path/to/.sln>
```

`5.` Copy the .dlls(if necessary) to the executable directory

`6.` Execute the project