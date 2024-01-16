workspace "MilkyWay"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	startproject "MilkyWay"

	outputdir = "%{wks.location}/Build/Bin/"
	objoutdir = "%{wks.location}/Build/Bin-Int/"

	group "Vendor"
		require("MilkyWay/Vendor/glfw/premake5")

	group ""

	include "MilkyWay"
