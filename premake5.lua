workspace "MilkyWay"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	startproject "MilkyWay"

	outputdir = "%{wks.location}/Build/Bin/"
	objoutdir = "%{wks.location}/Build/Bin-Int/"

	include "MilkyWay"
