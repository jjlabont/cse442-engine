#include "DataTypes.h"

namespace goat {
	
	VertexData::VertexData(int span) : capacity(0), size(0), span(span) { }
	

	std::string VertexData::errorMsg(std::string msg) {
		return "VERTEX_DATA_ERROR: " + msg + "\n";
	}
	void VertexData::printErrorMsg(std::string msg) {
		errorMsg(msg);
	}

	//TODO:
	void VertexData::addData(std::string name, std::vector<std::vector<float*>>& d) {
		for (int i = 0; i < d.size(); i++) {
			bindVertex(name, d[i]);
		}
	}

	int VertexData::bindVertex(std::string name, std::vector<float*>& v) {
		int index = 0;

		//fill open position if one exists
		if (open.size() > 0) {
			index = open.back();
			open.pop_back();

			//replace data in open slot
			for (int i = 0; i < v.size(); i++) {
				v[i] = &data[(span * index) + i];
			}
		}
		//otherwise place at end of data
		else {
			index = data.size() / span;
			//create new slot
			for (int i = 0; i < v.size(); i++) {
				data.push_back(0.0f);
			}
			capacity++;
		}
		size++;

		return index;
	}

	//TODO:
	void VertexData::removeData(std::string name) {

	}

	std::pair<const void*, const unsigned int*> VertexData::getData() {
		return std::pair<const void*, const unsigned int*>(&data[0], &indices[0]);
	}

	//TODO:
	void VertexData::cleanUp() {

	}

	/*void VertexData::addData(std::string name, std::vector<std::vector<float>> d) {
		int l = data.size() / span;
		if (open.size() > 0) {
			for (int i = 0; i < d.size(); i++) {
				if (d[i].size() != span) {
					printErrorMsg("span of " + std::to_string(span) + " does not equal given vector size, " + std::to_string(d.size()));
				}

				l = open.back();
				open.pop_back();

				for (int j = 0; j < d[i].size(); j++) {

				}
			}
		}
		else {
			for (int i = 0; i < d.size(); i++) {
				if (d.size() != span) {
					printErrorMsg("span of " + std::to_string(span) + " does not equal given vector size, " + std::to_string(d.size()));
				}
			}
		}*/
		/*
		//location to fill
		int l = data.size() / span;
		if (open.size() > 0) {
			l = open.back();
			open.pop_back();

			//replace data in open slot
			for (int i = 0; i < d.size(); i++) {
				data[(span * l) + i] = d[i];
			}
		}
		else {
			//create new slot
			for (int i = 0; i < d.size(); i++) {
				data.push_back(d[i]);
			}
			capacity++;
		}
		key[name] = l;
		size++;
		*/
/*	}

	void VertexData::removeData(std::string name) {
		int begin = key[name] * span;

		for (int i = 0; i < span; i++) {
			data[begin + i] = 0.0f;
		}

		open.push_back(key[name]);
		key.erase(name);
		size--;
		//remove garbage data less than half slots are used
		if (size * 2 < capacity) {
			cleanUp();
		}
	}

	std::pair<const void*, const unsigned int*> VertexData::getData() {
		//if there is no data (nothing to draw)
		if (size == 0) {
			return std::pair<const void*, const unsigned int*>(nullptr, nullptr);
		}
		return std::pair<const void*, const unsigned int*>(&data[0], &indices[0]);
	}

	void VertexData::cleanUp() {

	}


	std::string VertexData::errorMsg(std::string msg) {
		return "VERTEX_DATA_ERROR: " + msg + "\n";
	}
	void VertexData::printErrorMsg(std::string msg) {
		errorMsg(msg);
	}
	*/
}