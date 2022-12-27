cb:
	@rm -rf build

clean:
	@echo "Cleaning up..."
	@rm -rf Debug build compile_commands.json

debug:
	@cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
	@ln -s Debug/compile_commands.json .

build:
	@mkdir build && cd build && cmake .. && make
