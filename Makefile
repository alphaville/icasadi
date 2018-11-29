default: build 

prepare:
	mkdir -p lib
	mkdir -p lib/build

build-clib: prepare
	# Compile phi.c and icasadi.c
	$(CC) -Wall -fPIC -c -o lib/build/auto_casadi_cost.o extern/auto_casadi_cost.c
	$(CC) -Wall -fPIC -c -o lib/build/auto_casadi_grad.o extern/auto_casadi_grad.c
	$(CC) -Wall -fPIC -c -o lib/build/icasadi.o extern/icasadi.c
	$(AR) rcs lib/libcsphi.a lib/build/auto_casadi_cost.o \
	lib/build/auto_casadi_grad.o lib/build/icasadi.o


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

doc:
	cargo doc --no-deps
	

.PHONY: prepare, build-clib, build, test, clean