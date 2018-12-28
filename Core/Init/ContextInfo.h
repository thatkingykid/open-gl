namespace Core {
	struct ContextInfo {
		int majorVersion, minorVersion;
		bool core;

		ContextInfo() {
			majorVersion = 4;
			minorVersion = 0;
			core = true;
		}

		ContextInfo(int inMajor, int inMinor, bool isCore) {
			this->majorVersion = inMajor;
			this->minorVersion = inMinor;
			this->core = isCore;
		}
	};
}