#include <SDL.h>
#include <iostream>
#include <random>
#include <ctime>
#include <filesystem> // For directory creation

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PIXEL_SIZE = 5; // Adjust pixel size

class RandomWalk {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int x, y;
    std::mt19937 rng;

    SDL_Color getRandomColor() {
        return SDL_Color{
            static_cast<Uint8>(rng() % 256),
            static_cast<Uint8>(rng() % 256),
            static_cast<Uint8>(rng() % 256),
            255
        };
    }

    void updatePosition() {
        x += (rng() % 5) - 2;
        y += (rng() % 5) - 2;
        x = std::max(0, std::min(x, WINDOW_WIDTH - 1));
        y = std::max(0, std::min(y, WINDOW_HEIGHT - 1));
    }

    void savePattern() {
        // Ensure the directory exists
        std::filesystem::create_directories("assets/generatedPatterns");

        // Create a surface to hold the renderer content
        SDL_Surface* saveSurface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
        if (!saveSurface) {
            std::cout << "Failed to create surface: " << SDL_GetError() << std::endl;
            return;
        }

        // Read pixels from the renderer into the surface
        SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, saveSurface->pixels, saveSurface->pitch);

        // Save the surface as a BMP file
        std::string filePath = "assets/generatedPatterns/pattern.bmp";
        if (SDL_SaveBMP(saveSurface, filePath.c_str()) != 0) {
            std::cout << "Failed to save BMP: " << SDL_GetError() << std::endl;
        } else {
            std::cout << "Pattern saved to " << filePath << std::endl;
        }

        SDL_FreeSurface(saveSurface);
    }

public:
    RandomWalk() : window(nullptr), renderer(nullptr) {
        rng.seed(std::random_device()());
    }

    bool init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
            return false;
        }

        window = SDL_CreateWindow("Random Walk",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN);

        if (!window) {
            std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (!renderer) {
            std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
            return false;
        }

        x = WINDOW_WIDTH / 2;
        y = WINDOW_HEIGHT / 2;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        return true;
    }

    void run() {
        bool quit = false;
        SDL_Event event;

        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }

            updatePosition();
            SDL_Color color = getRandomColor();
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = PIXEL_SIZE;
            rect.h = PIXEL_SIZE;
            SDL_RenderFillRect(renderer, &rect);

            SDL_RenderPresent(renderer);
            SDL_Delay(1);
        }

        savePattern();
    }

    ~RandomWalk() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

int main(int argc, char* argv[]) {
    RandomWalk app;
    if (!app.init()) return 1;
    app.run();
    return 0;
}
