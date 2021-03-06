#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/include/Model.o \
	${OBJECTDIR}/src/cpp/Main.o \
	${OBJECTDIR}/src/cpp/View.o \
	${OBJECTDIR}/src/cpp/Statistics.o \
	${OBJECTDIR}/src/cpp/GameOfLife.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game_of_life_falha1.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game_of_life_falha1.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game_of_life_falha1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/include/Model.o: src/include/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/include
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/include/Model.o src/include/Model.cpp

${OBJECTDIR}/src/cpp/Main.o: src/cpp/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cpp
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cpp/Main.o src/cpp/Main.cpp

${OBJECTDIR}/src/cpp/View.o: src/cpp/View.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cpp
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cpp/View.o src/cpp/View.cpp

${OBJECTDIR}/src/cpp/Statistics.o: src/cpp/Statistics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cpp
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cpp/Statistics.o src/cpp/Statistics.cpp

${OBJECTDIR}/src/cpp/GameOfLife.o: src/cpp/GameOfLife.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cpp
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cpp/GameOfLife.o src/cpp/GameOfLife.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game_of_life_falha1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
