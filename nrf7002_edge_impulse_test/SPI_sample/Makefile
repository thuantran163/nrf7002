SHELL := /bin/bash
#
#.SUFFIXES:
#.DELETE_ON_ERROR:
#
#PWD := $(shell pwd)
#TOP := .
#TOPDIR :=
#BUILD_SYSTEM := $(TOPDIR)build/core
#
#
## This is the default target.  It must be the first declared target.
#.PHONY: west
.DEFAULT_GOAL := build
#$(DEFAULT_GOAL):
#
#.PHONY: FORCE
#FORCE:
TARGET := EdgeImpulse_example
DIR := $(shell pwd)
BUILD_DIR := $(DIR)/build
BOARD_DIR := $(DIR)/boards
#BOARD := nrf7002dk/nrf5340/cpuapp/ns
BOARD :=   nrf54h20dk/nrf54h20/cpuapp 
#DEBUG:= 
#OPT:=
PRJ_SOURCES := $(DIR)/prj.conf
#OVERLAY_SOURCES := $(BOARD_DIR)/nrf7002dk_nrf5340_cpuapp_ns.overlay
OVERLAY_SOURCES := $(BOARD_DIR)/nrf54h20dk_nrf54h20_cpuapp_fast.overlay
SUIT_EVELOPE_NORDIC_DIRECTORY := $(DIR)/nordic_top.suit
#CONFIG_SOURCES := $(BOARD_DIR)/nrf7002dk_nrf5340_cpuapp_ns.conf 
all: pristine

.PHONY: build
build: 
	west build $(if $(filter 1,$(PRISTINE)), --pristine) \
		--build-dir $(BUILD_DIR) $(DIR) \
		--board $(BOARD)  \
		-- -DNCS_TOOLCHAIN_VERSION=NONE \
		   -DBS_CONFIG_SUIT_EVELOPE_NORDIC_TOP_DIRECTORY=$(SUIT_EVELOPE_NORDIC_DIRECTORY) \
			 -DCONF_FILE= $(CONFIG_SOURCES) \
		   -DEXTRA_CONF_FILE=$(CONFIG_SOURCES) -DDTC_OVERLAY_FILE=$(OVERLAY_SOURCES) 

.PHONY: pristine
pristine: 
	$(MAKE) PRISTINE=1 build

.PHONY: flash
flash:
		west flash --skip-rebuild --no-erase


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)


