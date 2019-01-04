#pragma once
#include "ShaderManager.h"
#include "../Core/Init/IListener.h"

namespace Managers {
	class SceneManager : public Core::Init::IListener {
	public:
		SceneManager();
		~SceneManager();

		virtual void NotifyBeginFrame();
		virtual void NotifyDisplayFrame();
		virtual void NotifyEndFrame();
		virtual void NotifyReshape(int width, int height, int previousWidth, int previousHeight);

	private:
		Managers::ShaderManager* shaderManager;
	};
}