cmake_minimum_required(VERSION 3.13)

include(FetchContent)

set(SIGNALSMITH_AUDIO_PLOT_TAG
    main
    CACHE STRING "Branch or tag for externals.SignalsmithAudio.plot")

FetchContent_Declare(
  externals.SignalsmithAudio.plot
  GIT_REPOSITORY https://github.com/Signalsmith-Audio/plot.git
  GIT_TAG ${SIGNALSMITH_AUDIO_PLOT_TAG})
FetchContent_MakeAvailable(externals.SignalsmithAudio.plot)

FetchContent_GetProperties(externals.SignalsmithAudio.plot
                           SOURCE_DIR SignalsmithAudio_plot_SOURCE_DIR)

message(STATUS "Signalsmith-Audio.plot source directory: "
               "${SignalsmithAudio_plot_SOURCE_DIR}")

set(PLOT_HEADERS ${SignalsmithAudio_plot_SOURCE_DIR}/plot.h
                 ${SignalsmithAudio_plot_SOURCE_DIR}/heatmap.h)

# Add the include directory manually
add_library(externals.SignalsmithAudio.plot INTERFACE ${PLOT_HEADERS})
target_include_directories(externals.SignalsmithAudio.plot
                           INTERFACE ${SignalsmithAudio_plot_SOURCE_DIR})
