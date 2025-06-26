    workspace "GameEngine"
	architecture "x64"
    startproject "Sandbox" 

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
	location "GameEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",	
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"

		postbuildcommands
        {
            "{COPY} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Sandbox\""
        }


	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GameEngine/vendor/spdlog/include",
		"GameEngine/src"
	}

	links
	{
		"GameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"

		

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"