#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "InitGlew.h"

namespace Core {
	namespace Init {
		class InitGlut {
		public:
			static void Init(const Core::WindowInfo& window, const Core::ContextInfo& context, const Core::FrameBufferInfo& frameBuffer);
			static void Run();
			static void Close();
			void EnterFullscreen();
			void ExitFullscreen();
			static void PrintGLInfo(const Core::WindowInfo& window, const Core::ContextInfo& context);

		private:
			static void IdleCallback(void);
			static void DisplayCallback(void);
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
		};
	}
}