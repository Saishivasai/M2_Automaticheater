PROJ_NAME = Automatic_Heater

BUILD_DIR = Build

# All Source code files
SRC = main.c\
src/functions.c

# All header file paths
INC = -I inc

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
# Compile the code and generate the ELF file
	avr-gcc -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(BUILD_DIR)/$(PROJ_NAME).bin
	avr-objcopy -O ihex $(BUILD_DIR)/$(PROJ_NAME).bin $(BUILD_DIR)/$(PROJ_NAME).hex

$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all --check-config $^ $(INC)

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(BUILD_DIR)
	make -C documentation clean