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
    }
    
	links 
    { 
		"opengl32",
        "glfw",
    }

	targetdir (outputdir .. "%{cfg.buildcfg}/%{prj.name}")
	objdir (objoutdir .. "%{cfg.buildcfg}/%{prj.name}")
    characterset ("MBCS")
	debugdir (outputdir .. "%{cfg.buildcfg}/%{prj.name}")

	buildoptions { "/bigobj" }

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