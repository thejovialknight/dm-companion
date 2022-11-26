#pragma once
#include <string.h>

#define WINDOW_COUNT 6
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

struct Window {
	short x;
	short y;
	short width;
	short height;
	std::string text;

	Window(short x, short y, short width, short height, std::string text) : width(width), height(height), text(text) {}
};

struct Screen {
	Window windows[WINDOW_COUNT];

	Window& input_bar();
	Window& info_bar();

	Screen() {
		const short screen_width = SCREEN_WIDTH;
		const short screen_height = SCREEN_HEIGHT;
		const short bar_height = 3;
		const short window_width = screen_width / 2;
		const short window_height = screen_height / 2;

		windows[0] = Window(0, screen_height - bar_height, screen_width, bar_height, "> Input bar here!");
		windows[1] = Window(0, 0, screen_width, bar_height, "Status bar up here!");
		windows[2] = Window(0, bar_height, window_width, window_height, "Top left window here!");
		windows[3] = Window(window_width, bar_height, window_width, window_height, "Top right window here!");
		windows[4] = Window(0, bar_height + window_height, window_width, window_height, "Bottom left window here!");
		windows[5] = Window(window_width, bar_height + window_height, window_width, window_height, "Bottom right window here!");
	}

	void draw();
};
