default: build 

prepare:
	mkdir -p lib
	mkdir -p lib/build

build-clib: prepare
	# Compile phi.c and icasadi.c
	$(CC) -fPIC -c -o lib/build/csphi.o extern/autogen-casadi-function.c
	gcc -Wall -fPIC -c -o lib/build/icasadi.o extern/icasadi.c
	$(AR) rcs lib/libcsphi.a lib/build/csphi.o lib/build/icasadi.o


build: build-clib
	RUSTFLAGS='-L ./lib/' cargo build

test: build
	RUSTFLAGS='-L ./lib/' cargo test

run:
	RUSTFLAGS='-L ./lib/' cargo run

clean:
	cargo clean
	rm -rf lib/build/*.o	
	rm -rf lib/*.a	



.PHONY: prepare, build-clib, build, test, clean