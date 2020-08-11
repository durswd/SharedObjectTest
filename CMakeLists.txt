
add_library(Base SHARED Base.cpp DynamicLinkLibrary.cpp)
add_library(Link1 SHARED Link1.cpp DynamicLinkLibrary.cpp)
add_library(Link2 SHARED Link2.cpp DynamicLinkLibrary.cpp)
add_executable(App App.cpp DynamicLinkLibrary.cpp)
