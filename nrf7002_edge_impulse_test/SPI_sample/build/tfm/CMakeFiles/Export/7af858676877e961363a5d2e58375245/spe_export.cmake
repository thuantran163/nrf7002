# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "3.0.0")
   message(FATAL_ERROR "CMake >= 3.0.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 3.0.0...3.28)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS tfm_config psa_crypto_config psa_interface)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# The installation prefix configured by this project.
set(_IMPORT_PREFIX "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns")

# Create imported target tfm_config
add_library(tfm_config INTERFACE IMPORTED)

set_target_properties(tfm_config PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<\$<STREQUAL:,CRYPTO>:PSA_API_TEST_CRYPTO>;\$<\$<STREQUAL:,IPC>:PSA_API_TEST_IPC>;PROJECT_CONFIG_HEADER_FILE=\"/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/modules/nrf/modules/trusted-firmware-m/tfm_config.h\";\$<\$<OR:\$<BOOL:OFF>,\$<BOOL:0>>:CONFIG_TFM_CONNECTION_POOL_ENABLE>;TFM_PARTITION_LOG_LEVEL=TFM_PARTITION_LOG_LEVEL_SILENCE;\$<\$<BOOL:>:TFM_SP_LOG_RAW_ENABLED>;TFM_PARTITION_CRYPTO;TFM_PARTITION_PLATFORM;TFM_PARTITION_NS_AGENT_TZ;\$<\$<STREQUAL:,IPC>:PSA_API_TEST_IPC>;\$<\$<STREQUAL:PSA_ALG_GCM,PSA_ALG_GCM>:PS_CRYPTO_AEAD_ALG_GCM>;\$<\$<STREQUAL:PSA_ALG_GCM,PSA_ALG_CCM>:PS_CRYPTO_AEAD_ALG_CCM>;\$<\$<BOOL:ON>:PS_ENCRYPTION>;CRYPTO_HW_ACCELERATOR"
  INTERFACE_LINK_LIBRARIES "psa_crypto_config"
)

# Create imported target psa_crypto_config
add_library(psa_crypto_config INTERFACE IMPORTED)

# Create imported target psa_interface
add_library(psa_interface INTERFACE IMPORTED)

set_target_properties(psa_interface PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<\$<BOOL:>:CONFIG_TFM_ENABLE_CTX_MGMT>;\$<\$<BOOL:1>:TFM_ISOLATION_LEVEL=1>;\$<\$<BOOL:ON>:CONFIG_TFM_USE_TRUSTZONE>;\$<\$<BOOL:OFF>:TFM_MULTI_CORE_TOPOLOGY>;\$<\$<BOOL:OFF>:CONFIG_TFM_PARTITION_META>;\$<\$<BOOL:>:TFM_MULTI_CORE_TEST>"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/interface/include"
  INTERFACE_LINK_LIBRARIES "tfm_config"
)

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/spe_export-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  if(CMAKE_VERSION VERSION_LESS "3.28"
      OR NOT DEFINED _cmake_import_check_xcframework_for_${_cmake_target}
      OR NOT IS_DIRECTORY "${_cmake_import_check_xcframework_for_${_cmake_target}}")
    foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
      if(NOT EXISTS "${_cmake_file}")
        message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
      endif()
    endforeach()
  endif()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
