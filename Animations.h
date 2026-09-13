#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

// Small, dependency-free console "animation" helpers.
// Kept simple on purpose: typewriter text and a loading-dots effect.
class Animations {
public:
    static void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    // Prints text one character at a time, like an old terminal typing it out.
    static void typeEffect(const string& text, int delayMs = 10) {
        for (char c : text) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(delayMs));
        }
        cout << "\n";
    }

    // Prints a line, then a short pause (used to reveal ASCII art / banners
    // line-by-line instead of all at once).
    static void revealLine(const string& text, int delayMs = 60) {
        cout << text << "\n";
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }

    // "Loading..." / "Processing..." style animation: label + growing dots.
    static void loadingDots(const string& label, int dots = 3, int delayMs = 250) {
        cout << label << flush;
        for (int i = 0; i < dots; ++i) {
            this_thread::sleep_for(chrono::milliseconds(delayMs));
            cout << "." << flush;
        }
        cout << "\n";
    }

    // A tiny rotating spinner (|/-\\), useful for slightly longer waits.
    static void spinner(const string& label, int frames = 8, int delayMs = 120) {
        const char frame[] = { '|', '/', '-', '\\' };
        cout << label << " ";
        for (int i = 0; i < frames; ++i) {
            cout << frame[i % 4] << flush;
            this_thread::sleep_for(chrono::milliseconds(delayMs));
            cout << "\b" << flush;
        }
        cout << " done\n";
    }
};

#endif // ANIMATIONS_H
