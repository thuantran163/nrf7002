build: 
	west build --build-dir /workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build \
		/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/ \
		--board nrf7002dk_nrf7001_nrf5340_cpuapp_ns \
		-- -DNCS_TOOLCHAIN_VERSION=NONE -DCONF_FILE=/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/prj.conf\
		-DEXTRA_CONF_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.conf -DDTC_OVERLAY_FILE=boards/nrf7002dk_nrf5340_cpuapp_ns.overlay


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
