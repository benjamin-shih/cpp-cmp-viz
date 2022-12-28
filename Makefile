YELLOW:=$(shell tput setaf 3)
GREEN:=$(shell tput setaf 2)
RESET:=$(shell tput sgr0)
LOGFILE=$(LOGPATH)$(shell date +"%H:%M:%S")

cb:
	@echo "$(YELLOW)[INFO $(LOGFILE)] $(GREEN)Cleaning up build only..."
	@rm -rf build

clean:
	@echo "$(YELLOW)[INFO $(LOGFILE)] $(GREEN)Cleaning up..."
	@rm -rf Debug build compile_commands.json

debug:
	@echo "$(YELLOW)[INFO $(LOGFILE)] $(GREEN)Creating debug directory...$(RESET)"
	@cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
	@ln -s Debug/compile_commands.json .

build:
	@echo "$(YELLOW)[INFO $(LOGFILE)] $(GREEN)Creating build directory...$(RESET)"
	@mkdir build && cd build && cmake .. && make
