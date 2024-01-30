project "MilkyWay"
	language "C++"
	cppdialect "C++20"
	files
	{
		"**.h",
        "**.cpp",
	}

	includedirs 
    { 
        "%{prj.location}", 
		"Vendor/glfw/include",
		"Vendor/glad/include",
		"Vendor/stb/include",
    }
    
	links 
    { 
		"opengl32",
        "glfw",
		"Glad",
    }

	targetdir (outputdir .. "%{cfg.buildcfg}/%{prj.name}")
	objdir (objoutdir .. "%{cfg.buildcfg}/%{prj.name}")
    characterset ("MBCS")
	debugdir (outputdir .. "%{cfg.buildcfg}/%{prj.name}")

	buildoptions { "/bigobj" }

	defines {"STB_IMAGE_IMPLEMENTATION"}

	filter { "configurations:Debug" }
		defines { "DEBUG" }
		symbols "On"
		kind "ConsoleApp"

	filter { "configurations:Release" }
		defines { "NDEBUG" }
		optimize "On"
		kind "WindowedApp"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"
		kind "ConsoleApp"