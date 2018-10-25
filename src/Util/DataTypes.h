#pragma once

namespace goat {

	struct vec2 {
		float x;
		float y;

		vec2() : x(0.0f), y(0.0f) {}
		vec2(float x, float y) : x(x), y(y) {}
	};

	struct Shape {

	};

	struct Rect : public Shape {
		float x;
		float y;
		float w;
		float h;

		Rect() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) {};
		Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
	};

	struct Color {
		float r;
		float g;
		float b;
		float a;

		Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
		Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
	};
}