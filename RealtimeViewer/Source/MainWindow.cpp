// \brief
//	MainWindow.cpp
//

#include "MainWindow.h"
#include "Editor.h"
#include "OSSystem.h"
#include "SOIL.h"


namespace XEditor
{
	FMainWindow::FMainWindow()
	{
		clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	}

	FMainWindow::~FMainWindow()
	{

	}

	// process sdl event
	void FMainWindow::ProcessEvent(const SDL_Event& InEvent)
	{
		if (!IsRelevantToEvent(InEvent))
		{
			return;
		}

		Super::ProcessEvent(InEvent);
	}

	// tick
	void FMainWindow::Tick(float InSeconds)
	{
		Super::Tick(InSeconds);

		int w, h;
		SDL_GL_GetDrawableSize(_SDLWindow, &w, &h);
		glViewport(0, 0, w, h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnable(GL_TEXTURE_2D);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		// render scene
		RenderScene(InSeconds);

		// render ui
		RenderUI(InSeconds);

		SDL_GL_SwapWindow(_SDLWindow);
	}

	void FMainWindow::OnPostInitialize() 
	{
		/* do something */ 
	}

	void FMainWindow::OnPrevUninitalize() 
	{ 
		/* do something */ 
	}

	void FMainWindow::OnWndClosed()
	{
		SDL_Event event;

		event.type = SDL_QUIT;
		SDL_PushEvent(&event);
	}

	void FMainWindow::RenderUI(float InDelta)
	{
		BeginUI(InDelta);


		EndUI();
	}

	void FMainWindow::ToolTip(const char* InText)
	{
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::TextUnformatted(InText);
			ImGui::EndTooltip();
		}
	}

	void FMainWindow::RenderScene(float InDelta)
	{

	}
}