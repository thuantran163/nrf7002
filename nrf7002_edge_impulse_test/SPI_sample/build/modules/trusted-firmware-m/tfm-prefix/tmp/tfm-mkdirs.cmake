# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/root/ncs/modules/tee/tf-m/trusted-firmware-m")
  file(MAKE_DIRECTORY "/root/ncs/modules/tee/tf-m/trusted-firmware-m")
endif()
file(MAKE_DIRECTORY
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm"
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix"
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/tmp"
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp"
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/src"
  "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp${cfgdir}") # cfgdir has leading slash
endif()
