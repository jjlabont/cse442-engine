#pragma once

namespace goat {

	struct vec2 {
		float x;
		float y;

		vec2() : x(0.0f), y(0.0f) {}
		vec2(float x, float y) : x(x), y(y) {}
		vec2(const vec2& v2) {
			x = v2.x;
			y = v2.y;
		}
	};

	struct vec3 {
		float x;
		float y;
		float z;

		vec3() : x(0.0f), y(0.0f), z(0.0f) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		vec3(const vec3& v3) {
			x = v3.x;
			y = v3.y;
			z = v3.z;
		}
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
		Rect(const Rect& r) {
			x = r.x;
			y = r.y;
			w = r.w;
			h = r.h;
		}
	};

	struct Color {
		float r;
		float g;
		float b;
		float a;

		Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
		Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
		Color(const Color& c) {
			r = c.r;
			g = c.g;
			b = c.b;
			a = c.a;
		}
	};
}