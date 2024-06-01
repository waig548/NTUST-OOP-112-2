// Will Replace by OJ, DO NOT EDIT!
#include <iostream>

#include "IXMLParser.h"
#include "TestUtils.hpp"
#include "XMLTokenizer.h"

const std::string Case5_XML() {
    std::string xml = R"IMAXMLNOTHTML(
<Project DefaultTargets="Build">
    <ItemGroup Label="ProjectConfigurations">
        <ProjectConfiguration Include="Debug|Win32">
            <Configuration>Debug</Configuration>
            <Platform>Win32</Platform>
        </ProjectConfiguration>
        <ProjectConfiguration Include="Release|Win32">
            <Configuration>Release</Configuration>
            <Platform>Win32</Platform>
        </ProjectConfiguration>
        <ProjectConfiguration Include="Debug|x64">
            <Configuration>Debug</Configuration>
            <Platform>x64</Platform>
        </ProjectConfiguration>
        <ProjectConfiguration Include="Release|x64">
            <Configuration>Release</Configuration>
            <Platform>x64</Platform>
        </ProjectConfiguration>
    </ItemGroup>
    <PropertyGroup Label="Globals">
        <VCProjectVersion>16.0</VCProjectVersion>
        <ProjectGuid>{0E4A5A78-7535-4D47-B01A-9800AAD9E0E6}</ProjectGuid>
        <RootNamespace>P1</RootNamespace>
        <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
    </PropertyGroup>
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props"></Import>
    <PropertyGroup Label="Configuration" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
        <ConfigurationType>Application</ConfigurationType>
        <UseDebugLibraries>true</UseDebugLibraries>
        <PlatformToolset>v142</PlatformToolset>
        <CharacterSet>Unicode</CharacterSet>
    </PropertyGroup>
    <PropertyGroup Label="Configuration" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
        <ConfigurationType>Application</ConfigurationType>
        <UseDebugLibraries>false</UseDebugLibraries>
        <PlatformToolset>v142</PlatformToolset>
        <WholeProgramOptimization>true</WholeProgramOptimization>
        <CharacterSet>Unicode</CharacterSet>
    </PropertyGroup>
    <PropertyGroup Label="Configuration" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
        <ConfigurationType>Application</ConfigurationType>
        <UseDebugLibraries>true</UseDebugLibraries>
        <PlatformToolset>v142</PlatformToolset>
        <CharacterSet>Unicode</CharacterSet>
    </PropertyGroup>
    <PropertyGroup Label="Configuration" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
        <ConfigurationType>Application</ConfigurationType>
        <UseDebugLibraries>false</UseDebugLibraries>
        <PlatformToolset>v142</PlatformToolset>
        <WholeProgramOptimization>true</WholeProgramOptimization>
        <CharacterSet>Unicode</CharacterSet>
    </PropertyGroup>
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props"></Import>
    <ImportGroup Label="ExtensionSettings"></ImportGroup>
    <ImportGroup Label="Shared"></ImportGroup>
    <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
        <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props"
            Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')"
            Label="LocalAppDataPlatform"></Import>
    </ImportGroup>
    <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
        <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props"
            Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')"
            Label="LocalAppDataPlatform"></Import>
    </ImportGroup>
    <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
        <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props"
            Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')"
            Label="LocalAppDataPlatform"></Import>
    </ImportGroup>
    <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
        <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props"
            Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')"
            Label="LocalAppDataPlatform"></Import>
    </ImportGroup>
    <PropertyGroup Label="UserMacros"></PropertyGroup>
    <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
        <LinkIncremental>true</LinkIncremental>
    </PropertyGroup>
    <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
        <LinkIncremental>true</LinkIncremental>
    </PropertyGroup>
    <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
        <LinkIncremental>false</LinkIncremental>
    </PropertyGroup>
    <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
        <LinkIncremental>false</LinkIncremental>
    </PropertyGroup>
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
        <ClCompile>
            <WarningLevel>Level3</WarningLevel>
            <SDLCheck>true</SDLCheck>
            <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
            <ConformanceMode>true</ConformanceMode>
        </ClCompile>
        <Link>
            <SubSystem>Console</SubSystem>
            <GenerateDebugInformation>true</GenerateDebugInformation>
        </Link>
    </ItemDefinitionGroup>
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
        <ClCompile>
            <WarningLevel>Level3</WarningLevel>
            <SDLCheck>true</SDLCheck>
            <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
            <ConformanceMode>true</ConformanceMode>
        </ClCompile>
        <Link>
            <SubSystem>Console</SubSystem>
            <GenerateDebugInformation>true</GenerateDebugInformation>
        </Link>
    </ItemDefinitionGroup>
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
        <ClCompile>
            <WarningLevel>Level3</WarningLevel>
            <FunctionLevelLinking>true</FunctionLevelLinking>
            <IntrinsicFunctions>true</IntrinsicFunctions>
            <SDLCheck>true</SDLCheck>
            <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
            <ConformanceMode>true</ConformanceMode>
        </ClCompile>
        <Link>
            <SubSystem>Console</SubSystem>
            <EnableCOMDATFolding>true</EnableCOMDATFolding>
            <OptimizeReferences>true</OptimizeReferences>
            <GenerateDebugInformation>true</GenerateDebugInformation>
        </Link>
    </ItemDefinitionGroup>
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
        <ClCompile>
            <WarningLevel>Level3</WarningLevel>
            <FunctionLevelLinking>true</FunctionLevelLinking>
            <IntrinsicFunctions>true</IntrinsicFunctions>
            <SDLCheck>true</SDLCheck>
            <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
            <ConformanceMode>true</ConformanceMode>
        </ClCompile>
        <Link>
            <SubSystem>Console</SubSystem>
            <EnableCOMDATFolding>true</EnableCOMDATFolding>
            <OptimizeReferences>true</OptimizeReferences>
            <GenerateDebugInformation>true</GenerateDebugInformation>
        </Link>
    </ItemDefinitionGroup>
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets"></Import>
    <ImportGroup Label="ExtensionTargets"></ImportGroup>
    <ItemGroup>
        <ClCompile Include="main.cpp"></ClCompile>
        <ClCompile Include="ParserFactory.cpp"></ClCompile>
    </ItemGroup>
    <ItemGroup>
        <None Include="ParserFactory.hpp"></None>
        <None Include="XMLTokenizer.hpp"></None>
        <None Include="IXMLParser.hpp"></None>
        <None Include="case1.hpp"></None>
        <None Include="case2.hpp"></None>
        <None Include="hbk.json"></None>
    </ItemGroup>
    <ItemGroup>
        <ClInclude Include="MyParser.hpp"></ClInclude>
    </ItemGroup>
</Project>
)IMAXMLNOTHTML";

    // std::cout << "===TOKENS===" << std::endl;
    // for (const auto& token: XMLTokenizer::Tokenize(xml)) {
    //     std::cout << token->ToString() << std::endl;
    //     delete token;
    // }
    // std::cout << "===TOKENS===" << std::endl;

    return xml;
}


// This test won't be shown to you, the original one is over 10,000 lines, I bet you don't want to see it.
// But, the original XML string placed at the end of this file.
// FYI, The original declaration is below:
// void __Case5__test_root_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_Filter_VCProjectVersion_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_Filter_ProjectGuid_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_Filter_RootNamespace_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL1RR_Elements_Filter_WindowsTargetPlatformVersion_At_0(IElement*);
// void __Case5__test_root_Elements_At_2(IElement*);
// void __Case5__test_root_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL3RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_Filter_WholeProgramOptimization_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL4RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL5RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_At_6(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_Filter_WholeProgramOptimization_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL6RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_At_7(IElement*);
// void __Case5__test_root_Elements_At_8(IElement*);
// void __Case5__test_root_Elements_At_9(IElement*);
// void __Case5__test_root_Elements_At_10(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL10RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL10RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_At_11(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL11RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL11RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_At_12(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL12RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL12RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_At_13(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL13RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL13RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_At_14(IElement*);
// void __Case5__test_root_Elements_At_15(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL15RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL15RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_At_16(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL16RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL16RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_At_17(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL17RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL17RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_At_18(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL18RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL18RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_At_19(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL19RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_At_20(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL20RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_At_21(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL21RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_At_22(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL22RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_At_23(IElement*);
// void __Case5__test_root_Elements_At_24(IElement*);
// void __Case5__test_root_Elements_At_25(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL25RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL25RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL25RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL25RR_Elements_Filter_ClCompile_At_1(IElement*);
// void __Case5__test_root_Elements_At_26(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL26RR_Elements_Filter_None_At_5(IElement*);
// void __Case5__test_root_Elements_At_27(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL27RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_AtLL27RR_Elements_Filter_ClInclude_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ItemGroup_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL2RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_AtLL3RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL0RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL1RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL2RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_Elements_Filter_ProjectConfiguration_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_Filter_Configuration_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQProjectConfigurationQQRR_AtLL3RR_Elements_Filter_Platform_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ItemGroup_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL1RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL1RR_Elements_Filter_ClCompile_At_1(IElement*);
// void __Case5__test_root_Elements_Filter_ItemGroup_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL2RR_Elements_Filter_None_At_5(IElement*);
// void __Case5__test_root_Elements_Filter_ItemGroup_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemGroupQQRR_AtLL3RR_Elements_Filter_ClInclude_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_Filter_VCProjectVersion_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_Filter_ProjectGuid_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_Filter_RootNamespace_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL0RR_Elements_Filter_WindowsTargetPlatformVersion_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL1RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_Filter_WholeProgramOptimization_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL2RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL3RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_Filter_ConfigurationType_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_Filter_UseDebugLibraries_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_Filter_PlatformToolset_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_Filter_WholeProgramOptimization_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL4RR_Elements_Filter_CharacterSet_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_5(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_6(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL6RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL6RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_7(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL7RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL7RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_8(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL8RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL8RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_PropertyGroup_At_9(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL9RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQPropertyGroupQQRR_AtLL9RR_Elements_Filter_LinkIncremental_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_Import_At_1(IElement*);
// void __Case5__test_root_Elements_Filter_Import_At_2(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_1(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL2RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL3RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL4RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL4RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL5RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQImportGroupQQRR_AtLL5RR_Elements_Filter_Import_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ImportGroup_At_6(IElement*);
// void __Case5__test_root_Elements_Filter_ItemDefinitionGroup_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL0RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ItemDefinitionGroup_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL1RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ItemDefinitionGroup_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL2RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_Elements_Filter_ItemDefinitionGroup_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_AtLL1RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_Elements_Filter_ClCompile_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_4(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_At_5(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_WarningLevel_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_FunctionLevelLinking_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_IntrinsicFunctions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_SDLCheck_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_PreprocessorDefinitions_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQClCompileQQRR_AtLL0RR_Elements_Filter_ConformanceMode_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_Elements_Filter_Link_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_1(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_2(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_At_3(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_SubSystem_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_EnableCOMDATFolding_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_OptimizeReferences_At_0(IElement*);
// void __Case5__test_root_ElementsLLRR_FilterLLQQItemDefinitionGroupQQRR_AtLL3RR_ElementsLLRR_FilterLLQQLinkQQRR_AtLL0RR_Elements_Filter_GenerateDebugInformation_At_0(IElement*);

void Case5() {
    auto      parser = CreateParser();
    IElement* root   = parser->Parse(Case5_XML());
    delete parser;
    delete root;
}