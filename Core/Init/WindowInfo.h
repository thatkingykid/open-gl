#pragma once
#include <string>

namespace Core {
	struct WindowInfo {
		std::string name;
		int width, height;
		int positionX, positionY;
		bool reshapable;

		WindowInfo() {
			name = "OpenGL";
			width = 640;
			height = 480;
			positionX = 300;
			positionY = 300;
			reshapable = true;
		}

		WindowInfo(std::string inName, int inWidth, int inHeight, int inPosX, int inPosY, bool isReshapable) {
			this->name = inName;
			this->width = inWidth;
			this->height = inHeight;
			this->positionX = inPosX;
			this->positionY = inPosY;
			this->reshapable = isReshapable;
		}

		WindowInfo(const WindowInfo& windowInfo) {
			name = windowInfo.name;
			width = windowInfo.width;
			height = windowInfo.height;
			positionX = windowInfo.positionX;
			positionY = windowInfo.positionY;
			reshapable = windowInfo.reshapable;
		}

		void operator=(const WindowInfo& windowInfo) {
			name = windowInfo.name;
			width = windowInfo.width;
			height = windowInfo.height;
			positionX = windowInfo.positionX;
			positionY = windowInfo.positionY;
			reshapable = windowInfo.reshapable;
		}
	};
}