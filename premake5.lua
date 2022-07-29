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
includedirpath["src"]       = "%{prj.name}/src"
includedirpath["spdlog"]    = "%{prj.name}/external/spdlog/include"
includedirpath["GLFW"]      = "%{prj.name}/external/glfw/include"

-- library directories relative to root folder (solution directory)
librarydirpath              = {}
librarydirpath["GLFW"]      = "%{prj.name}/external/glfw/lib-vc2019/"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{includedirpath.src}",
        "%{includedirpath.spdlog}",
        "%{includedirpath.GLFW}"
    }


    libdirs
    {
        "%{librarydirpath.GLFW}"
    }

    links
    {
        "glfw3dll",
        "opengl32"
    }

    pchheader "precompiled.h"
    pchsource "%{prj.name}/src/precompiled.cpp"

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "ENGINE_WINDOWS",
            "BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox"),
            ("{COPY} ../%{librarydirpath.GLFW}/ ../bin/%{outputdir}/sandbox")
        }

    filter "configurations:Debug"
        defines "ENGINE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ENGINE_DIST"
        optimize "On"


project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Engine/external/spdlog/include",
        "Engine/src"
    }



    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
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
        symbols "On"

    filter "configurations:Release"
        defines "ENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ENGINE_DIST"
        optimize "On"

