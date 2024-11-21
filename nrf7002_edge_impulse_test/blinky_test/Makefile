build: 
	west build --build-dir /workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/blinky_test/build \
		/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/blinky_test \
		--board nrf7002dk_nrf7001_nrf5340_cpuapp_ns \
		-- -DNCS_TOOLCHAIN_VERSION=NONE -DCONF_FILE=/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/blinky_test/prj.conf\

clean:
	rm -rf ./build

.PHONY: build
