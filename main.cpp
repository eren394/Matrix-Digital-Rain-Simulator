#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <random>

void clearScreen() { std::cout << "\033[2J"; }
void cursorTo(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
void setColor(int colorCode) { std::cout << "\033[38;5;" << colorCode << "m"; }

std::random_device rd;
std::mt19937 gen(rd());

int getRandom(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

struct RainColumn {
    int x;
    float y;
    float speed;
    int length;

    RainColumn(int xPos, int screenHeight) {
        x = xPos;
        reset(screenHeight);
        y = getRandom(-screenHeight, 0);
    }

    void reset(int screenHeight) {
        y = 0;
        speed = getRandom(3, 7) * 0.15f;
        length = getRandom(10, 25);
    }

    void update(int screenHeight) {
        y += speed;
        if (y - length > screenHeight) {
            reset(screenHeight);
        }
    }

    void draw() {
        for (int i = 0; i < length; i++) {
            int currentY = (int)y - i;
            if (currentY > 0) {
                cursorTo(x, currentY);
                if (i == 0) setColor(15);
                else if (i < 3) setColor(46);
                else setColor(22);
                std::cout << (char)getRandom(33, 126);
            }
        }
    }
};

int main() {
    clearScreen();
    setColor(46);

    cursorTo(10, 5);
    std::cout << "Wake up, Neo..." << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cursorTo(10, 7);
    std::cout << "The Matrix has you..." << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cursorTo(10, 9);
    std::cout << "Follow the white rabbit." << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cursorTo(10, 12);
    std::cout << "[Sistem baglantisi bekleniyor...]" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(30));

    clearScreen();

    int width = 120; 
    int height = 40;

    std::vector<RainColumn> columns;
    for (int i = 1; i < width; i += 2) {
        columns.emplace_back(i, height);
    }

    while (true) {
        auto lastTime = std::chrono::steady_clock::now();

        while (true) {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastTime).count();

    if (elapsedTime > 2) {
        clearScreen();
        setColor(15); 
        cursorTo(10, 10);
        std::cout << "System wake-up detected. Reality re-syncing..." << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        clearScreen();
    }
    
    lastTime = currentTime;

    for (auto& col : columns) {
        col.update(height);
        col.draw();
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
}
        for (auto& col : columns) {
            col.update(height);
            col.draw();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }

    return 0;
}