add_rules("mode.debug", "mode.release")

target("ioc")
set_kind("binary")
add_files("src/*.cpp")
