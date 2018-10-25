#pragma once
#include <functional>
#include <vector>
#include <iostream>

#include "imgui/imgui.h"

namespace test {
	class Test {
	public:
		Test() {}
		virtual ~Test() {}

		virtual void onUpdate(float deltaTime) {}
		virtual void onRender() {}
		virtual void onImGuiRender() {}
	};

	class TestMenu : public Test{
	public:
		TestMenu(Test*& CurrentTestPointer);

		void onImGuiRender() override;

		template<typename T>
		void registerTest(const std::string name) {
			std::cout << "Registering test: " << name.c_str() << std::endl;
			m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
		}
	private:
		Test*& m_CurrentTest;
		std::vector<std::pair<std::string, std::function<Test*()>>>m_Tests;
	};
}