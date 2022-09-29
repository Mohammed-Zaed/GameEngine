workspace "Game_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "sandbox"

outputdir ="%{cfg.build}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
includedirpath              = {}
includedirpath["src"]       = "Engine/src"
includedirpath["spdlog"]    = "Engine/external/spdlog/include"
includedirpath["GLFW"]      = "Engine/external/glfw/include"
includedirpath["GLAD"]      = "Engine/external/glad/include"
includedirpath["IMGUI"]     = "Engine/external/imgui"
includedirpath["GLM"]       = "Engine/external/glm"

-- library directories relative to root folder (solution directory)
librarydirpath              = {}
librarydirpath["GLFW"]      = "%{prj.name}/external/glfw/lib-vc2019/"

include "Engine/external/glad"
include "Engine/external/imgui"

project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{includedirpath.src}",
        "%{includedirpath.spdlog}",
        "%{includedirpath.GLFW}",
        "%{includedirpath.GLAD}",
        "%{includedirpath.IMGUI}",
		"%{includedirpath.GLM}"
    }


    libdirs
    {
        "%{librarydirpath.GLFW}"
    }

    links
    {
        "glfw3dll",
        "opengl32",
        "Glad",
        "imGui"
    }

    pchheader "precompiled.h"
    pchsource "%{prj.name}/src/precompiled.cpp"

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "ENGINE_WINDOWS",
            "BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/sandbox/\""),
            ("{COPY} ../%{librarydirpath.GLFW}/ ../bin/%{outputdir}/sandbox")
        }

    filter "configurations:Debug"
        defines "ENGINE_DEBUG"
        symbols "on"
        runtime "Debug"

    filter "configurations:Release"
        defines "ENGINE_RELEASE"
        optimize "on"
        runtime "Release"

    filter "configurations:Dist"
        defines "ENGINE_DIST"
        optimize "on"
        runtime "Release"


project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Engine/src",
		"%{includedirpath.spdlog}",
		"%{includedirpath.GLM}"
    }



    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "ENGINE_WINDOWS"
        }

        links
        {
            "Engine"
        }

    filter "configurations:Debug"
        defines "ENGINE_DEBUG"
        symbols "on"
		runtime "Debug"

    filter "configurations:Release"
        defines "ENGINE_RELEASE"
        optimize "on"
        runtime "Release"

    filter "configurations:Dist"
        defines "ENGINE_DIST"
        optimize "on"
        runtime "Release"
