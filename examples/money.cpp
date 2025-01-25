#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Money.hpp"

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

Money shop_sum(Money total[5])
{
	Money sum(0);
	for (int i = 0; i < 5; ++i)
	{
		sum += total[i];
	}
	return sum;
}

int main(int, char**)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Money", nullptr, nullptr);
	if (window == nullptr)
	{
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); /* vsync */

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui::StyleColorsLight();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	Money budget(0);
	constexpr int BREAD = 1;
	constexpr int MILK = 2;
	constexpr int COLA = 0;
	constexpr int MOSKVICH = 3;
	constexpr int BRAIN = 4;
	int shopping_list[5] = {0};
	Money price_list[5] = {Money(39.90), Money(54.90), Money(99.90), Money(2220000.90), Money(1.00)};
	Money total[5] = {Money(0), Money(0), Money(0), Money(0), Money(0)};
	Money total_sum(0);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ImGui::Begin("Sberbank");

			if (ImGui::Button("Ask for 100 RUB"))
			{
				budget += 100;
			}
			ImGui::SameLine();
			ImGui::Text("Budget: %s RUB", budget.to_string().c_str());

			ImGui::End();
		}

		{
			ImGui::Begin("Pyaterochka");
			ImGui::Text("There are products for today:");

			{
				if (ImGui::InputInt("Coca-cola", &shopping_list[COLA], 1, 1))
				{
					if (shopping_list[COLA] >= 0)
					{
						total[COLA] = price_list[COLA] * shopping_list[COLA];
					}
					else
					{
						shopping_list[COLA] = 0;
					}
				}
				ImGui::SameLine();
				ImGui::Text("%s RUB", price_list[COLA].to_string().c_str());
			}

			{
				if (ImGui::InputInt("Milk", &shopping_list[MILK], 1, 1))
				{
					if (shopping_list[MILK] >= 0)
					{
						total[MILK] = price_list[MILK] * shopping_list[MILK];
					}
					else
					{
						shopping_list[MILK] = 0;
					}
				}
				ImGui::SameLine();
				ImGui::Text("%s RUB", price_list[MILK].to_string().c_str());
			}


			{
				if (ImGui::InputInt("Bread", &shopping_list[BREAD], 1, 1))
				{
					if (shopping_list[BREAD] >= 0)
					{
						total[BREAD] = price_list[BREAD] * shopping_list[BREAD];
					}
					else
					{
						shopping_list[BREAD] = 0;
					}
				}
				ImGui::SameLine();
				ImGui::Text("%s RUB", price_list[BREAD].to_string().c_str());
			}

			{
				if (ImGui::InputInt("Moskvich", &shopping_list[MOSKVICH], 1, 1))
				{
					if (shopping_list[MOSKVICH] >= 0)
					{
						total[MOSKVICH] = price_list[MOSKVICH] * shopping_list[MOSKVICH];
					}
					else
					{
						shopping_list[MOSKVICH] = 0;
					}
				}
				ImGui::SameLine();
				ImGui::Text("%s RUB", price_list[MOSKVICH].to_string().c_str());
			}

			{
				if (ImGui::InputInt("Brain", &shopping_list[BRAIN], 100, 100))
				{
					if (shopping_list[BRAIN] >= 0)
					{
						total[BRAIN] = price_list[BRAIN] * shopping_list[BRAIN];
					}
					else
					{
						shopping_list[BRAIN] = 0;
					}
				}
				ImGui::SameLine();
				ImGui::Text("%s RUB", price_list[BRAIN].to_string().c_str());
			}

			total_sum = shop_sum(total);
			ImGui::Text("Total: %s RUB", total_sum.to_string().c_str());

			if (budget >= total_sum)
			{
				if (ImGui::Button("Buy"))
				{
					budget -= total_sum;
					for (int i = 0; i < 5; ++i)
					{
						shopping_list[i] = 0;
						total[i] = 0;
					}
				}
			}
			else
			{
				ImGui::Text("Not enough money");
			}

			ImGui::End();
		}

		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
