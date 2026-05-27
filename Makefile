all: tapl bin tests

tapl:
	${MAKE} -C tapl

bin: tapl
	${MAKE} -C bin

tests: tapl
	${MAKE} -C tests

clean:
	${MAKE} -C tapl clean
	${MAKE} -C bin clean
	${MAKE} -C tests clean

.PHONY: all bin tests tapl clean