#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

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

	/*
		Brief	: maintains vertex data for a set of entities
		Details	: The goal of VertexData is to make it possible for
	*/
	class VertexData {
	private:
		/*
			Brief : Index data to be sent to GPU
		*/
		std::vector<unsigned int> indices;
		/*
			Brief : Vertex Data to be sent to GPU
		*/
		std::vector<float> data;



		/*
			Brief : vector of start positions for inactive vertices
		*/
		std::vector<int> open;
		/*
			Brief : Given key[a] = b,
					   - a : name of an Entity
					   - b : vector of start positions for vertices in data
					A start position is given as (key[name][i] * span)
		*/
		std::unordered_map<std::string, std::vector<int>> key;
		/*
			Brief : vector of cross reference values that point at the pointers
					in each entity. For when data vector is remade & the addresses change
		*/
		std::vector<std::pair<int, float**>> crossReference;


		/*
			Brief : (# of active vertices) + (# of inactive vertices)
		*/
		int capacity;
		/*
			Brief : # of active vertices
		*/
		int size;



		/*
			Brief : # of elements in each vertex
		*/
		int span;



		/*
			errorMsg	: String -> String

			Brief		: returns a given message as an error message
			Params		: (String msg) message used in error message
		*/
		std::string errorMsg(std::string msg);
		/*
			printErrorMsg	: String -> ()

			Brief			: prints given message as error message
			Params			: (String msg) message printed in error message
		*/
		void printErrorMsg(std::string msg);

	public:
		/*
			VertexData	: Int -> ()

			Brief		: constructor for VertexData class.
			Params		: (Int span) sets the span.
		*/
		VertexData(int span);



		/*
			addData	: String vector<vector<Float*>>& -> ()

			Brief	: add & bind a set of data
			Params	: (String name) name of entity who's data is being added
					  (vector<vector<float*>>& d) set of data to bind
					     - outer vector : vector of vertices
						 - inner vector : vector of vertex data (of size span)
		*/
		void addData(std::string name, std::vector<std::vector<float*>>& d);
		/*
			bindVertex	: String vector<Float*>& -> Int

			Brief		: add & bind data for a single vertex
						  and return the index where we binded
			Params		: (String name) name of entity who's binding vertex data
						  (vector<float*>&) vector of vertex data (of size span)
		*/
		int bindVertex(std::string name, std::vector<float*>& v);
		/*
			removeData	: String -> ()

			Brief		: removes an entities data
			Params		: (String name) name of  entity who's data to remove
		*/
		void removeData(std::string name);
		/*
			getData	: () -> pair<const void*, const unsigned int*>

			Brief	: returns the index and vertex data
					  Given getData().first  = a,
							getData().second = b
						- a : vertex data
						- b : index data
		*/
		std::pair<const void*, const unsigned int*> getData();
		/*
			cleanUp : () -> ()
			
			Brief	: re-arrange data to remove all inactive vertices
		*/
		void cleanUp();
	};
}