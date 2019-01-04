#pragma once
namespace Core {
	namespace Init {
		class IListener {
		public:
			virtual ~IListener() = 0;
			virtual void NotifyBeginFrame() = 0;
			virtual void NotifyDisplayFrame() = 0;
			virtual void NotifyEndFrame() = 0;
			virtual void NotifyReshape(int width, int height, int previousWidth, int previousHeight) = 0;
		};
		inline IListener::~IListener() {}
	}
}