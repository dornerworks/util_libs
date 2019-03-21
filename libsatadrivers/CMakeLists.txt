#
# Copyright 2019, DornerWorks
# Copyright 2018, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_DORNERWORKS_BSD)
#

cmake_minimum_required(VERSION 3.7.2)

project(libsatadrivers C)

set(configure_string "")

config_option(LibSatadrivers LIB_SATA
    "Support library for x86 SATA"
    DEFAULT OFF
)

config_option(LibSatadriversAHCIEnable AHCI_ENABLE
    "Enables AHCI mode, if disabled IDE mode will be used"
    DEFAULT ON
    DEPENDS "LibSatadrivers"
)

add_config_library(satadrivers "${configure_string}")


if(LibSatadriversAHCIEnable)
    file(GLOB sources src/ahci.c src/common.c)
else()
    file(GLOB sources src/ide.c src/common.c)
endif()

add_library(satadrivers STATIC EXCLUDE_FROM_ALL ${sources})
target_include_directories(satadrivers PUBLIC include)
target_link_libraries(satadrivers Configuration muslc platsupport utils sel4)
