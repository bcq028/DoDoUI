#pragma once

#include "ApplicationCore/GenericPlatform/GenericApplication.h"

#include "ApplicationCore/GenericPlatform/GenericPlatformApplicationMisc.h"

namespace DoDo {
	struct FWindowsPlatformApplicationMisc : public FGenericPlatformApplicationMisc
	{
		static void platform_pre_init();
		/*get glfw content scale*/
		static float get_dpi_scale_factor_at_point(float x, float y);

		static std::shared_ptr<GenericApplication> create_application();
	};

#ifdef WIN32
	typedef FWindowsPlatformApplicationMisc FPlatformApplicationMisc;
#endif
}