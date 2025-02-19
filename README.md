# RandomWalk 🚶‍♂️

![Build Status](https://img.shields.io/badge/build-passing-brightgreen) ![License](https://img.shields.io/badge/license-MIT-blue)

#### 🎮 RandomWalk is a C++ program that generates a pattern by the random movement of a pixel using the SDL2 library. The program creates a window where a pixel moves randomly, leaving a colourful trail behind. The generated pattern can be saved as a BMP file. 🎨

#### 🎓 This project was created as a fun experiment after learning C++ in my 2nd semester of college. It served as a practical way to explore and test the SDL library, combining newly acquired programming knowledge with graphics programming concepts. 💡

<hr>

<br>

## Table of Contents 📑
- [Overview 🌟](#overview)
- [Features ✨](#features)
- [Screenshots 📸](#screenshots)
- [Video Demo 🎥](#video-demo)
- [Getting Started 🚀](#getting-started)
        - [Prerequisites 📋](#prerequisites)
        - [Installation 🛠️](#installation)
        - [Usage ▶️](#usage)
- [SDL2 Resources 📚](#sdl2-resources)
- [Contributing 🤝](#contributing)
- [License 📄](#license)
- [Acknowledgements 🙏](#acknowledgements)
- [Contact 📧](#contact)

## Overview 🌟

This project demonstrates the use of the SDL2 library for graphics programming in C++. It includes features such as:
- Random movement of a pixel within a window
- Colorful trails left by the moving pixel
- Saving the generated pattern as a BMP file

## Features ✨
- Random movement of a pixel
- Colorful trails
- Save the pattern as a BMP file

## Screenshots 📸
![Screenshot](path/to/screenshot.png)

## Video Demo 🎥
Watch the RandomWalk in action:

![RandomWalk Demo](/assets/randomWalk.mp4)


[![RandomWalk Demo Video](https://img.youtube.com/vi/6xoGNF_uH-w/0.jpg)](https://www.youtube.com/watch?v=6xoGNF_uH-w)

*Click the image above to watch the demo video on YouTube*

## Getting Started 🚀

### Prerequisites 📋

To build and run this project, you need to have the following installed on your system:
- C++ compiler (e.g., g++)
- SDL2 library

### Installation 🛠️

1. **Clone the repository**:

        ```sh
        git clone https://github.com/yourusername/RandomWalk.git
        cd RandomWalk
        ```
        
2. **Install SDL2**:
        - Download SDL2 from [libsdl.org](https://libsdl.org)
        - Extract the files and place them in the `include/SDL2` and `lib/SDL2` directories

3. **Compile the project**:
        ```sh
        g++ -o RandomWalk src/main.cpp -Iinclude/SDL2 -Llib/SDL2 -lmingw32 -lSDL2main -lSDL2
        ```

### Usage ▶️

Run the executable:
```sh
./RandomWalk.exe
```

The program will open a window where a pixel moves randomly, leaving a colourful trail. When you close the window, the generated pattern will be saved as `pattern.bmp` in the current directory.

## SDL2 Resources 📚
- Official SDL2 Website: [libsdl.org](https://www.libsdl.org/)
- SDL2 Documentation: [wiki.libsdl.org](https://wiki.libsdl.org/)
- SDL2 Download Page: [libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)
- SDL2 Tutorials: [lazyfoo.net/tutorials/SDL](https://lazyfoo.net/tutorials/SDL/)

## Contributing 🤝
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

![Alt](https://repobeats.axiom.co/api/embed/a005a65113d6ead7fa1c05ff7019eda75dbfd827.svg "Repobeats analytics image")


## License 📄
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements 🙏
SDL2 - Simple DirectMedia Layer library

