##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=ecc
ConfigurationName      :=Release
WorkspacePath          :=/home/euripus/build/prj/Console
ProjectPath            :=/home/euripus/build/prj/Console/ecc
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=13.01.2019
CodeLitePath           :=/home/euripus/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="ecc.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_PanTompkins.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_analysis.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release


$(IntermediateDirectory)/.d:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_PanTompkins.cpp$(ObjectSuffix): src/PanTompkins.cpp $(IntermediateDirectory)/src_PanTompkins.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/euripus/build/prj/Console/ecc/src/PanTompkins.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanTompkins.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_PanTompkins.cpp$(DependSuffix): src/PanTompkins.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_PanTompkins.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_PanTompkins.cpp$(DependSuffix) -MM src/PanTompkins.cpp

$(IntermediateDirectory)/src_PanTompkins.cpp$(PreprocessSuffix): src/PanTompkins.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_PanTompkins.cpp$(PreprocessSuffix) src/PanTompkins.cpp

$(IntermediateDirectory)/src_analysis.cpp$(ObjectSuffix): src/analysis.cpp $(IntermediateDirectory)/src_analysis.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/euripus/build/prj/Console/ecc/src/analysis.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_analysis.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_analysis.cpp$(DependSuffix): src/analysis.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_analysis.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_analysis.cpp$(DependSuffix) -MM src/analysis.cpp

$(IntermediateDirectory)/src_analysis.cpp$(PreprocessSuffix): src/analysis.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_analysis.cpp$(PreprocessSuffix) src/analysis.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/euripus/build/prj/Console/ecc/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/


