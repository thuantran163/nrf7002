NUMBER_FILE := count.txt
NUMBER := $(shell cat $(NUMBER_FILE))
NEW_NUMBER := $(shell echo $$(($(NUMBER)+1)))
build: 
	west build --build-dir /workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build \
		/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/ \
		--board nrf7002dk/nrf5340/cpuapp/ns \
		-- -DNCS_TOOLCHAIN_VERSION=NONE -DCONF_FILE=/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/prj.conf\
		-DEXTRA_CONF_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.conf -DDTC_OVERLAY_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.overlay
#	git add .
#	git commit -m "build $(NUMBER)"
#	git push
#	echo $(NEW_NUMBER) > $(NUMBER_FILE)


build-pristine: 
	west build --build-dir /workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build \
		/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/ \
		--pristine \
		--board nrf7002dk_nrf7001_nrf5340_cpuapp_ns \
		-- -DNCS_TOOLCHAIN_VERSION=NONE -DCONF_FILE=/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/prj.conf\
		-DEXTRA_CONF_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.conf -DDTC_OVERLAY_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.overlay


clean:
	rm -rf ./build

.PHONY: build
